/* /////////////////////////////////////////////////////////////////////////////
 * File:    std/c/openrj.d
 *
 * Purpose: D declarations for the Open-RJ library API
 *
 * Created: 26th June 2004
 * Updated: 30th September 2004
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004, Matthew Wilson and Synesis Software
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


/* std/c/openrj.d D declarations for the Open-RJ library API
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Module
 */

module std.c.openrj;

/* /////////////////////////////////////////////////////////////////////////////
 * Imports
 */


/* /////////////////////////////////////////////////////////////////////////////
 * Enumerations
 */

public enum ORJ_FLAG
{
        ORJ_FLAG_ORDERFIELDS        =   0x0001  /*!< Arranges the fields in alphabetical order */
    ,   ORJ_FLAG_ELIDEBLANKRECORDS  =   0x0002  /*!< Causes blank records to be ignored */
};

public enum ORJRC
{
        ORJ_RC_SUCCESS              =   0
    ,   ORJ_RC_CANNOTOPENJARFILE
    ,   ORJ_RC_NORECORDS
    ,   ORJ_RC_OUTOFMEMORY
    ,   ORJ_RC_BADFILEREAD
    ,   ORJ_RC_PARSEERROR
    ,   ORJ_RC_INVALIDINDEX
    ,   ORJ_RC_UNEXPECTED
    ,   ORJ_RC_INVALIDCONTENT
};

