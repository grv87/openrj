/* /////////////////////////////////////////////////////////////////////////////
 * File:        MemoryDatabase.h
 *
 * Purpose:     Definition of the MemoryDatabase class
 *
 * Created:     14th January 2005
 * Updated:     15th January 2005
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, 2005. All rights reserved.
 *
 * Home:        http://www.openrj.orj/
 *
 * ////////////////////////////////////////////////////////////////////////// */

#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "Database.h"

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
	/// \brief This class represents the Open-RJ database file, once read in and parsed
	public __gc class MemoryDatabase
		: public Database
	{
	/// \name Construction
	/// @{
	public:
		MemoryDatabase(String *contents, unsigned int flags);
//		MemoryDatabase(char[] contents, unsigned int flags);
	/// @}

	/// \name Properties
	/// @{
	public:
		/// Converts the database to a string form
		String	*ToString();
	/// @}

	/// \name Implementation
	/// @{
	private:
		static ::openrj::ORJDatabaseA const *create_database_(char const *contents, size_t cbContents, unsigned int flags);
	/// @}

	/// \name Members
	/// @{
	private:
		String	*m_path;
	/// @}
	};
}

/* ////////////////////////////////////////////////////////////////////////// */
