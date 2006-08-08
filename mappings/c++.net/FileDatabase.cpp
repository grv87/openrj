/* /////////////////////////////////////////////////////////////////////////////
 * File:    FileDatabase.cpp
 *
 * Purpose: Implementation file for OpenRJ::FileDatabase class
 *
 * Created: 3rd August 2004
 * Updated: 24th May 2006
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "FileDatabase.h"
#include "Record.h"
#include "OpenRJException.h"
#include "OpenRJUtil.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
    namespace
    {
        void *_fnAlloc(::openrj::IORJAllocator * /* m */, size_t cb)
        {
            return (void*)System::Runtime::InteropServices::Marshal::AllocHGlobal(cb);
        }
        void *_fnRealloc(::openrj::IORJAllocator * /* m */, void *pv, size_t cb)
        {
            return (void*)System::Runtime::InteropServices::Marshal::ReAllocHGlobal(pv, (System::IntPtr)(void*)cb);
        }
        void _fnFree(::openrj::IORJAllocator * /* m */, void *pv)
        {
            System::Runtime::InteropServices::Marshal::FreeHGlobal(pv);
        }
    }

    /* static */ ::openrj::ORJDatabaseA const *FileDatabase::create_database_(char const *path, unsigned flags)
    {
        ::openrj::ORJDatabaseA const    *database;
        ::openrj::ORJError              error;
        ::openrj::ORJRC                 rc  =   ::openrj::ORJ_ReadDatabaseA(path, GetAllocator(), flags, &database, &error);

        if(::openrj::ORJ_RC_SUCCESS != rc)
        {
            if(::openrj::ORJ_RC_CANNOTOPENJARFILE == rc)
            {
                String  *message    =   String::Concat( new String(::openrj::ORJ_GetErrorStringA(rc), 0, ::openrj::ORJ_GetErrorStringLengthA(rc))
                                                    ,   ": "
                                                    ,   path);

                throw new DatabaseException(message, rc, error);
            }
            else
            {
                throw new DatabaseException(rc, error);
            }
        }

        return database;
    }

    FileDatabase::FileDatabase(String *path) // flags == Flags::ElideBlankRecords
		: Database(create_database_(::dotnetstl::c_string_accessor<char>(path), Database::Flags::ElideBlankRecords))
        , m_path(path)
    {}

    FileDatabase::FileDatabase(String *path, Flags flags)
        : Database(create_database_(::dotnetstl::c_string_accessor<char>(path), flags))
        , m_path(path)
    {}

    String *FileDatabase::get_Path()
    {
        return m_path;
    }

    String *FileDatabase::ToString()
    {
        return String::Concat(new String("Open-RJ Database; path="), get_Path());
    }
}

/* ////////////////////////////////////////////////////////////////////////// */
