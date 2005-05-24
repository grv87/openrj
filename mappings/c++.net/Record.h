/* /////////////////////////////////////////////////////////////////////////////
 * File:        Record.h
 *
 * Purpose:     Definition of the OpenRJ::Record class
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


#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "OpenRJ.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace OpenRJ
{
	public __gc class Field;
	public __gc class Database;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
	using namespace System;
	using System::Collections::ArrayList;
	using System::Collections::IEnumerable;
	using System::Collections::IEnumerator;

	[System::Reflection::DefaultMemberAttribute("Item")]
	public __gc __sealed class Record
	{
	/// \name Construction
	/// @{
	private public:
		Record(::openrj::ORJRecordA const *record, ::OpenRJ::Database *database);
	/// @}

	/// \name Properties
	/// @{
	public:
		/// The number of fields in the record
		__property int					get_NumFields();

		/// The record within which this record resides
		__property ::OpenRJ::Database	*get_Database();

		/// Enumerate the fields in the record
		IEnumerator						*GetEnumerator();

		/// Access the fields by index
		__property Field				*get_Item(int index);
#ifdef INDEXER_RETURNS_STRING
		__property String				*get_Item(String *fieldName);
#else /* ? INDEXER_RETURNS_STRING */
		__property Field				*get_Item(String *fieldName);
#endif /* INDEXER_RETURNS_STRING */

		/// Converts the record to a string form
		String							*ToString();
	/// @}

	/// \name Members
	/// @{
	private:
		::openrj::ORJRecordA const	*m_record;
		::OpenRJ::Database			*m_database;
		ArrayList					*m_fields;
	};
	/// @}
}

/* ////////////////////////////////////////////////////////////////////////// */
