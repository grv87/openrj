/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj.hpp
 *
 * Purpose: Root header file for the C++ mapping of the Open-RJ library
 *
 * Created: 28th September 2004
 * Updated: 29th September 2004
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004, Matthew Wilson and Synesis Software
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

#ifndef OPENRJ_INCL_OPENRJ_STL_H_OPENRJ
#define OPENRJ_INCL_OPENRJ_STL_H_OPENRJ

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_H_OPENRJ_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_H_OPENRJ_MINOR     0
# define OPENRJ_VER_OPENRJ_STL_H_OPENRJ_REVISION  2
# define OPENRJ_VER_OPENRJ_STL_H_OPENRJ_EDIT      2
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

#include <exception>
#include <string>

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
/// The Open-RJ STL namespace - \c openrj::stl
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
public:
    /// Constructs an exception from the given error code and error structure
    database_exception(ORJRC rc, ORJError const &error)
        : m_rc(rc)
        , m_error(error)
    {}

public:
    ORJRC rc() const
    {
        return m_rc;
    }
    ORJError const &error() const
    {
        return m_error;
    }

    virtual char const *what() const throw()
    {
        return "Open-RJ exception";
    }

private:
    ORJRC       m_rc;
    ORJError    m_error;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_H_OPENRJ */

/* ////////////////////////////////////////////////////////////////////////// */
