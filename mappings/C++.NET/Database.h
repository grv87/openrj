/* /////////////////////////////////////////////////////////////////////////////
 * File:        Database.h
 *
 * Purpose:     Definition of the Database class
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
	public __gc class Record;
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
	/// \brief This class represents the Open-RJ database file, once read in and parsed
	public __gc class Database
//		: public IDisposable
	{
	/// \name Construction
	/// @{
	protected:
		Database(::openrj::ORJDatabaseA const *database);
	public:
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
	/// @}

	/// \name Members
	/// @{
	private:
		::openrj::ORJDatabaseA const	*m_database;
		ArrayList						*m_records;
	/// @}
	};
}

/* ////////////////////////////////////////////////////////////////////////// */
