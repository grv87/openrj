/* /////////////////////////////////////////////////////////////////////////////
 * File:    orjapi.c
 *
 * Purpose: Implementation file for the Open-RJ library
 *
 * Created: 11th June 2004
 * Updated: 6th June 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/** \file orjapi.c Implementation file for the Open-RJ library
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_C_ORJAPI_MAJOR      1
# define OPENRJ_VER_C_ORJAPI_MINOR      5
# define OPENRJ_VER_C_ORJAPI_REVISION   4
# define OPENRJ_VER_C_ORJAPI_EDIT       33
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warning handling
 */

#if defined(_MSC_VER) && \
    !defined(__INTEL_COMPILER) && \
    !defined(__DMC__)
# if _MSC_VER < 1300
#  pragma warning(disable : 4127)
# endif /* _MSC_VER < 1300 */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>
#include <openrj/openrj_memory.h>

#ifndef OPENRJ_NO_STDIO
# include <stdio.h>
#endif /* !OPENRJ_NO_STDIO */
#include <string.h>

/* Memory block format is as follows:
 *
 * [ ORJDatabaseA ] - rounded up to 16 bytes
 * [   raw data   ] - rounded up to 16 bytes
 * [   fields     ] - rounded up to 16 bytes
 * [   records    ] - rounded up to 16 bytes
 *
 * This leaves us with only one block, and with only two allocations
 */

#define round_up_16_(x)     (((x) + 15) & (~15))

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define false              (0)
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static char     *copy_advance(              char                        *dest
                                        ,   char const                  *src
                                        ,   size_t                      cch);
static int      process_field_markers(      char * const                py
                                        ,   size_t                      *numChars
                                        ,   size_t                      *numLines
                                        ,   size_t                      *numFields
                                        ,   size_t                      *numRecords
                                        ,   ORJError                    *error);
static ORJRC    ORJ_Field_GetNameAndValueA_(/* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname
                                        ,   /* [in] */ ORJStringA const **pvalue);

static int      field_compare(              void const                  *field1
                                        ,   void const                  *field2);

/** This function came about as a refactoring of ORJ_ReadDatabaseA() and
 * ORJ_CreateDatabaseFromMemoryA(), and as such may not represent the 'best'
 * implementation - particularly the number of parameters - but it is as a result
 * of the lowest risk evolution from ORJ_ReadDatabaseA() to the two API functions.
 *
 * Naturally, it may be subject to future refactoring.
 */
static ORJRC    ORJ_ExpandBlockAndParseA_(  ORJDatabaseA                *db
                                        ,   const size_t                cbDbStruct
                                        ,   size_t                      cbData
                                        ,   const size_t                cbAll
                                        ,   unsigned                    flags
                                        ,   IORJAllocator               *ator
                                        ,   ORJDatabaseA const          **pdatabase
                                        ,   ORJError                    *error
                                        ,   size_t                      size);

/* /////////////////////////////////////////////////////////////////////////////
 * API functions
 */

