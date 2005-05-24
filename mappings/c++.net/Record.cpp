/* /////////////////////////////////////////////////////////////////////////////
 * File:        Record.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Record class
 *
 * Created:     3rd August 2004
 * Updated:     18th February 2005
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

#include "Record.h"
#include "Field.h"
#include "Database.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
	Record::Record(::openrj::ORJRecordA const *record, ::OpenRJ::Database *database)
		: m_record(record)
		, m_database(database)
		, m_fields(new ArrayList(record->numFields))
	{
		::openrj::ORJFieldA const	*begin	=	&record->fields[0];
		::openrj::ORJFieldA const	*end	=	&record->fields[record->numFields];

		for(; begin != end; ++begin)
		{
			m_fields->Add(new Field(begin, this));
		}
	}

	int Record::get_NumFields()
	{
		return m_record->numFields;
	}

	::OpenRJ::Database *Record::get_Database()
	{
		return m_database;
	}

	::OpenRJ::Field *Record::get_Item(int index)
	{
		if(	index < 0 ||
			!(index < get_NumFields()))
		{
			throw new IndexOutOfRangeException();
		}

		return static_cast<Field*>(m_fields->get_Item(index));
	}

// TODO: Show how, when using the String* returning form (using new String(pField->value.ptr, 0, pField->value.len);)
// that it confuses the C# client. :-(

#ifdef INDEXER_RETURNS_STRING
	String *Record::get_Item(String *fieldName)
#else /* ? INDEXER_RETURNS_STRING */
	::OpenRJ::Field *Record::get_Item(String *fieldName)
#endif /* INDEXER_RETURNS_STRING */
	{
		::openrj::ORJFieldA const	*pField =	::openrj::ORJ_Record_FindFieldByNameA(m_record, ::dotnetstl::c_string_accessor<char>(fieldName), NULL);

		if(NULL == pField)
		{
			throw new IndexOutOfRangeException();
		}

		// Now find our internal field that is pointing to that
		Field	*field	=	NULL;

		for(int i = 0; i < m_fields->get_Count(); ++i)
		{
			Field	*field2	=	static_cast<Field*>(m_fields->get_Item(i));

			if(field2->m_field == pField)
			{
				field = field2;
				break;
			}
		}

		if(NULL == field)
		{
			throw new IndexOutOfRangeException("Unexpected condition");
		}

#ifdef INDEXER_RETURNS_STRING
		return new String(pField->value.ptr, 0, pField->value.len);
#else /* ? INDEXER_RETURNS_STRING */
		return field;
#endif /* INDEXER_RETURNS_STRING */
	}

	IEnumerator *Record::GetEnumerator()
	{
		return new ::dotnetstl::ArrayListEnumerator(m_fields);
	}

	String *Record::ToString()
	{
//		String	*s =

		return "";
	}
}

/* ////////////////////////////////////////////////////////////////////////// */
