/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_cpp_4.cpp
 *
 * Purpose:     C++ example program for the Open-RJ/C++ mapping. Demonstrates
 *              handling of a "failure to open file" error.
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

/* ////////////////////////////////////////////////////////////////////////// */

int main()
{
    try
    {
        unsigned                    flags   =   0;  // No special flags here.
        openrj::cpp::FileDatabase   db("|i|n|v|a|l|i|d|n|a|m|e|", flags);

    }
    catch(std::exception &x)
    {
        cerr << "Failed to open database: " << x.what() << endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
