/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/utility.hpp
 *
 * Purpose: Helper functions for use with the Open-RJ STL mapping
 *
 * Created: 2nd December 2004
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


/* \file openrj/stl/utility.hpp Helper functions for use with the Open-RJ STL mapping
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_UTILITY
#define OPENRJ_INCL_OPENRJ_STL_HPP_UTILITY

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_UTILITY_MAJOR    1
# define OPENRJ_VER_OPENRJ_STL_HPP_UTILITY_MINOR    0
# define OPENRJ_VER_OPENRJ_STL_HPP_UTILITY_REVISION 2
# define OPENRJ_VER_OPENRJ_STL_HPP_UTILITY_EDIT     4
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
 * Helper functions
 */

/// \brief Looks up the named field in one of two records, or throws exception if not found in either
///
/// \param fieldName The named of the field to be searched for
/// \param r0 The first record to be searched
/// \param r1 The second record to be searched
///
/// \return The value matching the field found in r0 or r1
///
/// \note If the field is not found in either record, an instance of std::out_of_range exception is thrown
inline string_t lookup(string_t const &fieldName, record const &r0, record const &r1)
{
    return r0.has_field(fieldName) ? r0[fieldName] : r1[fieldName];
}

/// \brief Looks up the named field in one of two records, or returns a default value if not found in either
///
/// \param fieldName The named of the field to be searched for
/// \param r0 The first record to be searched
/// \param r1 The second record to be searched
/// \param defaultValue The default value to be used if the named field is not found in either record
///
/// \return The value matching the field found in r0 or r1, or \c defaultValue if not found in either
inline string_t lookup(string_t const &fieldName, record const &r0, record const &r1, string_t const &defaultValue)
{
    return r0.has_field(fieldName) ? r0[fieldName] : r1.has_field(fieldName) ? r1[fieldName] : defaultValue;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_UTILITY */

/* ////////////////////////////////////////////////////////////////////////// */
