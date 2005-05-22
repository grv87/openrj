/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj-cpp.hpp
 *
 * Purpose: Root header file for the C++ mapping of the Open-RJ library
 *
 * Created: 15th June 2004
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


/* \file openrj/cpp/openrj.hpp This is the root file of the Open-RJ C++ -API
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_H_OPENRJ
#define OPENRJ_INCL_OPENRJ_CPP_H_OPENRJ

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_H_OPENRJ_MAJOR       1
# define OPENRJ_VER_OPENRJ_CPP_H_OPENRJ_MINOR       4
# define OPENRJ_VER_OPENRJ_CPP_H_OPENRJ_REVISION    1
# define OPENRJ_VER_OPENRJ_CPP_H_OPENRJ_EDIT        11
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#include <stlsoft/string_view.hpp>

#include <exception>

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef __BORLANDC__
# pragma warn -8026
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(ORJ_NO_NAMESPACE)
# error The Open-RJ C++ mapping may not be used if namespacing is disabled/deselected
#endif /* !ORJ_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
    /// \brief The Open-RJ C++ namespace - \c openrj::cpp
    ///
    /// This contains the Field, Record, FileDatabase and MemoryDatabase classes,
    /// along with the exception class DatabaseException
    namespace cpp
    {
        class Field;
        class Record;
        class DatabaseBase;
        class FileDatabase;
        class MemoryDatabase;
        typedef ::stlsoft::basic_string_view<char>  String;

#if !defined(ORJ_NO_EXCEPTIONS)
        /// \brief The exception type thrown by the Open-RJ - C++ mapping
        class DatabaseException
            : public std::exception
        {
        public:
            /// \brief Construct from result code and error structure
            ///
            /// \param rc The \link #ORJRC result code \endlink reflecting the error condition
            /// \param error The error structure (ORJError) associated with a parsing error
            DatabaseException(ORJRC rc, ORJError const &error)
                : m_rc(rc)
                , m_error(error)
            {}

        public:
            /// \brief The result code associated with the exception
            ORJRC rc() const
            {
                return m_rc;
            }
            /// \brief The error structure associated with the exception, when \c rc() returns ORJ_RC_PARSEERROR
            ORJError const &error() const
            {
                return m_error;
            }

        public:
            char const  *what() const throw()
            {
                if(ORJ_RC_PARSEERROR == m_rc)
                {
                    return ::stlsoft::c_str_ptr(m_error.parseError);
                }
                else
                {
                    return ::stlsoft::c_str_ptr(m_rc);
                }
            }

        private:
            ORJRC       m_rc;
            ORJError    m_error;
        };
#endif /* !ORJ_NO_EXCEPTIONS */

    } // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_OPENRJ */

/* ////////////////////////////////////////////////////////////////////////// */
