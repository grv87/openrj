/* /////////////////////////////////////////////////////////////////////////////
 * File:        STL.cpp
 *
 * Purpose:     Implementation file for the STL project.
 *
 * Created:     18th June 2004
 * Updated:     22nd April 2005
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright 2004-2005, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              email:      software@synesis.com.au
 *
 *              This source code is placed into the public domain 2004
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage.
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission.
 *
 * ////////////////////////////////////////////////////////////////////////// */

#define OPENRJ_STL_ITERATOR_HOLDS_VALUE

/* Open-RJ Header Files */
#include <openrj/stl/openrj.hpp>
#include <openrj/stl/field.hpp>
#include <openrj/stl/record.hpp>
#include <openrj/stl/database.hpp>

/* Standard C++ Library Files */
#include <iostream>

/* Standard C Library Files */
#include <stdlib.h>
#include <string.h>
#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca				__builtin_alloca
#elif defined(WIN32)
# include <malloc.h>
# ifndef alloca
#  define alloca            _alloca
# endif /* !alloca */
#else /* ? OS */
# include <alloca.h>
#endif /* OS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

using std::cerr;
using std::endl;
using std::cout;
#if !defined(ORJ_NO_NAMESPACE)
using openrj::ORJRC;
#endif /* !ORJ_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper function declarations
 */

