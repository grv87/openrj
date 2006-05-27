/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/field.hpp
 *
 * Purpose: field class, in the STL mapping of the Open-RJ library.
 *
 * Created: 28th September 2004
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


/** \file openrj/stl/field.hpp
 *
 * [C++ only] Definition of the openrj::stl::field class.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_FIELD
#define OPENRJ_INCL_OPENRJ_STL_HPP_FIELD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_FIELD_MAJOR      1
# define OPENRJ_VER_OPENRJ_STL_HPP_FIELD_MINOR      4
# define OPENRJ_VER_OPENRJ_STL_HPP_FIELD_REVISION   2
# define OPENRJ_VER_OPENRJ_STL_HPP_FIELD_EDIT       16
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/stl/openrj.hpp>

#include <stlsoft/shim_string.hpp>
#include <stlsoft/string_access.hpp>

#include <stdexcept>

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

/// \brief This class represents a field in a record in the database
class field
{
/// \name Types
/// @{
public:
    typedef field       class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Conversion constructor
    explicit field(ORJField const *field);
    /// Default constructor
    field();
    /// Copy constructor
    field(field const &rhs);
    /// Copy assignment operator
    field &operator =(field const &rhs);
/// @}

/// \name Attributes
/// @{
public:
    /// \brief The name of the field
    string_t name() const;
    /// \brief The value of the field
    string_t value() const;
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Provides access to the underlying field pointer
    ORJField const  *get_field() const;
    /// \brief Provides access to the field's record, in the form of its
    /// underlying field pointer
    ORJRecord const *get_record() const;
/// @}

// Members
private:
    ORJField const *m_field;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// \brief String access shim providing, possibly NULL, C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline stlsoft::basic_shim_string<char, true> c_str_ptr_null(field const &f)
{
    ORJField const  *pf =   f.get_field();
    string_t        s;

    s.reserve(pf->name.len + 1 + pf->value.len);

    s.append(pf->name.ptr, pf->name.len);
    s.append(1, '=');
    s.append(pf->value.ptr, pf->value.len);

    return stlsoft::basic_shim_string<char, true>(s.c_str(), s.length());
}

/// \brief String access shim providing C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline stlsoft::basic_shim_string<char> c_str_ptr(field const &f)
{
    ORJField const  *pf =   f.get_field();
    string_t        s;

    s.reserve(pf->name.len + 1 + pf->value.len);

    s.append(pf->name.ptr, pf->name.len);
    s.append(1, '=');
    s.append(pf->value.ptr, pf->value.len);

    return stlsoft::basic_shim_string<char>(s.c_str(), s.length());
}

/// \brief String access shim length of C-string form of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline size_t c_str_len(field const &f)
{
    ORJField const  *pf =   f.get_field();

    return pf->name.len + 1 + pf->value.len;
}

/// \brief String access shim providing (potentially non-nul-terminated) C-string access to the contents of a Field instance
///
/// \ingroup group_openrj_stringaccessshims
inline ::stlsoft::basic_shim_string<char> c_str_data(field const &f)
{
    return c_str_ptr(f);
}

/// \brief Stream insertion shim for a field instance
///
/// \ingroup group_openrj_streaminsertionshimfunctiontemplates
template <class S>
inline S &operator <<(S &s, field const &field)
{
    s << field.name() << "=" << field.value();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline field::field(ORJField const *field)
    : m_field(field)
{
    openrj_assert(NULL != field);
    openrj_assert(0 == field->mbz0);
    openrj_assert(static_cast<ptrdiff_t>(field->name.len) >= 0);
    openrj_assert(static_cast<ptrdiff_t>(field->value.len) >= 0);
}

inline field::field()
    : m_field(NULL)
{}

inline field::field(field const &rhs)
    : m_field(rhs.m_field)
{
    openrj_assert(NULL == m_field || 0 == rhs.m_field->mbz0);
    openrj_assert(NULL == m_field || static_cast<ptrdiff_t>(rhs.m_field->name.len) >= 0);
    openrj_assert(NULL == m_field || static_cast<ptrdiff_t>(rhs.m_field->value.len) >= 0);
}

inline field &field::operator =(field const &rhs)
{
    m_field = rhs.m_field;

    return *this;
}

inline string_t field::name() const
{
    if(NULL == m_field)
    {
        return string_t();
    }

    openrj_assert(NULL != m_field);
    openrj_assert(0 == m_field->mbz0);
    openrj_assert(static_cast<ptrdiff_t>(m_field->name.len) >= 0);
    openrj_assert(static_cast<ptrdiff_t>(m_field->value.len) >= 0);

    return string_t(m_field->name.ptr, m_field->name.len);
}

inline string_t field::value() const
{
    if(NULL == m_field)
    {
        return string_t();
    }

    openrj_assert(NULL != m_field);
    openrj_assert(0 == m_field->mbz0);
    openrj_assert(static_cast<ptrdiff_t>(m_field->name.len) >= 0);
    openrj_assert(static_cast<ptrdiff_t>(m_field->value.len) >= 0);

    return string_t(m_field->value.ptr, m_field->value.len);
}

inline ORJField const *field::get_field() const
{
    return m_field;
}

inline ORJRecord const *field::get_record() const
{
    openrj_assert(NULL != m_field);

    return ORJ_Field_GetRecordA(m_field);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

namespace stlsoft
{
    using ::openrj::stl::c_str_ptr_null;
    using ::openrj::stl::c_str_ptr;
    using ::openrj::stl::c_str_data;
    using ::openrj::stl::c_str_len;
}

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_FIELD */

/* ////////////////////////////////////////////////////////////////////////// */