ORJ_CALL(ORJRC) ORJ_CreateDatabaseFromMemoryA(  /* [in] */ char const           *contents
                                            ,   /* [in] */ size_t               cbContents
                                            ,   /* [in] */ IORJAllocator        *ator
                                            ,   /* [in] */ unsigned             flags
                                            ,   /* [out] */ ORJDatabaseA const  **pdatabase
                                            ,   /* [out] */ ORJError            *error)
{
    ORJRC       rc;
    ORJError    error_;

    openrj_assert(NULL != contents);
    openrj_assert(NULL != pdatabase);

    *pdatabase = NULL;

    if(NULL == error)
    {
        error = &error_;
    }
    error->reserved0        =   0;
    error->invalidLine      =   0;
    error->invalidColumn    =   0;
    error->parseError       =   ORJ_PARSE_SUCCESS;

    if( 0 == cbContents ||
        '\0' == *contents)
    {
        rc = ORJ_RC_NORECORDS;
    }
    else
    {
        size_t  size    =   cbContents;

        if(0 == size)
        {
            rc = ORJ_RC_NORECORDS;
        }
        else
        {
            const size_t    cbDbStruct  =   round_up_16_(sizeof(ORJDatabaseA));
            const size_t    cbData      =   round_up_16_(size + 1); /* Add 1 here, so that we can null-terminate the last line even if it does not contain \n */
            size_t          cbAll       =   cbDbStruct + cbData;
            ORJDatabaseA    *db         =   (ORJDatabaseA*)openrj_ator_alloc_(ator, cbAll);

            if(NULL == db)
            {
                rc = ORJ_RC_OUTOFMEMORY;
            }
            else
            {
                /* Now we copy in the contents onto the end of the structure, and pass off for
                 * processing
                 */
                (void)memcpy(((char*)db) + cbDbStruct, contents, size);

                /* Add a nul */
                (cbDbStruct + size)[(char*)db] = '\0';

                rc = ORJ_ExpandBlockAndParseA_(db, cbDbStruct, cbData, cbAll, flags, ator, pdatabase, error, size);

                if(ORJ_RC_SUCCESS != rc)
                {
                    openrj_ator_free_(ator, db);
                }
            }
        }

        /* Must only return ptr if succeeded */
        openrj_assert((0 != (*pdatabase)) == (ORJ_RC_SUCCESS == rc));

        if(ORJ_RC_SUCCESS == rc)
        {
            /* Can't have fields if no records, and vice versa */
            openrj_assert((0 == (*pdatabase)->numFields) == (0 == (*pdatabase)->numRecords));

            if(0 != (flags & ORJ_FLAG_ELIDEBLANKRECORDS))
            {
                size_t  i;

                for(i = 0; i < (*pdatabase)->numRecords; ++i)
                {
                    openrj_assert(0 != (*pdatabase)->records[i].numFields);
                }
            }

            if(0 != (*pdatabase)->numFields)
            {
                size_t  i;

                for(i = 0; i < (*pdatabase)->numFields; ++i)
                {
                    openrj_assert(0 == (*pdatabase)->fields[i].mbz0);
                    openrj_assert(0 != (*pdatabase)->fields[i].name.len);
                    openrj_assert(NULL != (*pdatabase)->fields[i].name.ptr);
                    openrj_assert(NULL != (*pdatabase)->fields[i].value.ptr);
                    openrj_assert((0 == (*pdatabase)->fields[i].name.len) || ('\0' != (*pdatabase)->fields[i].name.ptr[0]));
                    openrj_assert((0 == (*pdatabase)->fields[i].value.len) || ('\0' != (*pdatabase)->fields[i].value.ptr[0]));
                }
            }
        }
    }

    return rc;
}

