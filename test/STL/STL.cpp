/* /////////////////////////////////////////////////////////////////////////////
 * File:        STL.cpp
 *
 * Purpose:     Implementation file for the STL project.
 *
 * Created:     18th June 2004
 * Updated:     29th September 2004
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (C) 1999-2004, Synesis Software Pty Ltd.
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

static void			usage(int bExit, char const *reason);
static char const	*find_exe_name(char const *arg0);

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

static char const	*EXE_NAME	=	"";

/* ////////////////////////////////////////////////////////////////////////// */

int main_(int argc, char *argv[])
{
    int         i;
	char const	*jarName	=	NULL;
	unsigned	flags		=	0;

	EXE_NAME = find_exe_name(argv[0]);

#if 0
	Sleep(100000);
#endif /* 0 */

	for(i = 1; i < argc; ++i)
	{
		const char	*arg	=	argv[i];

		if(arg[0] == '-')
		{
			switch(arg[1])
			{
				case	'?':
					usage(1, NULL);
					break;
				case	'o':
					flags |= openrj::ORJ_FLAG_ORDERFIELDS;
					break;
				case	's':
					flags |= openrj::ORJ_FLAG_ELIDEBLANKRECORDS;
					break;
				default:
					usage(1, "Invalid argument(s) specified");
					break;
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
				usage(1, "Invalid argument(s) specified");
			}
		}
	}

	if(NULL == jarName)
	{
		usage(1, "Must specify a JAR name");
	}
	else
	{
		try
		{
			openrj::stl::database	db(jarName, flags);

			cout << "Record-JAR " << jarName << " has " << db.num_lines() << " lines in " << db.num_fields() << " fields in " << db.num_records() << " records" << endl;

			cout << endl << "Records and their fields:" << endl;
#if 0
			for(size_t iRecord = 0; iRecord < db.size(); ++iRecord)
			{
				openrj::stl::record	record(db[iRecord]);

				cout << "record-#" << iRecord << " (" << db.size() << " records)" << endl;

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

				cout << "record-#" << iRecord << " (of " << db.size() << " records)" << endl;

				if(record.has_field("Name"))
				{
					openrj::stl::string_t	value = record["Name"];

					cout << "This record has a \"Name\" field, whose value is " << value << endl;
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

#if !defined(__DMC__)
			cout << endl << "All fields:" << endl;
			std::copy(db.fields_begin(), db.fields_end(), std::ostream_iterator<openrj::stl::field>(std::cout, "\n"));
#endif /* __DMC__ */

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

static void usage(int bExit, char const *reason)
{
    cerr << "" << endl;
    cerr << "  Open-RJ C++ test client" << endl << endl;

	if(NULL != reason)
	{
	    cerr << "  " << reason << "" << endl << endl;
	}

    cerr << "" << endl;
	cerr << "  USAGE: " << EXE_NAME << " [-o] [-s] <database>" << endl;
    cerr << "" << endl;
	cerr << "  Options:" << endl;
	cerr << "    -o            -   orders the fields within each record" << endl;
	cerr << "    -s            -   elide blank records from the database" << endl;
	cerr << "    <database>    -   the Open-RJ database file" << endl;
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

static char const *find_exe_name(char const *arg0)
{
	char const	*slash	=	strrchr(arg0, '/');

#ifdef WIN32
	char const	*bs	=	strrchr(arg0, '\\');

	if(NULL == slash)
	{
		slash = bs;
	}
	else if(NULL != slash &&
			NULL != bs &&
			slash < bs)
	{
		slash = bs;
	}
#endif /* WIN32 */

	if(NULL == slash)
	{
		return arg0;
	}
	else
	{
		return slash + 1;
	}
}

/* ////////////////////////////////////////////////////////////////////////// */
