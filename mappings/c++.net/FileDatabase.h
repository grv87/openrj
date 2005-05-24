/* /////////////////////////////////////////////////////////////////////////////
 * File:        FileDatabase.h
 *
 * Purpose:     Definition of the FileDatabase class
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
	public __gc class FileDatabase
		: public Database
	{
	/// \name Construction
	/// @{
	public:
		FileDatabase(String *path, unsigned int flags);
	/// @}

	/// \name Properties
	/// @{
	public:
		/// The path of the database
		__property String	*get_Path();
		/// Converts the database to a string form
		String				*ToString();
	/// @}

	/// \name Implementation
	/// @{
	private:
		static ::openrj::ORJDatabaseA const *create_database_(char const *path, unsigned int flags);
	/// @}

	/// \name Members
	/// @{
	private:
		String	*m_path;
	/// @}
	};
}

/* ////////////////////////////////////////////////////////////////////////// */
