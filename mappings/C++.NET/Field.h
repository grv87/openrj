// OpenRJ.h

#pragma once

#include "OpenRJ.h"

namespace OpenRJ
{
	public __gc class Record;
	public __gc class Database;
}

namespace OpenRJ
{
	using namespace System;

	public __gc class Field
	{
	/// \name Construction
	/// @{
	private public:
		Field(::openrj::ORJFieldA const *field, ::OpenRJ::Record *record, ::OpenRJ::Database *database)
			: m_field(field)
			, m_record(record)
			, m_database(database)
		{}

	/// @}

	/// \name Properties
	/// @{
	public:
		/// The name of the field
		__property String			*get_Name();
		/// The value of the field
		__property String			*get_Value();

		/// The record within which this field resides
		__property ::OpenRJ::Record	*get_Record();

		/// Converts the field to a string form
		String						*ToString();
		
	/// @}

	public private:
		::openrj::ORJFieldA const	*m_field;
	private:
		::OpenRJ::Record			*m_record;
		::OpenRJ::Database			*m_database;
	};
}
