/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_cpp_2.cpp
 *
 * Purpose:     C++ example program for the Open-RJ/C++ mapping. Demonstrates
 *              searching for fields in records.
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

int main()
{
    try
    {
        unsigned                        flags   =   openrj::ELIDE_BLANK_RECORDS | openrj::IGNORE_CASE_ON_LOOKUP;
        openrj::cpp::MemoryDatabase     db(&contents[0], sizeof(contents), flags);

        cout    << "Database has " 
                << db.GetNumLines() << " lines in " 
                << db.GetNumFields() << " fields in "
                << db.GetNumRecords() << " records"
                << endl;

        cout << endl << "Searching for records in the database that have a \"Breed\" field:" << endl;

        { for(size_t iRecord = 0; iRecord < db.GetNumRecords(); ++iRecord)
        {
            openrj::cpp::Record record(db[iRecord]);

            if(!record.HasField("BREED"))
            {
                cout << "record does not contain a field called \"Breed\"" << endl;
            }
            else
            {
                cout    << "  record-#" << iRecord
                        << " " << record.GetComment() << " "
                        << " (" << record.GetNumFields() << " fields)"
                        << endl;

                cout    << "    " << "Name=" << record["Name"] << endl;
                cout    << "    " << "Species=" << record["Species"] << endl;
                cout    << "    " << "Breed=" << record["Breed"] << endl;
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