#ifndef OPENRJ_NO_FILE_HANDLING
ORJ_CALL(ORJRC) ORJ_ReadDatabaseA(  /* [in] */ char const           *jarFile
                                ,   /* [in] */ IORJAllocator        *ator
                                ,   /* [in] */ unsigned             flags
                                ,   /* [out] */ ORJDatabase const   **pdatabase
                                ,   /* [out] */ ORJError            *error)
{
    ORJRC       rc;
    FILE        *f;
    ORJError    error_;

    openrj_assert(NULL != jarFile);
    openrj_assert(NULL != pdatabase);

    *pdatabase = NULL;

    if(NULL == error)
    {
        error = &error_;
    }
    error->reserved0        =   0;
    error->invalidLine      =   0;
    error->invalidColumn    =   0;
    error->parseError       =   ORJ_PARSE_SUCCESS;

    /* (1) Open the file */
    f = fopen(jarFile, "rt");

    if(NULL == f)
    {
        rc = ORJ_RC_CANNOTOPENJARFILE;
    }
    else
    {
        /* (2) Determine the extent of the file */
        long    pos     =   fseek(f, 0, SEEK_END);
        long    size1    =   ftell(f);

        (void)fseek(f, pos, SEEK_SET);

        if(-1 == size1)
        {
            rc = ORJ_RC_BADFILEREAD;
        }
        else if(0 == size1)
        {
            rc = ORJ_RC_NORECORDS;
        }
        else
        {
            const size_t    cbDbStruct  =   round_up_16_(sizeof(ORJDatabaseA));
            const size_t    cbData      =   round_up_16_((size_t)size1 + 1); /* Add 1 here, so that we can null-terminate the last line even if it does not contain \n */
            size_t          cbAll       =   cbDbStruct + cbData;
            ORJDatabaseA    *db         =   (ORJDatabaseA*)openrj_ator_alloc_(ator, cbAll);

            if(NULL == db)
            {
                rc = ORJ_RC_OUTOFMEMORY;
            }
            else
            {
                /* Now we have the memory block, we read in all the contents and process them
                 * to determine the number of records involved.
                 */
                size_t  size2 = fread(((char*)db) + cbDbStruct, 1, cbData, f);

                if(0 == size2)
                {
                    rc = ORJ_RC_BADFILEREAD;
                }
                else
                {
                    /* Add a nul */
                    (cbDbStruct + size2)[(char*)db] = '\0';

                    rc = ORJ_ExpandBlockAndParseA_(db, cbDbStruct, cbData, cbAll, flags, ator, pdatabase, error, size2);
                }

                if(ORJ_RC_SUCCESS != rc)
                {
                    openrj_ator_free_(ator, db);
                }
            }
        }

        /* Must only return ptr if succeeded */
        openrj_assert((0 != (*pdatabase)) == (ORJ_RC_SUCCESS == rc));

        if(ORJ_RC_SUCCESS == rc)
        {
            /* Can't have fields if no records, and vice versa */
            openrj_assert((0 == (*pdatabase)->numFields) == (0 == (*pdatabase)->numRecords));

            if(0 != (flags & ORJ_FLAG_ELIDEBLANKRECORDS))
            {
                size_t  i;

                for(i = 0; i < (*pdatabase)->numRecords; ++i)
                {
                    openrj_assert(0 != (*pdatabase)->records[i].numFields);
                }
            }

            if(0 != (*pdatabase)->numFields)
            {
                size_t  i;

                for(i = 0; i < (*pdatabase)->numFields; ++i)
                {
                    openrj_assert(0 == (*pdatabase)->fields[i].mbz0);
                    openrj_assert(0 != (*pdatabase)->fields[i].name.len);
                    openrj_assert(NULL != (*pdatabase)->fields[i].name.ptr);
                    openrj_assert(NULL != (*pdatabase)->fields[i].value.ptr);
                    openrj_assert((0 == (*pdatabase)->fields[i].name.len) || ('\0' != (*pdatabase)->fields[i].name.ptr[0]));
                    openrj_assert((0 == (*pdatabase)->fields[i].value.len) || ('\0' != (*pdatabase)->fields[i].value.ptr[0]));
                }
            }
        }

        (void)fclose(f);
    }

    return rc;
}
#endif /* !OPENRJ_NO_FILE_HANDLING */

