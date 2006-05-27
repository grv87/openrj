/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_stl_1.cpp
 *
 * Purpose:     C++ example program for the Open-RJ/STL mapping. Demonstrates
 *              enumeration of all non-empty records and their fields, via.
 *              subscript operators.
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
#include <openrj/stl/database.hpp>

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
    "Name:      Sparky\n"
    "Species:   Cat\n"
    "%%\n";

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char * /* argv */[])
{
    try
    {
        unsigned                        flags   =   0;  // No special flags here.
        openrj::stl::memory_database    db(&contents[0], sizeof(contents), flags);

        cout    << "Database has " 
                << db.num_lines() << " lines in " 
                << db.num_fields() << " fields in "
                << db.num_records() << " records"
                << endl;

        cout << endl << "Enumerate records and their fields using subscript operators:" << endl;

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

                cout << "    field-#" << iField << ": " << field << endl;
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
