/* /////////////////////////////////////////////////////////////////////////////
 * File:        C_simple.c
 *
 * Purpose:     C test program for the Open-RJ core library. This program uses
 *              the memory database functions, and attempts to be a
 *              smallest-possible informative example.
 *
 * Created:     25th May 2005
 * Updated:     25th May 2005
 *
 * www:         http://www.openrj.org/
 *
 * Thanks:      To Rajiv Bhagwat for pointing out that the test programs left
 *              much to be desired in terms of discoverability.
 *
 * License:     Copyright 2004-2005, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2005
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* Open-RJ Header Files */
#include <openrj/openrj.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

// Sample database
static const char   contents[] =

    "%% Sample Open-RJ database - Cats and Dogs\n"
    "%% Created:   28th September 2004\n"
    "%% Updated:   29th September 2004\n"
    "Name:      Barney\n"
    "Species:   Dog\n"
    "Breed:     Bijon \\\n"
    "           Frieze\n"
    "%%\n"
    "Name:      Elsa\n"
    "Species:   Dog\n"
    "Breed:     Mixed\n"
    "%%\n"
    "Name:      Fluffy Kitten\n"
    "Species:   Cat\n"
    "%%\n"
    "Name:      Moet\n"
    "Species:   Dog\n"
    "Breed:     Boxer\n"
    "%%\n"
    "Name:      Rebel\n"
    "Species:   Dog\n"
    "Breed:     German \\\n"
    "           Shepherd\n"
    "%%\n"
    "Name:      Pepper\n"
    "Species:   Dog\n"
    "Breed:     Border Collie\n"
    "%%\n"
    "Name:      Samson\n"
    "Species:   Dog\n"
    "Breed:     Ridgeback\n"
    "%%\n"
    "Name:      Sheltie\n"
    "Species:   Dog\n"
    "Breed:     Shetland \\\n"
    "           Sheepdog\n"
    "%%\n"
    "Name:      Sparky\n"
    "Species:   Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    unsigned            flags       =   0; /* Could try ORJ_FLAG_ORDERFIELDS and/or ORJ_FLAG_ELIDEBLANKRECORDS */
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory, so use memory_database */
    rc = ORJ_CreateDatabaseFromMemory(contents, sizeof(contents), NULL, flags, &db, &error);

    if(0 != rc)
    {
        printf("Error at line %u, column %u: %s\n", error.invalidLine, error.invalidColumn, ORJ_GetErrorStringA(rc));

        return EXIT_FAILURE;
    }
    else
    {
        /* 2. Display database characteristics using structure accesses */
        printf("\n2. Display database characteristics (via structure member access):\n");

        printf("Database has %u lines in %u fields in %u records\n", db->numLines, db->numFields, db->numRecords);

        /* 3. Display database characteristics using method calls */
        printf("\n3. Display database characteristics (via API function call):\n");

        printf("Database has %u lines in %u fields in %u records\n", ORJ_Database_GetNumLinesA(db), ORJ_Database_GetNumFieldsA(db), ORJ_Database_GetNumRecordsA(db));

        /* 4. Enumerate the contents using structure accesses */
        {
            size_t  iRecord;

            printf("\n4. Enumerate the contents  (via structure member access):\n");

            for(iRecord = 0; iRecord < db->numRecords; ++iRecord)
            {
                size_t      iField;
                ORJRecordA  *rec =   &db->records[iRecord];

                if( NULL != rec->comment.ptr &&
                    0 != rec->comment.len)
                {
                    printf("record-#%u; %.*s (%u fields)\n", iRecord, rec->comment.len, rec->comment.ptr, rec->numFields);
                }
                else
                {
                    printf("record-#%d (%d fields)\n", iRecord, rec->numFields);
                }

                for(iField = 0; iField < rec->numFields; ++iField)
                {
                    ORJFieldA   *field  =   &rec->fields[iField];

                    printf("  field-#%d [%.*s]:[%.*s]\n", iField, field->name.len, field->name.ptr, field->value.len, field->value.ptr);
                }
            }
        }

        /* 5. Enumerate the contents using method calls */
        {
            size_t  iRecord;

            printf("\n5. Enumerate the contents  (via API function call):\n");

            for(iRecord = 0; iRecord < ORJ_Database_GetNumRecordsA(db); ++iRecord)
            {
                size_t              iField;
                ORJRecordA const    *rec;
                ORJStringA const    *comment;

                ORJ_Database_GetRecordA(db, iRecord, &rec);

                if( ORJ_RC_SUCCESS == ORJ_Record_GetCommentA(rec, &comment) &&
                    0 != comment->len)
                {
                    printf("record-#%u; %.*s (%u fields)\n", iRecord, comment->len, comment->ptr, ORJ_Record_GetNumFieldsA(rec));
                }
                else
                {
                    printf("record-#%u (%u fields)\n", iRecord, ORJ_Record_GetNumFieldsA(rec));
                }

                for(iField = 0; iField < ORJ_Record_GetNumFieldsA(rec); ++iField)
                {
                    ORJFieldA const     *field;
                    ORJFieldA const     *field2;
                    ORJStringA const    *name;
                    ORJStringA const    *value;

                    ORJ_Record_GetFieldA(rec, iField, &field);

                    ORJ_Field_GetNameAndValueA(field, &name, &value);

                    printf("  field-#%u [%.*s]:[%.*s]\n", iField, (int)field->name.len, field->name.ptr, (int)field->value.len, field->value.ptr);

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
                    /* Now do a check to verify that the ORJ_Record_FindFieldByNameA() method works! */

                    field2  =   ORJ_Record_FindFieldByNameA(rec, name->ptr, value->ptr);

                    if(field != field2)
                    {
                        fprintf(stderr, "** Field mismatch!! **\n");
                    }
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
                }
            }
        }

        /* Finally, free the database */
        ORJ_FreeDatabase(db);
    }

	((void)argc);
	((void)argv);

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
