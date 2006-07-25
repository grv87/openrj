/* /////////////////////////////////////////////////////////////////////////////
 * File:    OpenRJException.cpp
 *
 * Purpose: Implementation file for OpenRJ::Database class
 *
 * Created: 3rd August 2004
 * Updated: 12th June 2006
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "OpenrjException.h"

#define STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/string/char_traits.hpp>

#include <windows.h>

/* ////////////////////////////////////////////////////////////////////////// */

char *_strcpy(char *dest, char const *src)
{
    char    *ret    =   dest;
    size_t  len     =   ::stlsoft::char_traits<char>::length(src);

    ::stlsoft::char_traits<char>::copy(dest, src, len);
    dest[len] = '\0';

    return ret;
}

char *_strcat(char *dest, char const *src)
{
    size_t  len =   ::stlsoft::char_traits<char>::length(dest);

    _strcpy(dest + len, src);

    return dest;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
/*  
    public:
        String          *ToString();

    private:
        ::openrj::ORJRC     m_rc;
        ::openrj::ORJError  m_error;
        String              *m_message;
*/


    OpenRJException::OpenRJException(String *message)
        : parent_class_type(message)
    {}

} // namespace OpenRJ

namespace OpenRJ
{
    DatabaseException::DatabaseException(::openrj::ORJRC rc, ::openrj::ORJError err)
        : m_rc(rc)
        , m_error(err)
        , parent_class_type(NULL)
    {}

    DatabaseException::DatabaseException(String *message, ::openrj::ORJRC rc, ::openrj::ORJError err)
        : m_rc(rc)
        , m_error(err)
        , parent_class_type(message)
    {}

    Database::ErrorCode DatabaseException::get_ErrorCode()
    {
        return (Database::ErrorCode)m_rc;
    }

    Database::ParseErrorCode DatabaseException::get_ParseError()
    {
        return (Database::ParseErrorCode)m_error.parseError;
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
        String  *message    =   parent_class_type::get_Message();

        if(NULL != message)
        {
            return message;
        }
        else if(::openrj::ORJ_RC_PARSEERROR == m_rc)
        {
            char                sz[2048]    =   "";
#if 1
            char                num[21];

            static const char   _1[]        =   "Parse error in jar file: ";
            static const char   _2[]        =   ", line ";
            static const char   _3[]        =   ", column ";

            _strcpy(&sz[0], _1);
            _strcat(&sz[0], ::openrj::ORJ_GetParseErrorStringA(m_error.parseError));
            _strcat(&sz[0], _2);
            _strcat(&sz[0], ::stlsoft::integer_to_string(&num[0], stlsoft_num_elements(num), m_error.invalidLine));
            _strcat(&sz[0], _3);
            _strcat(&sz[0], ::stlsoft::integer_to_string(&num[0], stlsoft_num_elements(num), m_error.invalidColumn));

            int                 cch         =   ::stlsoft::char_traits<char>::length(&sz[0]);
#else /* ? 0 */
            int     cch =   ::wsprintfA(sz
                                    ,   "Parse error in jar file: %s, line %d, column %d"
                                    ,   ::openrj::ORJ_GetParseErrorStringA(m_error.parseError)
                                    ,   m_error.invalidLine
                                    ,   m_error.invalidColumn);
#endif /* 0 */

            return new String(sz, 0, cch);
        }
        else
        {
            return new String(::openrj::ORJ_GetErrorStringA(m_rc));
        }
    }

} // namespace OpenRJ

namespace OpenRJ
{
    UnknownFieldNameException::UnknownFieldNameException(String *fieldName)
        : m_fieldName(fieldName)
        , parent_class_type(String::Concat("Unknown field name: \"", fieldName, "\""))
    {}

    UnknownFieldNameException::UnknownFieldNameException(String *fieldName, String *message)
        : m_fieldName(fieldName)
        , parent_class_type(message)
    {}

    String* UnknownFieldNameException::get_FieldName()
    {
        return m_fieldName;
    }

} // namespace OpenRJ

/* ////////////////////////////////////////////////////////////////////////// */
