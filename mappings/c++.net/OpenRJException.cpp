/* /////////////////////////////////////////////////////////////////////////////
 * File:        OpenRJException.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Database class
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


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "OpenrjException.h"

#define STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS

#include <stlsoft_char_traits.h>
#include <stlsoft_integer_to_string.h>

#include <windows.h>

/* ////////////////////////////////////////////////////////////////////////// */

char *_strcpy(char *dest, char const *src)
{
	char	*ret	=	dest;
	size_t	len		=	::stlsoft::char_traits<char>::length(src);

	::stlsoft::char_traits<char>::copy(dest, src, len);
	dest[len] = '\0';

	return ret;
}

char *_strcat(char *dest, char const *src)
{
	size_t	len	=	::stlsoft::char_traits<char>::length(dest);

	_strcpy(dest + len, src);

	return dest;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

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
			char				sz[2048]	=	"";
#if 1
			char				num[21];

			static const char	_1[]		=	"Parse error in jar file: ";
			static const char	_2[]		=	", line ";
			static const char	_3[]		=	", column ";

			_strcpy(&sz[0], _1);
			_strcat(&sz[0], ::openrj::ORJ_GetParseErrorStringA(m_error.parseError));
			_strcat(&sz[0], _2);
			_strcat(&sz[0], ::stlsoft::integer_to_string(&num[0], stlsoft_num_elements(num), m_error.invalidLine));
			_strcat(&sz[0], _3);
			_strcat(&sz[0], ::stlsoft::integer_to_string(&num[0], stlsoft_num_elements(num), m_error.invalidColumn));

			int					cch			=	::stlsoft::char_traits<char>::length(&sz[0]);
#else /* ? 0 */
			int		cch	=	::wsprintfA(sz
									,	"Parse error in jar file: %s, line %d, column %d"
									,	::openrj::ORJ_GetParseErrorStringA(m_error.parseError)
									,	m_error.invalidLine
									,	m_error.invalidColumn);
#endif /* 0 */

			return new String(sz, 0, cch);
		}
		else
		{
			return new String(::openrj::ORJ_GetErrorStringA(m_rc));
		}
	}
}

/* ////////////////////////////////////////////////////////////////////////// */
