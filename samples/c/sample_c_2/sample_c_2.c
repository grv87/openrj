/* /////////////////////////////////////////////////////////////////////////////
 * File:        sample_c_2.c
 *
 * Purpose:     C sample program for the Open-RJ library.
 *
 * Created:     11th June 2004
 * Updated:     13th May 2006
 *
 * www:         http://www.openrj.org/
 *
 * Thanks:      To Rajiv Bhagwat for pointing out that the test programs left
 *              much to be desired in terms of discoverability.
 *
 * License:     Copyright (c) 2004-2006, Synesis Software Pty Ltd.
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
                usage(1, "Invalid argument(s) specified", i, argc, argv);
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

            printf("Record-JAR %s has %u lines in %u fields in %u records\n", jarName, (unsigned)database->numLines, (unsigned)database->numFields, (unsigned)database->numRecords);

            for(iRecord = 0; iRecord < database->numRecords; ++iRecord)
            {
                size_t      iField;
                ORJRecordA  *record =   &database->records[iRecord];

                if( NULL != record->comment.ptr &&
                    0 != record->comment.len)
                {
                    printf("record-#%u; %.*s (%u fields)\n", (unsigned)iRecord, (int)record->comment.len, record->comment.ptr, (unsigned)record->numFields);
                }
                else
                {
                    printf("record-#%d (%u fields)\n", (unsigned)iRecord, (unsigned)record->numFields);
                }

                for(iField = 0; iField < record->numFields; ++iField)
                {
                    ORJFieldA   *field  =   &record->fields[iField];

                    printf("  field-#%u [%.*s]:[%.*s]\n", (unsigned)iField, (int)field->name.len, field->name.ptr, (int)field->value.len, field->value.ptr);
                }
            }

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

    fprintf(stderr, "  USAGE 1: %s [-i] [-o] [-s] <database>\n\n", EXE_NAME);
    fprintf(stderr, "    -i            -   ignore case when looking up fields\n");
    fprintf(stderr, "    -o            -   orders the fields within each record\n");
    fprintf(stderr, "    -s            -   elide blank records from the database\n");
    fprintf(stderr, "    <database>    -   the Open-RJ database file\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "    Converts the <input-file> to the <output-file> by either\n");
    fprintf(stderr, "    Base-64 encoding (-e) or Base-64 decoding (-d)\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  USAGE 2: %s -?\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Displays this help\n");
    fprintf(stderr, "\n");

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
