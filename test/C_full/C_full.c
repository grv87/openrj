/* /////////////////////////////////////////////////////////////////////////////
 * File:        C_full.c
 *
 * Purpose:     C test program for the Open-RJ library.
 *
 * Created:     11th June 2004
 * Updated:     26th December 2006
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
 *              This source code is placed into the public domain 2004
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
 * Compiler warning handling
 */

#if defined(_MSC_VER) && \
    !defined(__INTEL_COMPILER) && \
    !defined(__DMC__)
# if _MSC_VER < 1300
#  pragma warning(disable : 4127)   /* Suppresses "conditional expression is constant", found in assertions */
# endif /* _MSC_VER < 1300 */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper function declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);
static int  run_unittests(void);
static int  run_unittest1(void);
static int  run_unittest2(void);
static int  execute_unittest(ORJDatabaseA const *database);

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    int         i;
    char const  *jarName    =   NULL;
    unsigned    flags       =   0;

    /* Parse the command-line arguments. */
    for(i = 1; i < argc; ++i)
    {
        const char  *arg    =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                /* -- arguments */
                if( 0 == strcmp("unittest", arg + 2) ||
                    0 == strcmp("unittests", arg + 2))
                {
                    return run_unittests();
                }
                else
                {
                    usage(1, "Invalid argument(s) specified", i, argc, argv);
                }
            }
            else
            {
                /* - arguments */
                switch(arg[1])
                {
                    case    '?':
                        usage(1, NULL, -1, argc, argv);
                        break;
                    case    'i':
                        flags |= ORJ_FLAG_IGNORECASEONLOOKUP;
                        break;
                    case    'o':
                        flags |= ORJ_FLAG_ORDERFIELDS;
                        break;
                    case    's':
                        flags |= ORJ_FLAG_ELIDEBLANKRECORDS;
                        break;
                    default:
                        usage(1, "Invalid argument(s) specified", i, argc, argv);
                        break;
                }
            }
        }
        else
        {
            /* other arguments */
            if(NULL == jarName)
            {
                jarName = arg;
            }
            else
            {
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
        }
    }

    if(NULL == jarName)
    {
        usage(1, "Must specify a JAR name", -1, argc, argv);
    }
    else
    {
        /* Here's where the use of the library starts. */

        ORJDatabase const   *database;
        ORJError            error;
        ORJRC               rc  =   ORJ_ReadDatabase(jarName, NULL, flags, &database, &error);

        if(0 != rc)
        {
            printf("Error in %s, at line %u, column %u\n", jarName, error.invalidLine, error.invalidColumn);
        }
        else
        {
            size_t  iRecord;

#if 0 /* Change this to 1 to exercise the database via structure members, rather than via API functions */
            printf("Record-JAR %s has %d lines in %d fields in %d records\n", jarName, database->numLines, database->numFields, database->numRecords);

            for(iRecord = 0; iRecord < database->numRecords; ++iRecord)
            {
                size_t      iField;
                ORJRecordA  *record =   &database->records[iRecord];

                if( NULL != record->comment.ptr &&
                    0 != record->comment.len)
                {
                    printf("record-#%u; %.*s (%u fields)\n", iRecord, record->comment.len, record->comment.ptr, record->numFields);
                }
                else
                {
                    printf("record-#%d (%d fields)\n", iRecord, record->numFields);
                }

                for(iField = 0; iField < record->numFields; ++iField)
                {
                    ORJFieldA   *field  =   &record->fields[iField];

                    printf("  field-#%d [%.*s]:[%.*s]\n", iField, field->name.len, field->name.ptr, field->value.len, field->value.ptr);
                }
            }
#else /* ? 0 */
            printf("Record-JAR %s has %ld lines in %ld fields in %ld records\n", jarName, (long)ORJ_Database_GetNumLinesA(database), (long)ORJ_Database_GetNumFieldsA(database), (long)ORJ_Database_GetNumRecordsA(database));

            for(iRecord = 0; iRecord < ORJ_Database_GetNumRecordsA(database); ++iRecord)
            {
                size_t              iField;
                ORJRecordA const    *record;
                ORJStringA const    *comment;

                ORJ_Database_GetRecordA(database, iRecord, &record);

                if( ORJ_RC_SUCCESS == ORJ_Record_GetCommentA(record, &comment) &&
                    0 != comment->len)
                {
                    printf("record-#%ld; %.*s (%ld fields)\n", (long)iRecord, (int)comment->len, comment->ptr, (long)ORJ_Record_GetNumFieldsA(record));
                }
                else
                {
                    printf("record-#%ld (%ld fields)\n", (long)iRecord, (long)ORJ_Record_GetNumFieldsA(record));
                }

                for(iField = 0; iField < ORJ_Record_GetNumFieldsA(record); ++iField)
                {
                    ORJFieldA const     *field;
                    ORJFieldA const     *field2;
                    ORJStringA const    *name;
                    ORJStringA const    *value;

                    ORJ_Record_GetFieldA(record, iField, &field);

                    ORJ_Field_GetNameAndValueA(field, &name, &value);

                    printf("  field-#%ld [%.*s]:[%.*s]\n", (long)iField, (int)field->name.len, field->name.ptr, (int)field->value.len, field->value.ptr);

                    /* Now do a check to verify that the ORJ_Record_FindFieldByNameA() method works! */

                    field2  =   ORJ_Record_FindFieldByNameA(record, name->ptr, value->ptr);

                    if(field != field2)
                    {
                        fprintf(stderr, "** Field mismatch!! **\n");
                    }
                }
            }
#endif /* 0 */

            ORJ_FreeDatabase(database);
        }
    }

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Worker functions
 */

