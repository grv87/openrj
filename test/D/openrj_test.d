/* /////////////////////////////////////////////////////////////////////////////
 * File:        openrj_test.d
 *
 * Purpose:     Test program for the D mapping of Open-RJ.
 *
 * Created      14th July 2004
 * Updated:     13th December 2005
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (C) 2004, Matthew Wilson.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2004
 *              by Matthew Wilson. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Matthew Wilson "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Matthew Wilson be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Matthew Wilson nor the names of
 *              any subdivisions, employees or agents of Matthew Wilson, nor the
 *              names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */


import std.gc;
import std.openrj;

/** Program main */
int main(char[][] args)
{
	if(args.length < 2)
	{
		usage();
	}
	else
	{
		char[]		jarName	=	args[1];
		Database	db		=	new Database(jarName);
		char[]		name;
		char[]		value;

		printf("Fields by record:\n");

		foreach(Record record; db)
		{
			printf("record (%d fields)\n", record.length);

			foreach(Field field; record)
			{
				printf("  field: [%.*s]:[%.*s]\n", field.name, field.value);
			}
		}

		printf("All fields:\n");

		foreach(Field field; db.fields())
		{
			printf("  field: [%.*s]:[%.*s]\n", field.name, field.value);

			if(null === name)
			{
				name = field.name;
			}
		}

		name	=	"Year";
		value	=	"2001";
//		value	=	null;

		printf("\nSearching for records containing field with name \"%.*s\" and value \"%.*s\"\n", name, (null === value) ? "" : value);

		foreach(Record record; db.getRecordsContainingField(name, value))
		{
			printf("record %p (%d fields)\n", record, record.length);

			foreach(Field field; record)
			{
				printf("  field: %.*s=%.*s\n", field.name, field.value);
			}
		}

/+ // Enable to observe timely deallocation of the database
		for(int i = 0; i < 10000; ++i)
		{
			std.gc.fullCollect();
		}

		printf("Leaving\n");
+/
	}

	return 0;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Function implementations
 */

private void usage()
{
	printf("USAGE: openrj_test <jarName>\n");
}

/* //////////////////////////////////////////////////////////////////////////
 * End of file
 */
