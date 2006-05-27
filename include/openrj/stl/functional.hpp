/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/functional.hpp
 *
 * Purpose: Functors for use with the Open-RJ STL mapping
 *
 * Created: 10th November 2004
 * Updated: 28th May 2006
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


/** \file openrj/stl/functional.hpp
 *
 * [C++ only] Functors for use with the
 *  \link openrj::stl Open-RJ/STL\endlink mapping.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_FUNCTIONAL
#define OPENRJ_INCL_OPENRJ_STL_HPP_FUNCTIONAL

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_FUNCTIONAL_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_FUNCTIONAL_MINOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_FUNCTIONAL_REVISION  2
# define OPENRJ_VER_OPENRJ_STL_HPP_FUNCTIONAL_EDIT      8
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/stl/openrj.hpp>
#include <openrj/stl/field.hpp>
#include <openrj/stl/record.hpp>

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
 * Classes
 */

/// Predicate which detects whether a record contains one of more fields of a
/// given name
struct record_has_field
{
/// \name Construction
/// @{
public:
    /// Constructs an instance with the given field name
    ///
    /// \param fieldName The name of the field against which records will be tested
    explicit record_has_field(char const *fieldName)
        : m_fieldName(fieldName)
    {}
    /// Constructs an instance with the given field name
    ///
    /// \param fieldName The name of the field against which records will be tested
    template <typename S>
    explicit record_has_field(S const &fieldName)
        : m_fieldName(::stlsoft::c_str_ptr(fieldName))
    {}
/// @}

/// \name Operators
/// @{
public:
    /// \brief Tests the given record to see whether it contains (one or more of)
    /// the required field
    template <typename R>
    bool operator ()(R const &record) const
    {
        return record.has_field(m_fieldName);
    }
/// @}

/// \name Members
/// @{
private:
    const string_t    m_fieldName;
/// @}

// Not to be implemented
private:
    record_has_field &operator =(record_has_field const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_FUNCTIONAL */

/* ////////////////////////////////////////////////////////////////////////// */