static ORJRC ORJ_ExpandBlockAndParseA_( ORJDatabaseA        *db
                                    ,   const size_t        cbDbStruct
                                    ,   size_t              cbData
                                    ,   const size_t        cbAll
                                    ,   unsigned            flags
                                    ,   IORJAllocator       *ator
                                    ,   ORJDatabaseA const  **pdatabase
                                    ,   ORJError            *error
                                    ,   size_t              size)
{
    ORJRC       rc;
    char *const pchData1 =   ((char*)db) + cbDbStruct;
    size_t      numLines;
    size_t      numFields;
    size_t      numRecords;

    /* 0-fill the remainder of the data block */
    (void)memset(&pchData1[size], 0, cbData - size);

    /* Process the block, counting the number of lines, fields and records */
    if(!process_field_markers(pchData1, &size, &numLines, &numFields, &numRecords, error))
    {
        rc = ORJ_RC_PARSEERROR;
    }
    else
    {
        /* Now we need to reallocate, and apportion the fields and record structures */
        const size_t    cbFields    =   round_up_16_(numFields * sizeof(ORJFieldA));
        const size_t    cbRecords   =   round_up_16_(numRecords * sizeof(ORJRecordA));
        size_t          cbAllNew    =   cbAll + cbFields + cbRecords;
        ORJDatabaseA    *newDb      =   (ORJDatabaseA*)openrj_ator_realloc_(ator, db, cbAllNew);

#ifdef _DEBUG
        memset((char*)newDb + cbDbStruct + size + 1, 'ª', cbAllNew - (cbDbStruct + size + 1));
#endif /* _DEBUG */

        if(NULL == newDb)
        {
            rc = ORJ_RC_OUTOFMEMORY; /* The free() below will release the initial block */
        }
        else
        {
            /* The reallocation has succeeded, so we now. */

            char *const             pchData2    =   ((char*)newDb) + cbDbStruct;    /* This is hiding outer scope, but buys us const */
            char const *const       end1        =   &pchData2[size];
            ORJFieldA *const        pFields     =   (ORJFieldA*)&pchData2[round_up_16_(size)];
            ORJRecordA *const       pRecords    =   (ORJRecordA*)&pchData2[round_up_16_(size) + cbFields];
            ORJRecordA const *const lastRecord  =   &pRecords[numRecords];
            char                    *data       =   &pchData2[0];
            ORJFieldA               *field      =   &pFields[0];
            ORJFieldA               *field0;
            ORJRecordA              *record     =   &pRecords[0];

            openrj_assert((void*)pchData2 < (void*)end1);
            openrj_assert((void*)end1 <= (void*)pFields);
            openrj_assert((void*)pFields <= (void*)pRecords);

            db = newDb;

            record->mbz0        =   0;
            record->numFields   =   0;

            if(0 == numFields)
            {
                numRecords = 0;
            }
            else
            {
                openrj_assert((void*)pFields < (void*)pRecords);

                /* Now tie up all the fields and records */
                for(field0 = field; data != end1; )
                {
                    size_t const len = strlen(data);

                    openrj_assert(NULL == strchr(data, '\r'));
                    openrj_assert(NULL == strchr(data, '\n'));

                    if(0 == len)
                    {
                        /* A blank line. Skip it */
                    }
                    else if('%' == data[0] &&
                            '%' == data[1])
                    {
                        /* A comment line. Will terminate record */

                        record->fields      =   field0;
                        record->reserved0   =   db;
                        field0 = field;

                        if(ORJ_FLAG_ORDERFIELDS == (flags & ORJ_FLAG_ORDERFIELDS))
                        {
                            /* Now sort the elements */
                            qsort(record->fields, record->numFields, sizeof(ORJFieldA), field_compare);
                        }

                        record->comment.len =   len - 2;
                        record->comment.ptr =   data + 2;

                        for(; '\0' != *record->comment.ptr; ++record->comment.ptr, --record->comment.len)
                        {
                            if( ' ' != *record->comment.ptr &&
                                '\t' != *record->comment.ptr)
                            {
                                break;
                            }
                        }

                        openrj_assert(0 <= (ptrdiff_t)record->comment.len);
                        openrj_assert(record->comment.len < len);
                        openrj_assert(NULL != record->comment.ptr);
                        openrj_assert(' ' != record->comment.ptr[0]);
                        openrj_assert('\t' != record->comment.ptr[0]);
                        openrj_assert(data <= record->comment.ptr);
                        openrj_assert(record->comment.ptr <= data + len);
                        openrj_assert((0 == record->comment.len) || (record->comment.ptr <= data + 2 + record->comment.len));
                        openrj_assert('\0' == record->comment.ptr[record->comment.len]);

                        if( ORJ_FLAG_ELIDEBLANKRECORDS == (flags & ORJ_FLAG_ELIDEBLANKRECORDS) &&
                            0 == record->numFields)
                        {
                            --numRecords;
                        }
                        else
                        {
                            ++record;
                        }
                        if(record != lastRecord)
                        {
                            record->mbz0        =   0;
                            record->numFields   =   0;
                            record->fields      =   NULL;
                        }
                    }
                    else
                    {
                        /* A genuine field */

                        char    *end2    =   data + len;
                        char    *colon;
                        char    *value;

                        /* 1. Remove space before end */
                        for(; data != end2; --end2)
                        {
                            if( ' ' != *(end2 - 1) &&
                                '\t' != *(end2 - 1))
                            {
                                break;
                            }

                            *(end2 - 1) = '\0'; /* Strips trailing whitespace from line */
                        }

                        colon = strchr(data, ':');

                        if(NULL == colon)
                        {
                            colon = end2;
                            value = end2;
                        }
                        else
                        {
                            char ch;

                            *colon = '\0'; /* NUL terminates name */

                            value = colon + 1;

                            /* Trim end of name */
                            for(; data != colon; --colon)
                            {
                                if( ' ' != *(colon - 1) &&
                                    '\t' != *(colon - 1))
                                {
                                    break;
                                }

                                *(colon - 1) = '\0'; /* Strips trailing whitespace from line */
                            }

                            /* Trim start of value */
                            for(; '\0' != (ch = *value); )
                            {
                                if( ' ' != ch &&
                                    '\t' != ch)
                                {
                                    break;
                                }

                                ++value;
                            }
                        }

                        /* At this point, the following must hold:
                         *
                         * - data points to start of name
                         * - colon points to end of name
                         * - value points to start of value
                         * - end points to end of value
                         */

                        openrj_assert(NULL != data);
                        openrj_assert(NULL != colon);
                        openrj_assert(NULL != value);
                        openrj_assert(NULL != end2);

                        openrj_assert(data <= colon);
                        openrj_assert(colon <= value);
                        openrj_assert(value <= end2);

                        field->mbz0         =   0;
                        field->name.ptr     =   data;
                        field->name.len     =   (size_t)(colon - data);
                        field->value.ptr    =   value;
                        field->value.len    =   (size_t)(end2 - value);
                        field->reserved0    =   record;

                        openrj_assert(field->name.ptr <= field->value.ptr);

                        openrj_assert('\0' == field->name.ptr[field->name.len]);
                        openrj_assert('\0' == field->value.ptr[field->value.len]);

                        ++field;
                        ++record->numFields;
                    }

                    data += 1 + len;
                }
            }

            db->mbz0        =   0;
            db->flags       =   flags;

            db->numLines    =   numLines;
            db->numFields   =   numFields;
            db->numRecords  =   numRecords;

            db->records     =   pRecords;
            db->fields      =   pFields;
            db->ator        =   ator;

            *pdatabase = db;

            rc = ORJ_RC_SUCCESS;
        }
    }

    return rc;
}

