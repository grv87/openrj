/* /////////////////////////////////////////////////////////////////////////////
 * File:        FileDatabase.cpp
 *
 * Purpose:     Implementation file for OpenRJ::FileDatabase class
 *
 * Created:     3rd August 2004
 * Updated:     15th January 2005
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, 2004-2005. All rights reserved.
 *
 * Home:        http://www.openrj.orj/
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
		::openrj::ORJDatabaseA const	*database;
		::openrj::ORJError				error;
		::openrj::ORJRC					rc	=	::openrj::ORJ_ReadDatabaseA(path, GetAllocator(), flags, &database, &error);

		if(::openrj::ORJ_RC_SUCCESS != rc)
		{
			// throw something here
			throw new DatabaseException(rc, error);
		}

		return database;
	}

	FileDatabase::FileDatabase(String *path, unsigned int flags)
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
