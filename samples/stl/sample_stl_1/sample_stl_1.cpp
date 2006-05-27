/* /////////////////////////////////////////////////////////////////////////////
 * File:        sample_stl_1.cpp
 *
 * Purpose:     C++ test program for the Open-RJ/STL (the STL mapping of the
 *              Open-RJ library).
 *
 * Created:     18th June 2004
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
#include <openrj/stl/database.hpp>

/* Standard C++ Library Files */
#include <iostream>

/* Standard C Library Files */
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

using std::cerr;
using std::endl;
using std::cout;

/* /////////////////////////////////////////////////////////////////////////////
 * Helper function declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char *argv[])
{
    int         i;
    char const  *jarName    =   NULL;
    unsigned    flags       =   0;

    /* Parse the command-line arguments, to specify the . */
    for(i = 1; i < argc; ++i)
    {
        const char  *arg    =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                /* -- arguments */
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
                        flags |= openrj::IGNORE_CASE_ON_LOOKUP;
                        break;
                    case    'o':
                        flags |= openrj::ORDER_FIELDS;
                        break;
                    case    's':
                        flags |= openrj::ELIDE_BLANK_RECORDS;
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
        try
        {
            openrj::stl::file_database  db(jarName, flags);

            cout    << "  Database has " 
                    << db.num_lines() << " lines in " 
                    << db.num_fields() << " fields in "
                    << db.num_records() << " records"
                    << endl;

            { for(size_t iRecord = 0; iRecord < db.size(); ++iRecord)
            {
                openrj::stl::record record(db[iRecord]);

                cout    << "  record-#" << iRecord
                        << " " << record.comment() << " "
                        << " (" << record.size() << " fields)"
                        << endl;

                for(size_t iField = 0; iField < record.size(); ++iField)
                {
                    openrj::stl::field  field(record[iField]);
                    std::string         name    =   field.name();
                    std::string         value   =   field.value();

                    cout << "    field-#" << iField << " " << field << endl;
                }
            }}

        }
        catch(openrj::stl::database_exception &x)
        {
            openrj::ORJRC   rc = x.rc();

            if(0 != rc)
            {
                switch(rc)
                {
                    case    openrj::ORJ_RC_CANNOTOPENJARFILE:
                        cout << "Cannot open file: " << jarName << "" << endl;
                        break;
                    case    openrj::ORJ_RC_PARSEERROR:
                        cout    << "Error in " << jarName
                                << ", at line " << x.error().invalidLine
                                << ", column " << x.error().invalidColumn
                                << "; " << stlsoft::c_str_ptr(x.error().parseError)
                                << "" << endl;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
#if 0
    { for(size_t i = 0; i < 0xFFFFFFFF; ++i) {} }
#endif /* 0 */

    try
    {
        return main_(argc, argv);
    }
    catch(std::exception &x)
    {
        cerr << "Unhandled error: " << x.what() << endl;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;
    }

    return EXIT_FAILURE;
}

/* ////////////////////////////////////////////////////////////////////////// */

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

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[])
{
    char    *EXE_NAME   =   strcpy(static_cast<char*>(alloca(1 + strlen(argv[0]))), argv[0]);
    char    *p;

    if(NULL != (p = strrchr(EXE_NAME, '\\')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    if(NULL != (p = strrchr(EXE_NAME, '/')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    cerr << "" << endl;
    cerr << "  Open-RJ STL test program: " << EXE_NAME << endl;;
    cerr << "" << endl;

    stlsoft_assert(invalidArg < argc);

    if(NULL != reason)
    {
        cerr << "  Error: " << reason << "" << endl;
        cerr << "" << endl;
    }

    if(0 < invalidArg)
    {
        cerr << "  First invalid argument #" << invalidArg << ": " << argv[invalidArg] << endl;
        cerr << "  Arguments were (first bad marked *):" << endl << endl;
        for(int i = 1; i < argc; ++i)
        {
            cerr << "  " << ((i == invalidArg) ? "* " : "  ") << argv[i] << endl;
        }
        cerr << "" << endl;
    }

    cerr << "  USAGE 1: " << EXE_NAME << " [-o] [-s] <database>" << endl;
    cerr << "" << endl;
    cerr << "    -o            -   orders the fields within each record" << endl;
    cerr << "    -s            -   elide blank records from the database" << endl;
    cerr << "    <database>    -   the Open-RJ database file" << endl;
    cerr << "" << endl;
    cerr << "    Converts the <input-file> to the <output-file> by either" << endl;
    cerr << "    Base-64 encoding (-e) or Base-64 decoding (-d)" << endl;
    cerr << "" << endl;
    cerr << "  USAGE 2: " << EXE_NAME << " -?" << endl;
    cerr << "" << endl;
    cerr << "    Displays this help" << endl;
    cerr << "" << endl;

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
