/* /////////////////////////////////////////////////////////////////////////////
 * File:        Field.h
 *
 * Purpose:     Definition of the Field class
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
	public __gc class Record;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
	using namespace System;

	public __gc __sealed class Field
	{
	/// \name Construction
	/// @{
	private public:
		Field(::openrj::ORJFieldA const *field, ::OpenRJ::Record *record);
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

	/// \name Members
	/// @{
	public private:
		::openrj::ORJFieldA const	*m_field;
	private:
		::OpenRJ::Record			*m_record;
	/// @}
	};
}

/* ////////////////////////////////////////////////////////////////////////// */
