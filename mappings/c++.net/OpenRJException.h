/* /////////////////////////////////////////////////////////////////////////////
 * File:        OpenRJException.h
 *
 * Purpose:     Definition of the OpenRJ::Database class
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
 * Classes
 */

namespace OpenRJ
{
	using namespace System;
	using System::ApplicationException;

	public __gc class DatabaseException
		: public ApplicationException
	{
	public:
		DatabaseException(::openrj::ORJRC rc, ::openrj::ORJError err);

	public:
		::OpenRJ::RC	get_ErrorCode();
		PARSE_ERROR		get_ParseError();
		int				get_ParseLine();
		int				get_ParseColumn();

	public:
		String			*ToString();

	private:
		::openrj::ORJRC		m_rc;
		::openrj::ORJError	m_error;
	};
}

/* ////////////////////////////////////////////////////////////////////////// */