public enum ORJ_PARSE_ERROR
{
        ORJ_PARSE_SUCCESS
    ,   ORJ_PARSE_RECORDSEPARATORINCONTINUATION
    ,   ORJ_PARSE_UNFINISHEDRECORD
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

struct ORJFieldA
{
    size_t      mbz0;       /*!< Reserved: must be 0 */
    char[]      name;       /*!< The field name */
    char[]      value;      /*!< The field value */
    void        *reserved0; /*!< Reserved. Cannot be used by client code */
};

alias ORJFieldA         ORJField;
alias ORJFieldA         Field;


struct ORJRecordA
{
    size_t      mbz0;       /*!< Reserved: must be 0 */
    ORJFieldA[] fields;     /*!< The field array */
    void        *reserved0; /*!< Reserved. Cannot be used by client code */
};

alias ORJRecordA            ORJRecord;
alias ORJRecordA            Record;



struct ORJDatabaseA
{
    size_t          mbz0;       /*!< Reserved: must be 0 */
    size_t          flags;      /*!< Holds the flags passed to the function used to create the database */
    size_t          numLines;   /*!< The number of lines in the database */
    ORJFieldA[]     fields;     /*!< The record array */
    ORJRecordA[]    records;    /*!< The record array */
    void            *reserved0; /*!< The allocator */
};

alias ORJDatabaseA      ORJDatabase;
alias ORJDatabaseA      Database;


struct ORJError
{
    size_t          mbz0;
    uint            invalidLine;
    uint            invalidColumn;
    ORJ_PARSE_ERROR parseError;
};


struct IORJAllocator
{
    /** Defines the "member" function for allocating memory */
    void *(*pfnAlloc)(IORJAllocator *ator, size_t cb);
    /** Defines the "member" function for reallocating memory */
    void *(*pfnRealloc)(IORJAllocator *ator, void *pv, size_t cb);
    /** Defines the "member" function for freeing memory */
    void (*pfnFree)(IORJAllocator *ator, void *pv);
};

/* /////////////////////////////////////////////////////////////////////////////
 * API
 */

extern(C)
{

/***************************************
 * Database manipulation functions
 */

/** \name Database manipulation functions
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Reads the records from the given file into an Open-RJ databsae
 *
 * \param jarName Name of the Record-JAR file. May not be NULL
 * \param ator The allocator to use for allocating memory, May be NULL, in which case CRT malloc() / realloc() / free() are used
 * \param pdatabase Pointer to a database pointer, in which will be returned the database. May not be NULL. The returned pointer
 * must be freed using ORJ_FreeDatabaseA().
 */

ORJRC ORJ_ReadDatabaseA(in char             *jarName
                    ,   in void             *ator
                    ,   in uint             flags
                    ,   out ORJDatabaseA    *database
                    ,   in ORJError         *error);


/** \brief Frees the resources associated with the database
 *
 * \param database The database. May not be NULL
 */
ORJRC ORJ_FreeDatabaseA(in ORJDatabaseA *database);

/** \brief Gives the number of lines in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
size_t ORJ_Database_GetNumLinesA(in ORJDatabaseA *database);

/** \brief Gives the number of fields in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
size_t ORJ_Database_GetNumFieldsA(in ORJDatabaseA *database);

/** \brief Gives the number of records in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
size_t ORJ_Database_GetNumRecordsA(in ORJDatabaseA *database);

/** \brief Gives the number of records in a database
 *
 * \param database The database from which the record is to be retrieved
 * \param iRecord Index of the record to be retrieved
 * \param precord Pointer to a record pointer. The returned value points at the requested record stucture
 */
ORJRC ORJ_Database_GetRecordA(  in ORJDatabaseA *database
                            ,   in size_t       iRecord
                            ,   in ORJRecordA   **precord);

/** @} */

/***************************************
 * Record manipulation functions
 */

/** \name Record manipulation functions
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the number of fields in a record
 *
 * \param record The record. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
size_t ORJ_Record_GetNumFieldsA(in ORJRecordA *record);

/** \brief Gives the number of field in a record
 *
 * \param record The record from which to retrieve the field
 * \param iField Index of the field to be retrieved
 * \param pfield Pointer to a field pointer. The returned value points at the requested field stucture
 */
ORJRC ORJ_Record_GetFieldA( in ORJRecordA   *record
                        ,   in size_t       iField
                        ,   in ORJFieldA    **pfield);

ORJFieldA *ORJ_Record_FindFieldByNameA( in ORJRecordA   *record
                                    ,   in char         *fieldName
                                    ,   in char         *fieldValue);

/** \brief Gives the database associated with the record
 *
 * \param record The record. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
ORJDatabaseA *ORJ_Record_GetDatabaseA(in ORJRecordA *record);

/** @} */

/***************************************
 * Field manipulation functions
 */

/** \name Field manipulation functions
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the name of a field
 *
 * \param field The field whose name is to be retrieved
 * \param pname Pointer to a string pointer. The returned value points at a string 
 * structure representing the name
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJRC ORJ_Field_GetNameA(   in ORJFieldA    *field
                        ,   out char[]      name);

/** \brief Gives the value of a field
 *
 * \param field The field whose value is to be retrieved
 * \param pvalue Pointer to a string pointer. The returned value points at a string 
 * structure representing the value
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJRC ORJ_Field_GetValueA(  in ORJFieldA    *field
                        ,   out char[]      value);

/** \brief Gives the name and value of a field
 *
 * \param field The field whose value is to be retrieved
 * \param pname Pointer to a string pointer. The returned value points at a string 
 * structure representing the name
 * \param pvalue Pointer to a string pointer. The returned value points at a string 
 * structure representing the value
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJRC ORJ_Field_GetNameAndValueA(   in ORJFieldA    *field
                                ,   out char[]      name
                                ,   out char[]      value);

/** \brief Gives the record associated with the field
 *
 * \param field The field. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
ORJRecordA *ORJ_Field_GetRecordA(in ORJFieldA *field);

/** @} */


/***************************************
 * Error functions
 */

/** \name Error functions
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the name of the error
 *
 * \param errorCode The error whose name is to be retrieved
 * \note If the error is not recognised, the function returns the empty string ("")
 */
char *ORJ_GetErrorStringA( /* [in] */ ORJRC            errorCode);

/** \brief Gives the name of the parse-error
 *
 * \param errorCode The parse-error whose name is to be retrieved
 * \note If the error is not recognised, the function returns the empty string ("")
 */
char *ORJ_GetParseErrorStringA( /* [in] */ ORJ_PARSE_ERROR errorCode);

/** @} */

} // extern(C)

/* ////////////////////////////////////////////////////////////////////////// */

version(MainTest)
{
    int main(char[][] args)
    {
        if(args.length < 2)
        {
            printf("Specify an Open-RJ file");
        }
        else
        {
            Database    *database;
            ORJRC       rc   =  ORJ_ReadDatabaseA(args[1], null, 0, database, null);

            if(0 != rc)
            {
                printf("Failed: %u\n", rc);
            }
            else
            {
                printf("Num lines:   %u\n", database.numLines);
                printf("Num fields:  %u\n", database.fields.length);
                printf("Num records: %u\n", database.records.length);

                foreach(Record record; database.records)
                {
                    printf("  Record; num fields: %u\n", record.fields.length);

                    foreach(Field field; record.fields)
                    {
                        printf("    name:  %.*s; value: %.*s\n", field.name, field.value);
                    }
                }

                ORJ_FreeDatabaseA(database);
            }
        }

        return 0;
    }
}

/* ////////////////////////////////////////////////////////////////////////// */
