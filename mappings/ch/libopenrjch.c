/* /////////////////////////////////////////////////////////////////////////////
 * File:    libopenrjch.c
 *
 * Purpose: Implementation file for the Open-RJ - Ch mapping
 *
 * Created: 7th August 2004
 * Updated: 25th May 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/** \file libopenrjch.c Implementation file for the Open-RJ - Ch mapping
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <ch.h>
#include <openrj/openrj.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

EXPORTCH ORJRC ORJ_ReadDatabaseA_chdl(void *arg_)
{
    va_list             ap;
    ORJRC               retVal;
    char const          *jarName;
    IORJAllocator       *ator;
    unsigned            flags;
    ORJDatabaseA const  **pdatabase;
    ORJError            *error;

    Ch_VaStart(ap, arg_);

    jarName     =       Ch_VaArg(ap, char const*);
    ator        =       Ch_VaArg(ap, IORJAllocator*);
    flags       =       Ch_VaArg(ap, unsigned);
    pdatabase   =       Ch_VaArg(ap, ORJDatabaseA const**);
    error       =       Ch_VaArg(ap, ORJError*);

    Ch_VaEnd(ap);

    retVal = ORJ_ReadDatabaseA(jarName, ator, flags, pdatabase, error);

    return retVal;
}

EXPORTCH ORJRC ORJ_CreateDatabaseFromMemoryA_chdl(void *arg_)
{
    va_list             ap;
    ORJRC               retVal;
    char const          *contents;
    size_t              cbContents;
    IORJAllocator       *ator;
    unsigned            flags;
    ORJDatabaseA const  **pdatabase;
    ORJError            *error;

    Ch_VaStart(ap, arg_);

    contents    =       Ch_VaArg(ap, char const*);
    cbContents  =       Ch_VaArg(ap, size_t);
    ator        =       Ch_VaArg(ap, IORJAllocator*);
    flags       =       Ch_VaArg(ap, unsigned);
    pdatabase   =       Ch_VaArg(ap, ORJDatabaseA const**);
    error       =       Ch_VaArg(ap, ORJError*);

    Ch_VaEnd(ap);

    retVal = ORJ_CreateDatabaseFromMemoryA(contents, cbContents, ator, flags, pdatabase, error);

    return retVal;
}

EXPORTCH ORJRC ORJ_FreeDatabaseA_chdl(void *arg_)
{
    va_list             ap;
    ORJRC               retVal;
    ORJDatabaseA const  *database;

    Ch_VaStart(ap, arg_);

    database    =       Ch_VaArg(ap, ORJDatabaseA const*);

    Ch_VaEnd(ap);

    retVal = ORJ_FreeDatabaseA(database);

    return retVal;
}

EXPORTCH char const *ORJ_GetErrorStringA_chdl(void *arg_)
{
    va_list     ap;
    char const  *retVal;
    ORJRC       rc;

    Ch_VaStart(ap, arg_);

    rc  =       Ch_VaArg(ap, ORJRC);

    Ch_VaEnd(ap);

    retVal = ORJ_GetErrorStringA(rc);

    return retVal;
}

EXPORTCH char const *ORJ_GetParseErrorStringA_chdl(void *arg_)
{
    va_list         ap;
    char const      *retVal;
    ORJ_PARSE_ERROR rc;

    Ch_VaStart(ap, arg_);

    rc  =       Ch_VaArg(ap, ORJ_PARSE_ERROR);

    Ch_VaEnd(ap);

    retVal = ORJ_GetParseErrorStringA(rc);

    return retVal;
}

EXPORTCH ORJFieldA const *ORJ_Record_FindFieldByNameA_chdl(void *arg_)
{
    va_list             ap;
    ORJFieldA const     *retVal;
    ORJRecordA const    *record;
    char const          *fieldName;
    char const          *fieldValue;

    Ch_VaStart(ap, arg_);

    record      =   Ch_VaArg(ap, ORJRecordA const*);
    fieldName   =   Ch_VaArg(ap, char const*);
    fieldValue  =   Ch_VaArg(ap, char const*);

    Ch_VaEnd(ap);

    retVal = ORJ_Record_FindFieldByNameA(record, fieldName, fieldValue);

    return retVal;
}

EXPORTCH ORJDatabaseA const *ORJ_Record_GetDatabaseA_chdl(void *arg_)
{
    va_list             ap;
    ORJDatabaseA const  *retVal;
    ORJRecordA const    *record;

    Ch_VaStart(ap, arg_);

    record  =       Ch_VaArg(ap, ORJRecordA const*);

    Ch_VaEnd(ap);

    retVal = ORJ_Record_GetDatabaseA(record);

    return retVal;
}

EXPORTCH ORJRecordA const *ORJ_Field_GetRecordA_chdl(void *arg_)
{
    va_list             ap;
    ORJRecordA const    *retVal;
    ORJFieldA const     *field;

    Ch_VaStart(ap, arg_);

    field   =       Ch_VaArg(ap, ORJFieldA const*);

    Ch_VaEnd(ap);

    retVal = ORJ_Field_GetRecordA(field);

    return retVal;
}

/* ////////////////////////////////////////////////////////////////////////// */
