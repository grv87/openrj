/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/record.hpp
 *
 * Purpose: Record class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
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


/** \file openrj/cpp/record.hpp
 *
 * [C++ only] Definition of the openrj::cpp::Record class.
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_H_RECORD
#define OPENRJ_INCL_OPENRJ_CPP_H_RECORD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_H_RECORD_MAJOR       1
# define OPENRJ_VER_OPENRJ_CPP_H_RECORD_MINOR       7
# define OPENRJ_VER_OPENRJ_CPP_H_RECORD_REVISION    2
# define OPENRJ_VER_OPENRJ_CPP_H_RECORD_EDIT        20
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>
#include <openrj/cpp/field.hpp>

#include <stlsoft/stlsoft.h>
#include <stlsoft/auto_buffer.hpp>
#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
# include <stlsoft/meta.hpp>
# include <stlsoft/meta/yesno.hpp>
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#include <stdio.h>
#include <algorithm>
#include <stdexcept>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
namespace cpp
{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief This class represents a record in the database
class Record
{
private:
    friend class DatabaseBase;

    Record(ORJRecord const &record)
        : m_record(&record)
    {}
public:
    /// Default constructor
    Record()
        : m_record(NULL)
    {}
    /// Copy constructor
    Record(Record const &rhs)
        : m_record(rhs.m_record)
    {}

    /// Copy assignment operator
    Record &operator =(Record const &rhs)
    {
        m_record = rhs.m_record;

        return *this;
    }

public:
    /// \brief Returns the record comment string
    String GetComment() const
    {
        openrj_assert(NULL != m_record);

        ORJStringA const *comment;

        return (ORJ_RC_SUCCESS == ORJ_Record_GetCommentA(m_record, &comment)) ? String(comment->ptr, comment->len) : String();
    }

    /// \brief Returns the number of fields in the record
    size_t GetNumFields() const
    {
        openrj_assert(NULL != m_record);

        return ORJ_Record_GetNumFieldsA(m_record);
    }

    /// \brief Returns the requested field
    ///
    /// \param index The index of the field to be returned. Must be less than the
    /// value returned by GetNumFields()
    ///
    /// \note The return type is const, to prevent confusing semantics such
    /// as
    /// \htmlonly
    /// <pre>
    /// 
    /// Record record = . . .;
    ///
    /// record[0] = record[1]; // Doesn't have any effect!!
    /// 
    /// </pre>
    /// \endhtmlonly
    const Field operator [](size_t index) const
    {
        openrj_assert(index <= GetNumFields());

        ORJFieldA const  *field;

        if(ORJ_RC_SUCCESS != ORJ_Record_GetFieldA(m_record, index, &field))
        {
            field = NULL;
        }

        return Field(field);
    }

    /// \brief Looks up the field, optionally returning the located field to the caller
    ///
    /// \param name The name of the field to be returned.
    /// \param pfield Pointer to a pointer that will be set to the returned field
    bool has_field_with_name(char const *name, ORJField const **pfield = NULL) const
    {
        ORJField const  *const  begin   =   &m_record->fields[0];
        ORJField const  *const  end     =   &m_record->fields[m_record->numFields];
        ORJField const          *it     =   ::std::find_if(begin, end, match_name(name));

        if(NULL != pfield)
        {
            *pfield = (it == end) ? NULL : it;
        }

        return (it != end);
    }

    bool HasField(char const *name) const
    {
        return NULL != ORJ_Record_FindFieldByNameA(m_record, name, NULL);
    }

    bool HasField(char const *name, char const *value) const
    {
        return NULL != ORJ_Record_FindFieldByNameA(m_record, name, value);
    }

    bool HasFieldWithValue(char const *value) const
    {
        return NULL != ORJ_Record_FindFieldByNameA(m_record, NULL, value);
    }

#if !defined(ORJ_NO_EXCEPTIONS)
    /// \brief Returns the requested field
    ///
    /// \param name The index of the field to be returned.
    /// \retval A Field wrapper to the requested field. If not found, an
    /// instance of std::out_of_range is thrown. There is no error return
    ///
    /// \note The return type is const, to prevent confusing semantics such
    /// as
    /// \htmlonly
    /// <pre>
    /// 
    /// Record record = . . .;
    ///
    /// record["Channel"] = record["Port"]; // Doesn't have any effect!!
    /// 
    /// </pre>
    /// \endhtmlonly
    String operator [](char const *name) const
    {
        openrj_assert(NULL != name);

        ORJField const  *begin  =   &m_record->fields[0];
        ORJField const  *end    =   &m_record->fields[m_record->numFields];
        ORJField const  *it     =   ::std::find_if(begin, end, match_name(name));

        if(it == end)
        {
            const size_t                nameLen     =   ::strlen(name);
            static const char           fmt[]       =   "Field \"%s\" not found";
            stlsoft::auto_buffer<char>  buff(nameLen + stlsoft_num_elements(fmt));

            throw ::std::out_of_range((0 == buff.size()) ? "Field not found" : (::sprintf(&buff[0], fmt, name), buff.data()));
        }

        return String(it->value.ptr, it->value.len);
    }


# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
     !defined(STLSOFT_COMPILER_IS_BORLAND)
    template <typename S>
    String subscript_operator_(S const &name, stlsoft::no_type) const
    {
        return operator [](::stlsoft::c_str_ptr(name));
    }

    template <typename I>
    Field subscript_operator_(I const &index, stlsoft::yes_type) const
    {
        return operator [](static_cast<size_t>(index));
    }

    /// \brief Returns the requested field
    ///
    /// \param name The index of the field to be returned.
    /// \retval A Field wrapper to the requested field. If not found, an
    /// instance of std::out_of_range is thrown. There is no error return
    template <typename S>
    typename stlsoft::select_first_type<Field, String, stlsoft::is_integral_type<S>::value>::type operator [](S const &name) const
    {
        typedef typename stlsoft::is_integral_type<S>::type     yesno_type;

        return subscript_operator_(name, yesno_type());
    }
# else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    /// \brief Returns the requested field
    ///
    /// \param name The index of the field to be returned.
    /// \retval A Field wrapper to the requested field. If not found, an
    /// instance of std::out_of_range is thrown. There is no error return
#  if !defined(STLSOFT_COMPILER_IS_MSVC) || \
      _MSC_VER >= 1200
    template <typename S>
    typename String operator [](S const &name) const
    {
        return operator [](::stlsoft::c_str_ptr(name));
    }
#  endif /* compiler */

#  ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
    const Field operator [](int index) const
    {
        return operator [](static_cast<size_t>(index));
    }
//    const Field operator [](long index) const
//    {
//        return operator [](static_cast<size_t>(index));
//    }
#  endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
# endif /* !__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
#endif /* !ORJ_NO_EXCEPTIONS */

// Implementation
private:
    struct match_name
    {
    public:
        match_name(char const *name)
            : m_name(name)
        {}

    public:
        bool operator ()(ORJField const &field) const
        {
            return 0 == strcmp(m_name, field.name.ptr);
        }

    private:
        char const  *m_name;
    };

// Members
private:
    ORJRecord const *m_record;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_RECORD */

/* ////////////////////////////////////////////////////////////////////////// */