static void			usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);
static int			run_unittests();

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char *argv[])
{
    int         i;
	char const	*jarName	=	NULL;
	unsigned	flags		=	0;

#if 0
	Sleep(100000);
#endif /* 0 */

	for(i = 1; i < argc; ++i)
	{
		const char	*arg	=	argv[i];

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
					case	'?':
						usage(1, NULL, -1, argc, argv);
						break;
					case	'o':
						flags |= openrj::ORJ_FLAG_ORDERFIELDS;
						break;
					case	's':
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

	if(NULL == jarName)
	{
		usage(1, "Must specify a JAR name", -1, argc, argv);
	}
	else
	{
		try
		{
#if 1
			openrj::stl::database	db(jarName, flags);
#else /* ? 0 */
			static const char	contents[] =

				"%% Sample Open-RJ database - Cats and Dogs\n"
				"%% Created:   28th September 2004\n"
				"%% Updated:   29th September 2004\n"
				"Name:		Barney\n"
				"Species:	Dog\n"
				"Breed:		Bijon \\\n"
				"			Frieze\n"
				"%%\n"
				"Name:		Elsa\n"
				"Species:	Dog\n"
				"Breed:		Mixed\n"
				"%%\n"
				"Name:		Fluffy Kitten\n"
				"Species:	Cat\n"
				"%%\n"
				"Name:		Moet\n"
				"Species:	Dog\n"
				"Breed:		Boxer\n"
				"%%\n"
				"Name:		Rebel\n"
				"Species:	Dog\n"
				"Breed:		German \\\n"
				"			Shepherd\n"
				"%%\n"
				"Name:		Pepper\n"
				"Species:	Dog\n"
				"Breed:		Border Collie\n"
				"%%\n"
				"Name:		Samson\n"
				"Species:	Dog\n"
				"Breed:		Ridgeback\n"
				"%%\n"
				"Name:		Sheltie\n"
				"Species:	Dog\n"
				"Breed:		Shetland \\\n"
				"			Sheepdog\n"
				"%%\n"
				"Name:		Sparky\n"
				"Species:	Cat\n"
				"%%\n";

			openrj::stl::memory_database	db(&contents[0], sizeof(contents), flags);
#endif /* 0 */

			cout << "Record-JAR " << jarName << " has " << db.num_lines() << " lines in " << db.num_fields() << " fields in " << db.num_records() << " records" << endl;

			cout << endl << "Records and their fields:" << endl;
#if 0
			for(size_t iRecord = 0; iRecord < db.size(); ++iRecord)
			{
				openrj::stl::record	record(db[iRecord]);

				cout	<< "record-#" << iRecord
						<< " " << record.comment() << " "
						<< " (" << db.size() << " records)"
						<< endl;

				for(size_t iField = 0; iField < record.size(); ++iField)
				{
					openrj::stl::field	field(record[iField]);
					std::string			name	=	field.name();
					std::string			value	=	field.value();

					cout << "  field-#" << iField << field << endl;
				}
			}
#else /* ? 0 */

			openrj::stl::database::const_iterator	begin	=	db.begin();
			openrj::stl::database::const_iterator	end		=	db.end();

			for(size_t iRecord = 0; begin != end; ++begin, ++iRecord)
			{
				openrj::stl::record	record(*begin);

				cout	<< "record-#" << iRecord
						<< " " << record.comment() << " "
						<< " (of " << db.size() << " records)"
						<< endl;

				if(record.has_field("Name"))
				{
					openrj::stl::string_t	value		=	record["Name"];

					cout << "This record has a \"Name\" field, whose value is " << value << endl;

					size_t					numNames	=	record.count_fields("Name");

					STLSOFT_SUPPRESS_UNUSED(numNames);
				}

				openrj::stl::record::const_iterator	begin	=	record.begin();
				openrj::stl::record::const_iterator	end		=	record.end();

				for(size_t iField = 0; begin != end; ++begin, ++iField)
				{
					openrj::stl::field	field(*begin);
					std::string			name	=	field.name();
					std::string			value	=	field.value();

#if !defined(__STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER > 1200
					cout << "  field-#" << iField << " " << field << endl;
#else /* ? compiler */
					cout << "  field-#" << iField << " " << stlsoft::c_str_ptr(field) << endl;
#endif /* compiler */
				}
			}

#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
			cout << endl << "All fields:" << endl;
			std::copy(db.fields_begin(), db.fields_end(), std::ostream_iterator<openrj::stl::field>(std::cout, "\n"));
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */

#endif /* 0 */
		}
		catch(openrj::stl::database_exception &x)
		{
			ORJRC	rc = x.rc();

			if(0 != rc)
			{
				switch(rc)
				{
					case	openrj::ORJ_RC_CANNOTOPENJARFILE:
						cout << "Cannot open file: " << jarName << "" << endl;
						break;
					case	openrj::ORJ_RC_PARSEERROR:
						cout	<< "Error in " << jarName
								<< ", at line " << x.error().invalidLine
								<< ", column " << x.error().invalidColumn
#if 1
								<< "; " << stlsoft::c_str_ptr(x.error().parseError)
#else /* ? 0 */
								<< "; " << x.error().parseError
#endif /* 0 */
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

static int run_unittests()
{
#if 0
	static const char	contents[] =

		"%% Sample Open-RJ database - Cats and Dogs\n"
		"%% Created:   28th September 2004\n"
		"%% Updated:   29th September 2004\n"
		"Name:		Barney\n"
		"Species:	Dog\n"
		"Breed:		Bijon \\\n"
		"			Frieze\n"
		"%%\n"
		"Name:		Elsa\n"
		"Species:	Dog\n"
		"Breed:		Mixed\n"
		"%%\n"
		"Name:		Fluffy Kitten\n"
		"Species:	Cat\n"
		"%%\n"
		"Name:		Moet\n"
		"Species:	Dog\n"
		"Breed:		Boxer\n"
		"%%\n"
		"Name:		Rebel\n"
		"Species:	Dog\n"
		"Breed:		German \\\n"
		"			Shepherd\n"
		"%%\n"
		"Name:		Pepper\n"
		"Species:	Dog\n"
		"Breed:		Border Collie\n"
		"%%\n"
		"Name:		Samson\n"
		"Species:	Dog\n"
		"Breed:		Ridgeback\n"
		"%%\n"
		"Name:		Sheltie\n"
		"Species:	Dog\n"
		"Breed:		Shetland \\\n"
		"			Sheepdog\n"
		"%%\n"
		"Name:		Sparky\n"
		"Species:	Cat\n"
		"%%\n";

	/* 1. Test that *not* eliding blanks gives the right number of records */
	{
		ORJDatabase const	*database;
		ORJError			error;
		const unsigned		flags	=	0;
		ORJRC				rc		=	ORJ_CreateDatabaseFromMemoryA(&contents[0], sizeof(contents), NULL, flags, &database, &error);

		if(0 != rc)
		{
			fprintf(stderr, "Error in %s, at line %u, column %u\n", jarName, error.invalidLine, error.invalidColumn);

			return EXIT_FAILURE;
		}
		else
		{
			if(12 != database->numRecords)
			{
				fprintf(stderr, "Incorrect number of fieldsError in %s, at line %u, column %u\n", jarName, error.invalidLine, error.invalidColumn);

				goto Error1;
			}
			else if(25 != datebase->numFields)
			{
			}

			if(0)
			{
Error1:
				ORJ_FreeDatabase(database);

				return EXIT_FAILURE;
			}
		}
	}

	ORJDatabase const	*database;
	ORJError			error;
	ORJRC				rc;

	rc = ORJ_CreateDatabaseFromMemoryA(&contents[0], sizeof(contents), NULL, flags, &database, &error);

    const int   NUM_TESTS   =   1000;
    int         iRet        =   0;
    int         i;

#if 0
    srand(&i);
#endif /* 0 */

    for(i = 0; i < NUM_TESTS; ++i)
    {
        iRet = execute_unittest();

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

    return iRet;
#else /* ? 0 */
	return EXIT_SUCCESS;
#endif /* 0 */
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