ORJ_CALL(ORJRC) ORJ_FreeDatabaseA(/* [in] */ ORJDatabase const *database_)
{
    ORJDatabase *database   =   (ORJDatabase*)database_;

    openrj_assert(NULL != database);

#ifdef _DEBUG
    {
        IORJAllocator   *ator   =   database->ator;

        memset(database, 'ª', 50/*sizeof(ORJDatabase)*/);

        database->ator = ator;
    }
#endif /* _DEBUG */

    openrj_ator_free_(database->ator, database);

    return ORJ_RC_SUCCESS;
}

ORJ_CALL(ORJRC) ORJ_Database_GetRecordA(/* [in] */ ORJDatabaseA const   *database
                                    ,   /* [in] */ size_t               iRecord
                                    ,   /* [in] */ ORJRecordA const     **precord)
{
    ORJRC   rc;

    openrj_assert(NULL != database);
    openrj_assert(NULL != precord);

    if(iRecord < database->numRecords)
    {
        *precord = &database->records[iRecord];

        openrj_assert(NULL != *precord);

        rc = ORJ_RC_SUCCESS;
    }
    else
    {
        *precord = NULL;

        rc = ORJ_RC_INVALIDINDEX;
    }

    return rc;
}

ORJ_CALL(ORJRC) ORJ_Record_GetFieldA(       /* [in] */ ORJRecordA const *record
                                        ,   /* [in] */ size_t           iField
                                        ,   /* [in] */ ORJFieldA const  **pfield)
{
    ORJRC   rc;

    openrj_assert(NULL != record);
    openrj_assert(NULL != pfield);

    if(iField < record->numFields)
    {
        *pfield = &record->fields[iField];

        rc = ORJ_RC_SUCCESS;
    }
    else
    {
        *pfield = NULL;

        rc = ORJ_RC_INVALIDINDEX;
    }

    return rc;
}

