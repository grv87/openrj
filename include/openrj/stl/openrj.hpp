/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/openrj.hpp
 *
 * Purpose: Root header file for the STL mapping of the Open-RJ library
 *
 * Created: 28th September 2004
 * Updated: 23rd May 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
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


/* \file openrj/stl/openrj.hpp Root header file for the C++ mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_OPENRJ
#define OPENRJ_INCL_OPENRJ_STL_HPP_OPENRJ

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_MINOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_REVISION  3
# define OPENRJ_VER_OPENRJ_STL_HPP_OPENRJ_EDIT      10
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exceptions
#endif /* ORJ_NO_EXCEPTIONS */

#include <stlsoft.h>
#include <stlsoft_integer_to_string.h>

#include <exception>
#include <string>

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
/// \brief The Open-RJ STL namespace - \c openrj::stl
///
/// This contains the field, record, file_database and memory_database classes,
/// along with the exception class database_exception
namespace stl
{

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

typedef std::string string_t;

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
#ifdef __STLSOFT_COMPILER_IS_GCC
    virtual ~database_exception() throw()
    {}
#endif /* __STLSOFT_COMPILER_IS_GCC */
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
            strcpy(message, "' at line ");
            strcat(message, ::stlsoft::integer_to_string(&sz1[0], stlsoft_num_elements(sz1), error.invalidLine));
            strcat(message, " column ");
            strcat(message, ::stlsoft::integer_to_string(&sz2[0], stlsoft_num_elements(sz2), error.invalidColumn));

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
