// Implementation file for OpenRJ::Database class

#include "stdafx.h"

#include "OpenrjException.h"

#include <windows.h>

//int __cdecl wsprintfA(char *, char const *, ...);

namespace OpenRJ
{
	DatabaseException::DatabaseException(::openrj::ORJRC rc, ::openrj::ORJError err)
		: m_rc(rc)
		, m_error(err)
	{}

	::OpenRJ::RC DatabaseException::get_ErrorCode()
	{
		return ErrAsEnum(m_rc);
	}

	PARSE_ERROR DatabaseException::get_ParseError()
	{
		return ErrAsEnum(m_error.parseError);
	}

	int DatabaseException::get_ParseLine()
	{
		return m_error.invalidLine;
	}

	int DatabaseException::get_ParseColumn()
	{
		return m_error.invalidColumn;
	}

	String *DatabaseException::ToString()
	{
		if(::openrj::ORJ_RC_PARSEERROR == m_rc)
		{
			char	sz[2048];
//#define	wsprintfA	sprintf
			int		cch	=	wsprintfA(sz, "Parse error in jar file: %s, line %d, column %d", ::openrj::ORJ_GetParseErrorStringA(m_error.parseError), m_error.invalidLine, m_error.invalidColumn);

			return new String(sz, 0, cch);
		}
		else
		{
			return new String(::openrj::ORJ_GetErrorStringA(m_rc));
		}
	}
}