ORJ_CALL(ORJFieldA const*) ORJ_Record_FindFieldByNameA( /* [in] */ ORJRecordA const *record
                                                    ,   /* [in] */ char const       *fieldName
                                                    ,   /* [in] */ char const       *fieldValue)
{
    ORJFieldA const *begin;
    ORJFieldA const *end;
    size_t          cchFieldName;
    size_t          cchFieldValue;

    openrj_assert(NULL != record);
    openrj_assert(NULL != fieldName);

    cchFieldName    =   strlen(fieldName);
    cchFieldValue   =   (NULL == fieldValue) ? 0 : strlen(fieldValue);

    begin   =   &record->fields[0];
    end     =   &record->fields[record->numFields];
    for(; begin != end; ++ begin)
    {
        /* Name must be same length and contents */
        if( cchFieldName == begin->name.len &&
            0 == strncmp(fieldName, begin->name.ptr, begin->name.len))
        {
            /* Value must be NULL (meaning match any) or must be same length and contents */
            if( 0 == cchFieldValue ||
                (   cchFieldValue == begin->value.len &&
                    0 == strncmp(fieldValue, begin->value.ptr, begin->value.len)))
            {
                return begin;
            }
        }
    }

    return NULL;
}

ORJ_CALL(ORJDatabaseA const*) ORJ_Record_GetDatabaseA(/* [in] */ ORJRecordA const *record)
{
    openrj_assert(NULL != record);

    return (ORJDatabaseA const*)record->reserved0;
}

ORJ_CALL(ORJRC) ORJ_Record_GetCommentA(     /* [in] */ ORJRecordA const *record
                                        ,   /* [in] */ ORJStringA const **pcomment)
{
    openrj_assert(NULL != record);
    openrj_assert(NULL != pcomment);

    *pcomment = &record->comment;

    return ORJ_RC_SUCCESS;
}

ORJ_CALL(ORJRC) ORJ_Field_GetNameA(         /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname)
{
    openrj_assert(NULL != field);
    openrj_assert(NULL != pname);

    return ORJ_Field_GetNameAndValueA_(field, pname, NULL);
}

ORJ_CALL(ORJRC) ORJ_Field_GetValueA(        /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pvalue)
{
    openrj_assert(NULL != field);
    openrj_assert(NULL != pvalue);

    return ORJ_Field_GetNameAndValueA_(field, NULL, pvalue);
}

ORJ_CALL(ORJRC) ORJ_Field_GetNameAndValueA( /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname
                                        ,   /* [in] */ ORJStringA const **pvalue)
{
    openrj_assert(NULL != field);
    openrj_assert(NULL != pname);
    openrj_assert(NULL != pvalue);

    return ORJ_Field_GetNameAndValueA_(field, pname, pvalue);
}

ORJ_CALL(ORJRecordA const*) ORJ_Field_GetRecordA(  /* [in] */ ORJFieldA const *field)
{
    openrj_assert(NULL != field);

    return (ORJRecordA const*)field->reserved0;
}

/* ////////////////////////////////////////////////////////////////////////// */

