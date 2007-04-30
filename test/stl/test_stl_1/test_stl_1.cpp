/* /////////////////////////////////////////////////////////////////////////////
 * File:        STL_full.cpp
 *
 * Purpose:     C++ test program for the Open-RJ/STL (the STL mapping of the
 *              Open-RJ library).
 *
 * Created:     18th June 2004
 * Updated:     22nd April 2007
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
 * Enable this to use a memory_database, rather than a file_database on the file
 * specified in the command-line.
 *
 */
/* #define USE_MEMORY_DATABASE */   

/* 2. USE_STD_EXCEPTION_ONLY
 *
 * Enable this to catch any exceptions from the API via std::exception rather
 * than openrj::stl::database_exception.
 */
/* #define USE_STD_EXCEPTION_ONLY */   


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
static int  run_unittests();
static int  execute_unittest(openrj::stl::database_base const &database);

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

#ifndef USE_MEMORY_DATABASE
    if(NULL == jarName)
    {
        usage(1, "Must specify a JAR name", -1, argc, argv);
    }
    else
#endif /* !USE_MEMORY_DATABASE */
    {
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

            // 1. Create a database instance on memory, using openrj::stl::memory_database

            cout << endl << "1. Create a database instance on memory, using openrj::stl::memory_database" << endl << endl;

            openrj::stl::memory_database    db(&contents[0], sizeof(contents), flags);

#else /* ? USE_MEMORY_DATABASE */

            // 1. Create a database instance on file, using openrj::stl::file_database

            cout << endl << "1. Create a database instance on file, using openrj::stl::file_database" << endl << endl;

            openrj::stl::file_database      db(jarName, flags);

#endif /* USE_MEMORY_DATABASE */

            // 2. Display database characteristics

            cout << endl << "2. Display database characteristics:" << endl << endl;

#ifdef USE_MEMORY_DATABASE
            cout    << "  Database has " 
#else /* ? USE_MEMORY_DATABASE */
            cout    << "  Database \"" << jarName << "\" has " 
#endif /* USE_MEMORY_DATABASE */
                    << db.num_lines() << " lines in " 
                    << db.num_fields() << " fields in "
                    << db.num_records() << " records"
                    << endl;

            // 3. Enumerate the contents using subscript operators

            cout << endl << "3. Enumerate records and their fields using subscript operators:" << endl << endl;

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

                    cout << "    field-#" << iField << field << endl;
                }
            }}

            // 4. Enumerate the contents using begin()/end() methods

            cout << endl << "4. Enumerate records and their fields using begin()/end() methods:" << endl << endl;

            {   openrj::stl::database::const_iterator   b   =   db.begin();
                openrj::stl::database::const_iterator   e   =   db.end();

                for(size_t iRecord = 0; b != e; ++b, ++iRecord)
            {
                openrj::stl::record record(*b);

                cout    << "  record-#" << iRecord
                        << " " << record.comment() << " "
                        << " (" << record.size() << " fields)"
                        << endl;

                if(record.has_field("Name"))
                {
                    openrj::stl::string_t   value       =   record["Name"];

                    cout << "    This record has a \"Name\" field, whose value is " << value << endl;

                    size_t                  numNames    =   record.count_fields("Name");

                    STLSOFT_SUPPRESS_UNUSED(numNames);
                }

                {   openrj::stl::record::const_iterator b   =   record.begin();
                    openrj::stl::record::const_iterator e   =   record.end();

                    for(size_t iField = 0; b != e; ++b, ++iField)
                    {
                        openrj::stl::field  field(*b);
                        std::string         name    =   field.name();
                        std::string         value   =   field.value();

                        cout << "    field-#" << iField << " " << field << endl;
                }}
            }}

#ifdef STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
            // 5. Enumerate the contents in reverse using rbegin()/rend() methods

            cout << endl << "5. Enumerate the contents in reverse using rbegin()/rend() methods:" << endl << endl;

            {   openrj::stl::database::const_reverse_iterator   b   =   db.rbegin();
                openrj::stl::database::const_reverse_iterator   e   =   db.rend();

                for(size_t iRecord = 0; b != e; ++b, ++iRecord)
            {
                openrj::stl::record record(*b);

                cout    << "  record-#" << iRecord
                        << " " << record.comment() << " "
                        << " (" << record.size() << " fields)"
                        << endl;

                if(record.has_field("Name"))
                {
                    openrj::stl::string_t   value       =   record["Name"];

                    cout << "    This record has a \"Name\" field, whose value is " << value << endl;

                    size_t                  numNames    =   record.count_fields("Name");

                    STLSOFT_SUPPRESS_UNUSED(numNames);
                }

                {   openrj::stl::record::const_reverse_iterator b   =   record.rbegin();
                    openrj::stl::record::const_reverse_iterator e   =   record.rend();

                    for(size_t iField = 0; b != e; ++b, ++iField)
                    {
                        openrj::stl::field  field(*b);
                        std::string         name    =   field.name();
                        std::string         value   =   field.value();

                        cout << "    field-#" << iField << " " << field << endl;
                }}
            }}
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
            // 6. Enumerate all fields in the database using begin()/end() methods

            cout << endl << "6. Enumerate all fields in the database using begin()/end() methods:" << endl << endl;

            std::copy(db.fields_begin(), db.fields_end(), std::ostream_iterator<openrj::stl::field>(std::cout, "\n"));

# ifdef STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
            // 7. Enumerate all fields in the database in reverse using rbegin()/rend() methods

            cout << endl << "7. Enumerate all fields in the database in reverse using rbegin()/rend() methods:" << endl << endl;

            cout << endl << "All fields (in reverse order):" << endl;
            std::copy(db.fields_rbegin(), db.fields_rend(), std::ostream_iterator<openrj::stl::field>(std::cout, "\n"));
# endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */

        }
#ifdef USE_STD_EXCEPTION_ONLY
        catch(std::exception &x)
        {
            cerr << "Failed to open database: " << x.what() << endl;
        }
#else /* ? USE_STD_EXCEPTION_ONLY */
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
#endif /* USE_STD_EXCEPTION_ONLY */
    }

#if !defined(STLSOFT_COMPILER_IS_MSVC)
    STLSOFT_SUPPRESS_UNUSED(execute_unittest);
#endif /* compiler */

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

static int execute_unittest(openrj::stl::database_base const &database)
{
    /* 1. Check that the database thinks it has the same number of total
     * fields as the total of each record
     */
    size_t  numFields1  =   database.num_fields();
    size_t  numFields2  =   0;

    { for(size_t i = 0; i < database.num_records(); ++i)
    {
        numFields2 += database[i].size();
    }}

    if(numFields1 != numFields2)
    {
        fprintf(stderr, "DatabaseBase::GetNumFields(): %ld; n x Record::GetNumFields(): %ld\n", static_cast<long>(numFields1), static_cast<long>(numFields2));

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
    try
    {
        openrj::stl::memory_database    database(&contents[0], sizeof(contents), 0);

        int iRet = 0;

        if(NUM_RECORDS != database.num_records())
        {
            fprintf(stderr, "Incorrect number of records\n");

            iRet = 1;
        }
        else if(NUM_FIELDS != database.num_fields())
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
