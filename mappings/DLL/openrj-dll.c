/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj-dll.c
 *
 * Purpose: DLL implementation file for the Open-RJ library
 *
 * Created: 23rd June 2004
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


/** \file orjapi.c DLL implementation file for the Open-RJ library
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#define OPENRJ_PURE_API

#include <openrj/openrj.h>
#include <windows.h>

#include "MBldHdr.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#define SYDLLVER_PLATFORM_WINDOWS       0x00000001      /* Windows 9x */
#define SYDLLVER_PLATFORM_NT            0x00000002      /* Windows NT */

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#define _mccVerHi       OPENRJ_VER_MAJOR
#define _mccVerLo       OPENRJ_VER_MINOR
#define _mccBldNum      OPENRJ_VER_REVISION
#define _mccPlatform    SYDLLVER_PLATFORM_WINDOWS

/* /////////////////////////////////////////////////////////////////////////////
 * Entry points
 */

int WINAPI DllMain( HINSTANCE   hinst
                ,   DWORD       reason
                ,   LPVOID      lpReserved)
{
    ((void)hinst);
    ((void)reason);
    ((void)lpReserved);

    return TRUE;
}


typedef struct tagDllVersionInfo
{
    DWORD   cbSize;
    DWORD   dwMajorVersion;
    DWORD   dwMinorVersion;
    DWORD   dwBuildNumber;
    DWORD   dwPlatformID;
}   DllVersionInfo;

HRESULT CALLBACK DllGetVersion(DllVersionInfo *pvi)
{
    HRESULT                 hr;
    static DllVersionInfo   s_verinfo =
    {
        sizeof(s_verinfo),
        _mccVerHi,
        _mccVerLo,
        _mccBldNum,
        _mccPlatform
    };

    if(!pvi)
    {
        hr = E_POINTER;
    }
    else if(pvi->cbSize != s_verinfo.cbSize)
    {
        hr = E_INVALIDARG;
    }
    else
    {
        *pvi = s_verinfo;

        hr = S_OK;
    }

    return hr;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Synthesise the inline API functions here, so they're available for loading
 */

ORJ_CALL(size_t) ORJ_Database_GetNumLinesA(/* [in] */ ORJDatabaseA const *database)
{
    return database->numLines;
}

ORJ_CALL(size_t) ORJ_Database_GetNumFieldsA(/* [in] */ ORJDatabaseA const *database)
{
    return database->numFields;
}

ORJ_CALL(size_t) ORJ_Database_GetNumRecordsA(/* [in] */ ORJDatabaseA const *database)
{
    return database->numRecords;
}

ORJ_CALL(size_t) ORJ_Record_GetNumFieldsA(/* [in] */ ORJRecordA const *record)
{
    return record->numFields;
}

/* ////////////////////////////////////////////////////////////////////////// */