static int field_compare(void const *field1_, void const *field2_)
{
    ORJFieldA const *field1 = (ORJFieldA const*)field1_;
    ORJFieldA const *field2 = (ORJFieldA const*)field2_;

    return strcmp(field1->name.ptr, field2->name.ptr);
}

/* ////////////////////////////////////////////////////////////////////////// */

static ORJRC ORJ_Field_GetNameAndValueA_(   /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname
                                        ,   /* [in] */ ORJStringA const **pvalue)
{
    if(NULL != pname)
    {
        *pname = &field->name;
    }
    if(NULL != pvalue)
    {
        *pvalue = &field->value;
    }

    return ORJ_RC_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */

static char *copy_advance(char *dest, char const *src, size_t cch)
{
    return (char*)memcpy(dest, src, cch) + cch;
}

/* ////////////////////////////////////////////////////////////////////////// */

static int process_field_markers(char * const py, size_t *numChars, size_t *numLines, size_t *numFields, size_t *numRecords, ORJError *error)
{
#if 0
    enum State
    {
            START_OF_LINE           /*!< The initial state, and the state after the end of a non-continuation line */
        ,   NORMAL                  /*!< Within a normal line */
        ,   COMMENT                 /*!< Within a comment, which endures until the end of a line. Comment lines cannot be continued */
    };
    typedef enum  State  State;
#endif /* 0 */

    /* We need to iterate through this, counting the %%'s */
#if 0
    State       state                   =   NORMAL;
#endif /* 0 */
    char const  *end                    =   py + *numChars;
    char const  *begin;
    char const  *start;
    char        *dest;
#if !defined(WIN32)
    char        *next;
#endif /* !WIN32 */
    char        last_char               =   0;
    int         numLinesToInsert;
    int         numInitialWsToSkip      =   0;
    int         line                    =   0;
    int         column                  =   0;
    int         leadingCommentChars     =   0;
    int         isInContinuation        =   0;
    int         isInCommentLine         =   0;
    int         fieldLength             =   0;
    int         numFieldsThisRecord     =   0;

    openrj_assert(NULL != numChars);
    openrj_assert(NULL != numFields);
    openrj_assert(NULL != numRecords);
    openrj_assert(NULL != error);

    *numLines           =   0;
    *numFields          =   0;
    *numRecords         =   0;
/*  *error->invalidLine =   -1; */

#if !defined(WIN32)
    /* Remove all carriage returns. This has to be done on other platforms,
     * since we might be using data files created on Windows.
     */
    for(begin = py, next = py; begin != end; ++begin)
    {
        if('\r' == *begin)
        {
            --*numChars;
        }
        else
        {
            if(next != begin)
            {
                *next = *begin;
            }
            ++next;
        }
    }
    end = py + *numChars;
#endif /* !WIN32 */

    /* Trim all trailing whitespace (space or tab)
     *
     * This is effected by a single pass through the data, and noting the ends
     * of lines and continuation characters
     *
     */
    for(numLinesToInsert = 0, begin = py, start = py, dest = py; begin != end; ++begin)
    {
        const char  this_char   =   *begin;
        size_t      cch;

        /* In this loop, the variable tasks are as follows:
         *
         * begin - the current pointer in the processing
         * dest  - the output pointer
         * start - the start of the good input
         */

        switch(this_char)
        {
            case    '\n':
                /* (1) Copy all from [start:begin) => dest, and advance dest */
                cch = (size_t)(begin - start);
                dest = copy_advance(dest, start, cch);

                /* (2) One more line to insert */
                ++numLinesToInsert;

                /* (3) process the line */
                if('\\' == last_char)
                {
                    /* For continuation, just drop dest back one */
                    --dest;

                    isInContinuation = 1;
                    fieldLength += column;
                }
                else
                {
                    if(isInContinuation)
                    {
                        fieldLength += column;
                    }
                    else
                    {
                        fieldLength = column;
                    }

                    if( fieldLength > 0 &&
                        !isInCommentLine &&
                        0 == numInitialWsToSkip)
                    {
                        openrj_assert(0 == numInitialWsToSkip);

                        ++*numFields;
                        ++numFieldsThisRecord;
                    }
                    fieldLength = 0;

                    isInContinuation = 0;
                    isInCommentLine = 0;

                    /* Not a continuation, so put all lines here */
                    for(; numLinesToInsert; numLinesToInsert--)
                    {
                        *dest++ = '\0';
                    }
                }

                /* (4) advance start */
                start += cch + 1;

                /* (5) Reset start of line skip */
                numInitialWsToSkip = 0;

                break;
            case    ' ':
            case    '\t':
                /* If this is the beginning of the line, then we ignore it
                 * If it's at the end of the line, then we ignore it
                 */
                if( '\n' == last_char ||
                    numInitialWsToSkip > 0)
                {
                    ++numInitialWsToSkip;
                    ++start;
                }
                else if('\\' == last_char)
                {
                    /* Must determine whether or not we are on the end of
                     * a line, or just some valid text that contains "\\ "
                     */
                    int     isTrailingContinuation  =   1;
                    char    *f;

                    for(f = (char*)begin; f != end; )
                    {
                        if( ' ' == *f ||
                            '\t' == *f)
                        {
                            ++f;
                        }
                        else
                        {
                            if('\n' != *f)
                            {
                                isTrailingContinuation = 0;
                            }

                            break;
                        }
                    }

                    if(isTrailingContinuation)
                    {
                        /* Now we can just move everything along to  */
                        cch = (size_t)(begin - start - 1);
                        dest = copy_advance(dest, start, cch);
                        begin = f;
                        start = f + 1;
                        ++numLinesToInsert;
                    }
                }
                break;
            case    '%':
                if( !isInCommentLine &&
                    (   0 == column ||
                        leadingCommentChars > 0))
                {
                    ++leadingCommentChars;

                    if(leadingCommentChars > 1)
                    {
                        ++*numRecords;
                        numFieldsThisRecord = 0;

                        isInCommentLine = 1;

                        if(isInContinuation)
                        {
                            error->invalidLine      =   (unsigned)line;
                            error->invalidColumn    =   (unsigned)column;
                            error->parseError       =   ORJ_PARSE_RECORDSEPARATORINCONTINUATION;

                            return 0;
                        }
                    }
                } /* Fall through */
            default:
                numInitialWsToSkip = 0;
                break;
        }

        last_char = *begin;

        if('\n' == this_char)
        {
            ++line;
            column = 0;
            leadingCommentChars = 0;
        }
        else
        {
            ++column;
        }
    }

    if( '\n' != last_char &&
        '\0' != last_char)
    {
        error->invalidLine      =   (unsigned)line;
        error->invalidColumn    =   (unsigned)column;
        error->parseError       =   ORJ_PARSE_UNFINISHEDLINE;

        return 0;
    }

    *numChars = (size_t)(dest - py);

#ifdef x_DEBUG
    for(begin = py, end = py + *numChars; begin < end; )
    {
        if('\0' == *begin)
        {
            puts("");
            ++begin;
        }
        else
        {
            size_t len = strlen(begin);
            printf("[%s]\n", begin);
            begin += 1 + len;
        }
    }
#endif /* _DEBUG */

    *numLines = (size_t)line;

    if(0 != numFieldsThisRecord)
    {
        error->invalidLine      =   (unsigned)line;
        error->invalidColumn    =   (unsigned)column;
        error->parseError       =   ORJ_PARSE_UNFINISHEDRECORD;

        return 0;
    }

    if(0 != numLinesToInsert)
    {
        error->invalidLine      =   (unsigned)line;
        error->invalidColumn    =   (unsigned)column;
        error->parseError       =   ORJ_PARSE_UNFINISHEDFIELD;

        return 0;
    }

    return 1;
}

/* ////////////////////////////////////////////////////////////////////////// */
