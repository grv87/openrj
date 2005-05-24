/* /////////////////////////////////////////////////////////////////////////////
 * File:        MemoryDatabase.cpp
 *
 * Purpose:     Implementation file for OpenRJ::MemoryDatabase class
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

#include "MemoryDatabase.h"
#include "Record.h"
#include "OpenRJException.h"
#include "OpenRJUtil.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
	/* static */ ::openrj::ORJDatabaseA const *MemoryDatabase::create_database_(char const *contents, size_t cbContents, unsigned flags)
	{
		::openrj::ORJDatabaseA const	*database;
		::openrj::ORJError				error;
		::openrj::ORJRC					rc	=	::openrj::ORJ_CreateDatabaseFromMemoryA(contents, cbContents, GetAllocator(), flags, &database, &error);

		if(::openrj::ORJ_RC_SUCCESS != rc)
		{
			// throw something here
			throw new DatabaseException(rc, error);
		}

		return database;
	}

	MemoryDatabase::MemoryDatabase(String *contents, unsigned int flags)
		: Database(create_database_(::dotnetstl::c_string_accessor<char>(contents), contents->get_Length(), flags))
	{}

	String *MemoryDatabase::ToString()
	{
		return String::Concat(new String("Open-RJ Database; (memory)"));
	}
}

/* ////////////////////////////////////////////////////////////////////////// */
