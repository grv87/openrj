/* /////////////////////////////////////////////////////////////////////////////
 * File:    orjstr.c
 *
 * Purpose: Provides (English) string mappings for errors
 *
 * Created: 26th July 2004
 * Updated: 3rd March 2005
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


/* \file orjstr.c Provides (English) string mappings for errors
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_C_ORJMEM_MAJOR      1
# define OPENRJ_VER_C_ORJMEM_MINOR      0
# define OPENRJ_VER_C_ORJMEM_REVISION   4
# define OPENRJ_VER_C_ORJMEM_EDIT       6
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
/* #include <openrj/openrj_assert.h> */
/* #include <openrj/openrj_memory.h> */

#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifndef NUM_ELEMENTS
# define NUM_ELEMENTS(x)    (sizeof(x) / sizeof((x)[0]))
#endif /* !NUM_ELEMENTS */

/* ////////////////////////////////////////////////////////////////////////// */

#ifdef OPENRJ_DOCUMENTATION_SKIP_SECTION
struct ErrorString
#else /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
typedef struct ErrorString  ErrorString;
struct ErrorString
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
{
    int         errorCode;
    char const  *errorString;
};


static const ErrorString    errors[] =
{
/*[OPENRJ:Errors-start]*/
        {   ORJ_RC_SUCCESS              ,   "Operation was successful"                                   }
    ,   {   ORJ_RC_CANNOTOPENJARFILE    ,   "The given file does not exist, or cannot be accessed"       }
    ,   {   ORJ_RC_NORECORDS            ,   "The database file contained no records"                     }
    ,   {   ORJ_RC_OUTOFMEMORY          ,   "The API suffered memory exhaustion"                         }
    ,   {   ORJ_RC_BADFILEREAD          ,   "A read operation failed"                                    }
    ,   {   ORJ_RC_PARSEERROR           ,   "Parsing of the database file failed due to a syntax error"  }
    ,   {   ORJ_RC_INVALIDINDEX         ,   "An invalid index was specified"                             }
    ,   {   ORJ_RC_UNEXPECTED           ,   "An unexpected condition was encountered"                    }
    ,   {   ORJ_RC_INVALIDCONTENT       ,   "The database file contained invalid content"                }
/*[OPENRJ:Errors-end]*/
};

static const ErrorString    parseErrors[] =
{
/*[OPENRJ:ParseErrors-start]*/
        {   ORJ_PARSE_SUCCESS                       ,   "Parsing was successful"                                                            }
    ,   {   ORJ_PARSE_RECORDSEPARATORINCONTINUATION ,   "A record separator was encountered during a content line continuation"             }
    ,   {   ORJ_PARSE_UNFINISHEDLINE                ,   "The last line in the database was not terminated by a line-feed"                   }
    ,   {   ORJ_PARSE_UNFINISHEDFIELD               ,   "The last field in the database file was not well-formed"                           }
    ,   {   ORJ_PARSE_UNFINISHEDRECORD              ,   "The last record in the database file was not terminated by a record separator"     }
/*[OPENRJ:ParseErrors-end]*/
};

static char const *ORJ_LookupErrorStringA_(int error, ErrorString const *mappings, size_t cMappings)
{
    size_t  i;

    for(i = 0; i < cMappings; ++i)
    {
        if(error == mappings[i].errorCode)
        {
            return mappings[i].errorString;
        }
    }

    return "";
}

ORJ_CALL(char const *) ORJ_GetErrorStringA( /* [in] */ ORJRC            errorCode)
{
    return ORJ_LookupErrorStringA_((int)errorCode, &errors[0], NUM_ELEMENTS(errors));
}

ORJ_CALL(char const *) ORJ_GetParseErrorStringA( /* [in] */ ORJ_PARSE_ERROR errorCode)
{
    return ORJ_LookupErrorStringA_((int)errorCode, &parseErrors[0], NUM_ELEMENTS(parseErrors));
}

/* ////////////////////////////////////////////////////////////////////////// */
