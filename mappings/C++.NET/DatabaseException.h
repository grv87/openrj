#pragma once

#include "OpenRJ.h"

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
