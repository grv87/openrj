/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_cpp_6.cpp
 *
 * Purpose:     C++ example program for the Open-RJ/C++ mapping. Demonstrates
 *              enumeration of all non-empty records and their fields, with
 *              use of processing instructions.
 *
 * Created:     12th May 2006
 * Updated:     28th May 2006
 *
 * www:         http://www.openrj.org/
 *
 * License:     Copyright (c) 2006, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* Open-RJ Header Files */
#include <openrj/cpp/database.hpp>

/* Standard C++ Library Files */
#include <iostream>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

using std::cerr;
using std::endl;
using std::cout;

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

// Sample database
static const char   contents[] =

    "%% Sample Open-RJ database - Cats and Dogs\n"
    "%% Created:   28th September 2004\n"
    "%% Updated:   29th September 2004\n"
    "_OpenRJ.Field.Alias:   1:Name\n"
    "_OpenRJ.Field.Alias:   2:Species\n"
    "_OpenRJ.Field.Alias:   3:Breed\n"
    "%%\n"
    "1:  Barney\n"
    "2:  Dog\n"
    "3:  Bijon \\\n"
    "    Frieze\n"
    "%%\n"
    "1:  Elsa\n"
    "2:  Dog\n"
    "3:  Mixed\n"
    "%%\n"
    "1:  Fluffy Kitten\n"
    "2:  Cat\n"
    "%%\n"
    "1:  Moet\n"
    "2:  Dog\n"
    "3:  Boxer\n"
    "%%\n"
    "1:  Rebel\n"
    "2:  Dog\n"
    "3:  German \\\n"
    "    Shepherd\n"
    "%%\n"
    "1:  Sparky\n"
    "2:  Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char * /* argv */[])
{
    try
    {
        unsigned                        flags   =   0;
        openrj::cpp::MemoryDatabase     db(&contents[0], sizeof(contents), flags);

        cout    << "Database has " 
                << db.GetNumLines() << " lines in " 
                << db.GetNumFields() << " fields in "
                << db.GetNumRecords() << " records"
                << endl;

        cout << endl << "Enumerate records and their fields using subscript operators:" << endl;

        { for(size_t iRecord = 0; iRecord < db.GetNumRecords(); ++iRecord)
        {
            openrj::cpp::Record record(db[iRecord]);

            cout    << "record-#" << iRecord
                    << " " << record.GetComment() << " "
                    << " (" << record.GetNumFields() << " fields)"
                    << endl;

            for(size_t iField = 0; iField < record.GetNumFields(); ++iField)
            {
                openrj::cpp::Field  field(record[iField]);
                std::string         name    =   field.GetName();
                std::string         value   =   field.GetValue();

                cout << "  field-#" << iField << ": " << field << endl;
            }
        }}
    }
    catch(std::exception &x)
    {
        cerr << "Failed to open database: " << x.what() << endl;
    }

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
