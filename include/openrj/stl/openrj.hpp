/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/openrj.hpp
 *
 * Purpose: Root header file for the STL mapping of the Open-RJ library
 *
 * Created: 28th September 2004
 * Updated: 22nd April 2007
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004-2007, Matthew Wilson and Synesis Software
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


/** \file openrj/stl/openrj.hpp
 *
 * [C++ only] Defines common typedefs and exception types used in the
 *  \link openrj::stl Open-RJ/STL\endlink mapping.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_OPENRJ
#define OPENRJ_INCL_OPENRJ_STL_HPP_OPENRJ

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_MINOR     4
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_REVISION  3
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_EDIT      20
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#ifdef OPENRJ_DOCUMENTATION_SKIP_SECTION
# include <openrj/stl/openrjfwd.hpp>
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */


#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exceptions
#endif /* ORJ_NO_EXCEPTIONS */

#include <stlsoft/stlsoft.h>
#if !defined(_STLSOFT_VER_1_9_1) || \
	_STLSOFT_VER < _STLSOFT_VER_1_9_1
# error Requires STLSoft 1.9.1, or later. (www.stlsoft.org/downloads.html)
#endif /* STLSoft version */

#include <stlsoft/conversion/integer_to_string.hpp>

#include <exception>
#if defined(OPENRJ_USE_CUSTOM_STRING)
# include OPENRJ_CUSTOM_STRING_INCLUDE
#else /* OPENRJ_USE_CUSTOM_STRING */
# include <string>
#endif /* !OPENRJ_USE_CUSTOM_STRING */

#include <string.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef __BORLANDC__
# pragma warn -8027
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
namespace stl
{

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** \brief String type used by the openrj::stl namespace. */
#if defined(OPENRJ_USE_CUSTOM_STRING)
typedef OPENRJ_CUSTOM_STRING_TYPE       string_t;
#else /* OPENRJ_USE_CUSTOM_STRING */
typedef std::string                     string_t;
#endif /* !OPENRJ_USE_CUSTOM_STRING */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief The exception type thrown by the Open-RJ - STL mapping
class database_exception
    : public std::exception
{
/// \name Types
/// @{
public:
    typedef std::exception      parent_class_type;
    typedef database_exception  class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an exception from the given error code and error structure
    database_exception(ORJRC rc, ORJError const &error)
        : m_rc(rc)
        , m_error(error)
        , m_message(create_message_(rc, error))
    {}
#ifdef STLSOFT_COMPILER_IS_GCC
    virtual ~database_exception() throw()
    {}
#endif /* compiler */
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The Open-RJ return code
    ORJRC rc() const
    {
        return m_rc;
    }
    /// \brief The Open-RJ parse error
    ORJError const &error() const
    {
        return m_error;
    }

    /// \brief A string form of the exception error message
    virtual char const *what() const throw()
    {
        return (ORJ_RC_PARSEERROR == m_rc) ? m_message.c_str() : ORJ_GetErrorStringA(m_rc);
    }
/// @}

/// \name Implementation
/// @{
private:
    static string_t create_message_(ORJRC rc, ORJError const &error)
    {
        string_t    s;

        if(ORJ_RC_PARSEERROR == rc)
        {
            char    message[201];
            char    sz1[21];
            char    sz2[21];

            // This was originally all done with string class methods, but it causes a
            // ridiculous number of reallocations, so we do it the old crusty way
            ::strcpy(message, "' at line ");
            ::strcat(message, ::stlsoft::integer_to_string(&sz1[0], stlsoft_num_elements(sz1), error.invalidLine));
            ::strcat(message, " column ");
            ::strcat(message, ::stlsoft::integer_to_string(&sz2[0], stlsoft_num_elements(sz2), error.invalidColumn));

            s   =   "Parse error '";
            s   +=  ORJ_GetParseErrorStringA(error.parseError);
            s   +=  message;
        }

        return s;
    }
/// @}

/// \name Members
/// @{
private:
    ORJRC           m_rc;
    ORJError        m_error;
    const string_t  m_message;
/// @}

// Not to be implemented
private:
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_OPENRJ */

/* ////////////////////////////////////////////////////////////////////////// */
