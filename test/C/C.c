/* /////////////////////////////////////////////////////////////////////////////
 * File:        C.c
 *
 * Purpose:     Implementation file for the C project.
 *
 * Created:     11th June 2004
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


/* Open-RJ Header Files */
#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
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
					flags |= ORJ_FLAG_ORDERFIELDS;
					break;
				case	's':
					flags |= ORJ_FLAG_ELIDEBLANKRECORDS;
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

static void usage(int bExit, char const *reason)
{
    fprintf(stderr, "\n");
    fprintf(stderr, "  Open-RJ C test client\n\n");

	if(NULL != reason)
	{
	    fprintf(stderr, "  %s\n\n", reason);
	}

    fprintf(stderr, "\n");
	fprintf(stderr, "  USAGE: %s [-o] [-s] <database>\n", EXE_NAME);
    fprintf(stderr, "\n");
	fprintf(stderr, "  Options:\n");
	fprintf(stderr, "    -o            -   orders the fields within each record\n");
	fprintf(stderr, "    -s            -   elide blank records from the database\n");
	fprintf(stderr, "    <database>    -   the Open-RJ database file\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  USAGE 2: %s -?\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "    Displays this help\n");
    fprintf(stderr, "\n");

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
