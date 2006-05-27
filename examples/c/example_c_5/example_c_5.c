/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_c_5.c
 *
 * Purpose:     C example program for the Open-RJ core library. Demonstrates
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
#include <openrj/openrj.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ////////////////////////////////////////////////////////////////////////// */

int main()
{
    unsigned            flags   =   0;
    ORJDatabase const   *db;
    ORJError            error;
    ORJRC               rc;

    /* 1. Create a database instance on memory, so use memory_database */
    rc = ORJ_ReadDatabase("|i|n|v|a|l|i|d|n|a|m|e|", NULL, flags, &db, &error);

    if(0 != rc)
    {
        char    message[1001];

        fprintf(stdout, "Display the error manually:\n");
        fprintf(stderr, "  Error at line %ld, column %ld: %s\n", (long)error.invalidLine, (long)error.invalidColumn, ORJ_GetErrorStringA(rc));

        fprintf(stdout, "Display the error using ORJ_FormatErrorA():\n");
        ORJ_FormatErrorA(&message[0], sizeof(message) / sizeof(0[message]), rc, &error, "  Error code %d means: %E\n", (int)rc);
        fprintf(stderr, message);

        return EXIT_FAILURE;
    }
    else
    {
        /* Finally, free the database */
        ORJ_FreeDatabase(db);
    }

    return EXIT_SUCCESS;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */
