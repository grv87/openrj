/* /////////////////////////////////////////////////////////////////////////////
 * File:        Database.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Database class
 *
 * Created:     3rd August 2004
 * Updated:     17th January 2005
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

#include "Database.h"
#include "Record.h"
#include "OpenRJException.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
	Database::Database(::openrj::ORJDatabaseA const *database)
		: m_database(database)
		, m_records(NULL)
	{
		m_records	=	new ArrayList(m_database->numRecords);

		::openrj::ORJRecordA const	*begin	=	&m_database->records[0];
		::openrj::ORJRecordA const	*end	=	&m_database->records[m_database->numRecords];

		for(; begin != end; ++begin)
		{
			m_records->Add(new Record(begin, this));
		}
	}

	Database::~Database()
	{
		Close();
	}

	void Database::Close()
	{
		if(NULL != m_database)
		{
			::openrj::ORJ_FreeDatabaseA(m_database);

			m_database = NULL;
		}
	}

	void Database::Dispose()
	{
		Close();
	}

	int Database::get_NumLines()
	{
		return m_database->numLines;
	}

	int Database::get_NumFields()
	{
		return m_database->numFields;
	}

	int Database::get_NumRecords()
	{
		return m_database->numRecords;
	}

	IEnumerator *Database::GetEnumerator()
	{
		return new ::dotnetstl::ArrayListEnumerator(m_records);
	}

	Record *Database::get_Item(int index)
	{
		if(	index < 0 ||
			!(index < get_NumRecords()))
		{
			throw new IndexOutOfRangeException();
		}

		return static_cast<Record*>(m_records->get_Item(index));
	}
}

/* ////////////////////////////////////////////////////////////////////////// */
