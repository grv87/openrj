/* /////////////////////////////////////////////////////////////////////////////
 * File:    field.hpp
 *
 * Purpose: Field class, in the STL mapping of the Open-RJ library.
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


/* \file openrj/stl/field.hpp Field class, in the STL mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_H_FIELD
#define OPENRJ_INCL_OPENRJ_STL_H_FIELD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_H_FIELD_MAJOR    1
# define OPENRJ_VER_OPENRJ_STL_H_FIELD_MINOR    0
# define OPENRJ_VER_OPENRJ_STL_H_FIELD_REVISION 2
# define OPENRJ_VER_OPENRJ_STL_H_FIELD_EDIT     4
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/stl/openrj.hpp>

#include <stlsoft_shim_string.h>
#include <stlsoft_string_access.h>

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
    field(ORJField const *field)
        : m_field(field)
    {
        openrj_assert(NULL != field);
        openrj_assert(0 == field->mbz0);
        openrj_assert(static_cast<ptrdiff_t>(field->name.len) >= 0);
        openrj_assert(static_cast<ptrdiff_t>(field->value.len) >= 0);
    }

    /// Default constructor
    field()
        : m_field(NULL)
    {}

    /// Copy constructor
    field(field const &rhs)
        : m_field(rhs.m_field)
    {
        openrj_assert(NULL == m_field || 0 == rhs.m_field->mbz0);
        openrj_assert(NULL == m_field || static_cast<ptrdiff_t>(rhs.m_field->name.len) >= 0);
        openrj_assert(NULL == m_field || static_cast<ptrdiff_t>(rhs.m_field->value.len) >= 0);
    }

    /// Copy assignment operator
    field &operator =(field const &rhs)
    {
        m_field = rhs.m_field;

        return *this;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief The name of the field
    string_t name() const
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
    /// \brief The value of the field
    string_t value() const
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
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Provides access to the underlying field pointer
    ORJField const  *get_field() const
    {
        return m_field;
    }
    /// \brief Provides access to the field's record, in the form of its 
    /// underlying field pointer
    ORJRecord const *get_record() const
    {
        openrj_assert(NULL != m_field);

        return ORJ_Field_GetRecordA(m_field);
    }
/// @}

// Members
private:
    ORJField const *m_field;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline stlsoft::shim_string<char> c_str_ptr(field const &f)
{
    ORJField const  *pf =   f.get_field();
    string_t        s;

    s.reserve(pf->name.len + 1 + pf->value.len);

    s.append(pf->name.ptr, pf->name.len);
    s.append(1, '=');
    s.append(pf->value.ptr, pf->value.len);

    return stlsoft::shim_string<char>(s.c_str(), s.length());
}

template <class S>
inline S &operator <<(S &s, field const &field)
{
    s << field.name() << "=" << field.value();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

namespace stlsoft
{
    using ::openrj::stl::c_str_ptr;
}

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_H_FIELD */

/* ////////////////////////////////////////////////////////////////////////// */