#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca             __builtin_alloca
#elif defined(WIN32)
# include <malloc.h>
# ifndef alloca
#  define alloca            _alloca
# endif /* !alloca */
#else /* ? OS */
# include <alloca.h>
#endif /* OS */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    /* Get the executable name */
    char    *EXE_NAME   =   strcpy((char*)alloca(1 + strlen(argv[0])), argv[0]);
    char    *p;

    if(NULL != (p = strrchr(EXE_NAME, '\\')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    if(NULL != (p = strrchr(EXE_NAME, '/')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }


    fprintf(stderr, "\n");
    fprintf(stderr, "  Open-RJ C test program: %s\n", EXE_NAME);
    fprintf(stderr, "\n");

    if(NULL != reason)
    {
        fprintf(stderr, "  Error: %s\n", reason);
        fprintf(stderr, "\n");
    }

    if(0 < invalidArg)
    {
        int i;

        fprintf(stderr, "  First invalid argument #%d: %s\n", invalidArg, argv[invalidArg]);
        fprintf(stderr, "  Arguments were (first bad marked *):\n\n");
        for(i = 1; i < argc; ++i)
        {
            fprintf(stderr, "  %s%s\n", (i == invalidArg) ? "* " : "  ", argv[i]);
        }
        fprintf(stderr, "\n");
    }

    fprintf(stderr, "  USAGE 1: %s [-o] [-s] <database>\n\n", EXE_NAME);
    fprintf(stderr, "    -o            -   orders the fields within each record\n");
    fprintf(stderr, "    -s            -   elide blank records from the database\n");
    fprintf(stderr, "    <database>    -   the Open-RJ database file\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "    Converts the <input-file> to the <output-file> by either\n");
    fprintf(stderr, "    Base-64 encoding (-e) or Base-64 decoding (-d)\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  USAGE 2: %s --unittest\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Runs internal tests, returning 0 if all succeed, non-0 otherwise\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  USAGE 3: %s -?\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Displays this help\n");
    fprintf(stderr, "\n");

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

static int execute_unittest(ORJDatabaseA const *database)
{
    ((void)database);

    /* NOTE: Not yet implemented */

    return 0;
}

static int run_unittests()
{
    int iRes    =   EXIT_SUCCESS;
    int i;

    i = run_unittest1();

    if( EXIT_SUCCESS == iRes &&
        EXIT_SUCCESS != i)
    {
        iRes = i;
    }

    i = run_unittest2();

    if( EXIT_SUCCESS == iRes &&
        EXIT_SUCCESS != i)
    {
        iRes = i;
    }

    return iRes;
}

static int run_unittest1()
{
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
#if !defined(__GNUC__)
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
#endif /* compiler */
        "Name:      Sparky\n"
        "Species:   Cat\n"
        "%%\n";
#if !defined(__GNUC__)
    static const size_t NUM_RECORDS =   12;
    static const size_t NUM_FIELDS  =   25;
#else /* ?  compiler */
    static const size_t NUM_RECORDS =   9;
    static const size_t NUM_FIELDS  =   16;
#endif /* compiler */

    /* 1. Test that *not* eliding blanks gives the right number of records */
    {
        ORJDatabase const   *database;
        ORJError            error;
        const unsigned      flags   =   0;
        ORJRC               rc      =   ORJ_CreateDatabaseFromMemoryA(&contents[0], sizeof(contents), NULL, flags, &database, &error);

        if(0 != rc)
        {
            fprintf(stderr, "Error in at line %u, column %u\n", error.invalidLine, error.invalidColumn);

            return EXIT_FAILURE;
        }
        else
        {
            int iRet = 0;

            if(NUM_RECORDS != database->numRecords)
            {
                fprintf(stderr, "Incorrect number of records\n");

                iRet = 1;
            }
            else if(NUM_FIELDS != database->numFields)
            {
                fprintf(stderr, "Incorrect number of fields\n");

                iRet = 1;
            }
            else
            {
                const int   NUM_TESTS   =   1000;
                int         i;

                for(i = 0; i < NUM_TESTS; ++i)
                {
                    iRet = execute_unittest(database);

                    if(0 != iRet)
                    {
                        break;
                    }
                }

                if(0 == iRet)
                {
                    fprintf(stderr, "%d tests succeeded\n", NUM_TESTS);
                }
                else
                {
                    fprintf(stderr, "Test #%d failed\n", i);
                }
            }

            ORJ_FreeDatabase(database);

            return (0 == iRet) ? EXIT_SUCCESS : EXIT_FAILURE;
        }
    }
}

static int run_unittest2()
{
    static const char   contents[] =

        "%% Sample Open-RJ database - Cats and Dogs\n"
        "%% Created:   28th September 2004\n"
        "%% Updated:   29th September 2004\n"
        "Name:      Barney\n"
        "Species:   Dog\n"
        "Breed:     Bijon \\\n"
        "           Frieze\n"
        "%%\n"
        "  : \n"
        "Species:   Cat\n"
        "    :\n"
        "    : \n"
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
        "Name:      Sparky\n"
        "Species:   Cat\n"
        "%%\n";

    /* 1. Test that the incorrectly formed (empty) field name causes parsing to return an error */
    {
        ORJDatabase const   *database;
        ORJError            error;
        const unsigned      flags       =   0;
        ORJRC               rc          =   ORJ_CreateDatabaseFromMemoryA(&contents[0], sizeof(contents), NULL, flags, &database, &error);
        const unsigned      errorLine   =   8;

        if( ORJ_RC_PARSEERROR != rc ||
            error.parseError != ORJ_PARSE_INVALIDFIELDNAME)
        {
            fprintf(stderr, "Failed to detect format error in contents!\n");

            return EXIT_FAILURE;
        }
        else if(errorLine != error.invalidLine)
        {
            fprintf(stderr, "Failed to detect location of format error in contents. Expected line %d; actual line %d\n", errorLine, error.invalidLine);

            return EXIT_FAILURE;
        }
        else
        {
            return EXIT_SUCCESS;
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
