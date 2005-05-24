/* /////////////////////////////////////////////////////////////////////////////
 * File:        Cpp_full.cpp
 *
 * Purpose:     C++ test program for the Open-RJ/C++ (the C++ mapping of the
 *              Open-RJ library).
 *
 * Created:     15th June 2004
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
 *              This source code is placed into the public domain 2004
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* Customise the test program as follows: */

/* 1. USE_MEMORY_DATABASE
 *
 * Enable this to use a MemoryDatabase, rather than a FileDatabase on the file
 * specified in the command-line.
 *
 */
/* #define USE_MEMORY_DATABASE */   

/* 2. USE_STD_EXCEPTION_ONLY
 *
 * Enable this to catch any exceptions from the API via std::exception rather
 * than openrj::cpp::DatabaseException.
 */
/* #define USE_STD_EXCEPTION_ONLY */   


/* Open-RJ Header Files */
#include <openrj/cpp/database.hpp>

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
static int  run_unittests();
static int  execute_unittest(openrj::cpp::DatabaseBase const &database);

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
                    case    'o':
                        flags |= openrj::ORJ_FLAG_ORDERFIELDS;
                        break;
                    case    's':
                        flags |= openrj::ORJ_FLAG_ELIDEBLANKRECORDS;
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

#ifndef USE_MEMORY_DATABASE
    if(NULL == jarName)
    {
        usage(1, "Must specify a JAR name", -1, argc, argv);
    }
    else
#endif /* !USE_MEMORY_DATABASE */
    {
        /* Here's where the use of the library starts. */

        using namespace openrj::cpp;

        try
        {
#ifdef USE_MEMORY_DATABASE

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

            MemoryDatabase  db(&contents[0], sizeof(contents), flags);

#else /* ? USE_MEMORY_DATABASE */

            FileDatabase    db(jarName, flags);

#endif /* USE_MEMORY_DATABASE */

            cout    << "Record-JAR " << jarName << " has "
                    << db.GetNumLines() << " lines in "
                    << db.GetNumFields() << " fields in "
                    << db.GetNumRecords() << " records"
                    << endl;

            for(size_t iRecord = 0; iRecord < db.GetNumRecords(); ++iRecord)
            {
                size_t  iField;
                Record  record(db[iRecord]);

                cout    << "record-#" << iRecord 
                        << " " << record.GetComment() << " "
                        << " (" << db.GetNumRecords() << " fields)"
                        << endl;

                for(iField = 0; iField < record.GetNumFields(); ++iField)
                {
                    Field       field(record[iField]);
                    char const  *name   =   field.GetName();
                    char const  *value  =   field.GetValue();

                    cout    << "  field-#" << iField << " " << field
                            << " (name=" << name << "; value=" << value << ")"
                            << endl;
                }
            }
        }
#ifdef USE_STD_EXCEPTION_ONLY
        catch(std::exception &x)
        {
            cerr << "Failed to open database: " << x.what() << endl;
        }
#else /* ? USE_STD_EXCEPTION_ONLY */
        catch(openrj::cpp::DatabaseException &x)
        {
            openrj::ORJRC   rc = x.rc();

            if(0 != rc)
            {
                switch(rc)
                {
                    case    openrj::ORJ_RC_CANNOTOPENJARFILE:
                        cerr << "Cannot open file: " << jarName << endl;
                        break;
                    case    openrj::ORJ_RC_PARSEERROR:
                        cerr    << "Error in " << jarName
                                << " at line " << x.error().invalidLine
                                << ", column " << x.error().invalidColumn
                                << "; " <<  stlsoft::c_str_ptr(x.error().parseError)
                                << endl;
                        break;
                    default:
                        break;
                }
            }
        }
#endif /* USE_STD_EXCEPTION_ONLY */
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
#if 0
    Sleep(100000);
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
    cerr << "  Open-RJ C++ test program: " << EXE_NAME << endl;;
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
    cerr << "  USAGE 2: " << EXE_NAME << " --unittest" << endl;
    cerr << "" << endl;
    cerr << "    Runs internal tests, returning 0 if all succeed, non-0 otherwise" << endl;
    cerr << "" << endl;
    cerr << "  USAGE 3: " << EXE_NAME << " -?" << endl;
    cerr << "" << endl;
    cerr << "    Displays this help" << endl;
    cerr << "" << endl;

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

static int execute_unittest(openrj::cpp::DatabaseBase const &database)
{
    /* 1. Check that the database thinks it has the same number of total
     * fields as the total of each record
     */
    size_t  numFields1  =   database.GetNumFields();
    size_t  numFields2  =   0;

    { for(size_t i = 0; i < database.GetNumRecords(); ++i)
    {
        numFields2 += database[i].GetNumFields();
    }}

    if(numFields1 != numFields2)
    {
        fprintf(stderr, "DatabaseBase::GetNumFields(): %lu; n x Record::GetNumFields(): %lu\n", numFields1, numFields2);

        return 1;
    }

    /* NOTE: Other tests not yet implemented */

    return 0;
}

static int run_unittests()
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

    /* 1. Test that *not* eliding blanks gives the right number of records */
    try
    {
        openrj::cpp::MemoryDatabase     database(&contents[0], sizeof(contents), 0);

        int iRet = 0;

        if(12 != database.GetNumRecords())
        {
            fprintf(stderr, "Incorrect number of records\n");

            iRet = 1;
        }
        else if(25 != database.GetNumFields())
        {
            fprintf(stderr, "Incorrect number of fields\n");

            iRet = 1;
        }
        else
        {
            static const int    NUM_TESTS   =   1000;
            int                 i;

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

        return (0 == iRet) ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    catch(std::exception &x)
    {
        cout << "Failed: " << x.what() << endl;

        return EXIT_FAILURE;
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
