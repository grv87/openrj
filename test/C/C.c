/* /////////////////////////////////////////////////////////////////////////////
 * File:        C.c
 *
 * Purpose:     Implementation file for the C project.
 *
 * Created:     11th June 2004
 * Updated:     19th February 2005
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


/* Open-RJ Header Files */
#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

/* Standard C Library Files */
#include <stdio.h>
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
 * Helper function declarations
 */

static void			usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);
static int			run_unittests(void);
//static char const	*find_exe_name(char const *arg0);

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

//static char const	*EXE_NAME	=	"";

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    int         i;
	char const	*jarName	=	NULL;
	unsigned	flags		=	0;

//	EXE_NAME = find_exe_name(argv[0]);

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
						flags |= ORJ_FLAG_ORDERFIELDS;
						break;
					case	's':
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
		ORJDatabase const	*database;
		ORJError			error;
		ORJRC				rc	=	ORJ_ReadDatabase(jarName, NULL, flags, &database, &error);

		if(0 != rc)
		{
			printf("Error in %s, at line %u, column %u\n", jarName, error.invalidLine, error.invalidColumn);
		}
		else
		{
			size_t	iRecord;

#if 0
			printf("Record-JAR %s has %d lines in %d fields in %d records\n", jarName, database->numLines, database->numFields, database->numRecords);

			for(iRecord = 0; iRecord < database->numRecords; ++iRecord)
			{
				size_t		iField;
				ORJRecordA	*record	=	&database->records[iRecord];

				printf("record-#%d (%d records)\n", iRecord, record->numFields);

				for(iField = 0; iField < record->numFields; ++iField)
				{
					ORJFieldA	*field	=	&record->fields[iField];

					printf("  field-#%d [%.*s]:[%.*s]\n", iField, field->name.end - field->name.begin, field->name.begin, field->value.end - field->value.begin, field->value.begin);
				}
			}
#else /* ? 0 */
			printf("Record-JAR %s has %u lines in %u fields in %u records\n", jarName, ORJ_Database_GetNumLinesA(database), ORJ_Database_GetNumFieldsA(database), ORJ_Database_GetNumRecordsA(database));

			for(iRecord = 0; iRecord < ORJ_Database_GetNumRecordsA(database); ++iRecord)
			{
				size_t				iField;
				ORJRecordA const	*record;

				ORJ_Database_GetRecordA(database, iRecord, &record);

				openrj_assert(NULL != record);

				printf("record-#%u (%u records)\n", iRecord, ORJ_Record_GetNumFieldsA(record));

				for(iField = 0; iField < ORJ_Record_GetNumFieldsA(record); ++iField)
				{
					ORJFieldA const		*field;
					ORJStringA const	*name;
					ORJStringA const	*value;

					ORJ_Record_GetFieldA(record, iField, &field);

					ORJ_Field_GetNameAndValueA(field, &name, &value);

					printf("  field-#%u [%.*s]:[%.*s]\n", iField, (int)field->name.len, field->name.ptr, (int)field->value.len, field->value.ptr);
				}
			}
#endif /* 0 */

			ORJ_FreeDatabase(database);
		}
	}

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    // Get the executable name
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

#if 0
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
#endif /* 0 */

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
