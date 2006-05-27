/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_stl_3.cpp
 *
 * Purpose:     C++ example program for the Open-RJ/STL mapping. Demonstrates
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
#include <openrj/stl/database.hpp>
#include <openrj/stl/functional.hpp>

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
        unsigned                        flags   =   0;  // No special flags here.
        openrj::stl::memory_database    db(&contents[0], sizeof(contents), flags);

        cout    << "Database has " 
                << db.num_lines() << " lines in " 
                << db.num_fields() << " fields in "
                << db.num_records() << " records"
                << endl;

        cout << endl << "Searching for records in the database that have a \"Breed\" field:" << endl;

        openrj::stl::database_base::const_iterator   begin   =   db.begin();
        openrj::stl::database_base::const_iterator   end     =   db.end();

        { for(; begin != end; ++begin)
        {
            openrj::stl::record record(*begin);

            if(!record.has_field("BREED"))
            {
                cout << "record does not contain a field called \"Breed\"" << endl;
            }
            else
            {
                cout    << "  record"
                        << " " << record.comment() << " "
                        << " (" << record.size() << " fields)"
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
