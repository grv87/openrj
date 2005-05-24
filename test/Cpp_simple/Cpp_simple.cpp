/* /////////////////////////////////////////////////////////////////////////////
 * File:        Cpp_simple.cpp
 *
 * Purpose:     C++ test program for the Open-RJ/C++ (the C++ mapping of the
 *              Open-RJ library). This program uses the memory_database class
 *              and attempts to be a smallest-possible informative example.
 *
 * Created:     24th May 2005
 * Updated:     25th May 2005
 *
 * www:         http://www.openrj.org/
 *
 * Thanks:      To Rajiv Bhagwat for pointing out that the test programs left
 *              much to be desired in terms of discoverability.
 *
 * License:     Copyright 2005, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2005
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

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char * /* argv */[])
{
    try
    {
        // 1. Create a database instance on memory, so use memory_database

        unsigned                        flags   =   0;  // No special flags here.
        openrj::cpp::MemoryDatabase     db(&contents[0], sizeof(contents), flags);

        // 2. Display database characteristics

        cout << endl << "2. Display database characteristics:" << endl;

        cout    << "Database has " 
                << db.GetNumLines() << " lines in " 
                << db.GetNumFields() << " fields in "
                << db.GetNumRecords() << " records"
                << endl;

        // 3. Enumerate the contents using subscript operators

        cout << endl << "3. Enumerate records and their fields using subscript operators:" << endl;

        { for(size_t iRecord = 0; iRecord < db.GetNumRecords(); ++iRecord)
        {
            openrj::cpp::Record record(db[iRecord]);

            cout    << "record-#" << iRecord
                    << " " << record.GetComment() << " "
                    << " (" << db.GetNumRecords() << " fields)"
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
