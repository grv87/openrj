// Database.h

#pragma once

#include "OpenRJ.h"

namespace OpenRJ
{
	public __gc class Field;
	public __gc class Record;
}

namespace OpenRJ
{
	using namespace System;
	using System::Collections::ArrayList;
	using System::Collections::IEnumerable;
	using System::Collections::IEnumerator;

	[System::Reflection::DefaultMemberAttribute("Item")]
	/// \brief This class represents the Open-RJ database file, once read in and parsed
	public __gc class Database
//		: public IDisposable
	{
	/// \name Construction
	/// @{
	public:
		Database(String *path, unsigned int flags);
		~Database();
	/// @}

	/// \name Operations
	/// @{
	private:
		void Close();
	protected:
		void Dispose();
	/// @}

	/// \name Properties
	/// @{
	public:
		/// The path of the database
		__property String			*get_Path();
		/// The number of lines in the database
		__property int				get_NumLines();
		/// The number of fields in the database
		__property int				get_NumFields();
		/// The number of records in the database
		__property int				get_NumRecords();

		/// Enumerate the records in the database
		IEnumerator					*GetEnumerator();

		/// Access the records by index
		__property virtual Record	*get_Item(int index);

		/// Converts the database to a string form
		String						*ToString();
	/// @}

	private:
		::openrj::ORJDatabaseA const	*m_database;
		ArrayList						*m_records;
	};
}
