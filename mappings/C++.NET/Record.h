// Record.h

#pragma once

#include "OpenRJ.h"

namespace OpenRJ
{
	public __gc class Field;
	public __gc class Database;
}

namespace OpenRJ
{
	using namespace System;
	using System::Collections::ArrayList;
	using System::Collections::IEnumerable;
	using System::Collections::IEnumerator;

	[System::Reflection::DefaultMemberAttribute("Item")]
	public __gc class Record
	{
	private:
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
		__property virtual Field		*get_Item(int index);
		__property virtual Field		*get_Item(String *fieldName);

		/// Converts the record to a string form
		String							*ToString();
		
	/// @}

	private:
		::openrj::ORJRecordA const	*m_record;
		::OpenRJ::Database			*m_database;
		ArrayList					*m_fields;
	};
}
