/* /////////////////////////////////////////////////////////////////////////////
 * File:    record.hpp
 *
 * Purpose: Record class, in the C++ mapping of the Open-RJ library
 *
 * Created: 15th June 2004
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


/* \file openrj/stl/record.hpp Record class, in the C++ mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_H_RECORD
#define OPENRJ_INCL_OPENRJ_STL_H_RECORD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_H_RECORD_MAJOR       1
# define OPENRJ_VER_OPENRJ_STL_H_RECORD_MINOR       1
# define OPENRJ_VER_OPENRJ_STL_H_RECORD_REVISION    2
# define OPENRJ_VER_OPENRJ_STL_H_RECORD_EDIT        4
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exception
#endif /* ORJ_NO_EXCEPTIONS */

#include <algorithm>
#include <iterator>
#include <stdexcept>

#include <stlsoft_iterator.h>

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

/// \brief This class represents a record in the database
class record
{
public:
    typedef record              class_type;
    typedef field               value_type;
    typedef value_type const    const_reference;
    typedef value_type const    *const_pointer;
    typedef size_t              distance_type;

public:
    class const_iterator
        : public stlsoft::iterator_base<std::random_access_iterator_tag, const value_type, distance_type, const_pointer, const_reference>
    {
    public:
        typedef field               value_type;

    private:
        friend class record;

        const_iterator(ORJFieldA const *field)
            : m_field(field)
        {}
    public:
        const_iterator()
            : m_field(NULL)
        {}
        const_iterator(const_iterator const &rhs)
            : m_field(rhs.m_field)
        {}

        const_iterator &operator =(const_iterator const &rhs)
        {
            m_field = rhs.m_field;

            return *this;
        }

    public:
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
        const_reference operator *() const
        {
            m_value = value_type(m_field);

            return m_value;
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
        value_type operator *() const
        {
            return create_field_(m_field);
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
        }
        const_iterator &operator ++()
        {
            ++m_field;

            return *this;
        }
        const_iterator operator ++(int)
        {
            const_iterator  ret(*this);

            operator ++();

            return ret;
        }

    public:
        const_iterator operator -(difference_type d) const
        {
            return const_iterator(&m_field[d]);
        }
        difference_type operator -(const_iterator const &rhs) const
        {
            return &rhs.m_field[0] - &m_field[0];
        }

    public:
        bool is_equal(const_iterator const &rhs) const
        {
            return rhs.m_field == m_field;
        }

#if defined(__BORLANDC__) || \
    defined(__DMC__)
        bool operator ==(const_iterator const &rhs)
        {
            return is_equal(rhs);
        }

        bool operator !=(const_iterator const &rhs)
        {
            return !is_equal(rhs);
        }
#endif /* compiler */

    private:
        ORJFieldA const     *m_field;
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
        mutable value_type  m_value;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    };

    friend class const_iterator;

public:
    /// Conversion constructor
    record(ORJRecord const *record)
        : m_record(record)
    {}
    /// Default constructor
    record()
        : m_record(NULL)
    {}
    /// Copy constructor
    record(record const &rhs)
        : m_record(rhs.m_record)
    {}

    /// Copy assignment operator
    record &operator =(record const &rhs)
    {
        m_record = rhs.m_record;

        return *this;
    }

public:
    /// \brief Returns the number of fields in the record
    size_t size() const
    {
        openrj_assert(NULL != m_record);

        return ORJ_Record_GetNumFieldsA(m_record);
    }
    /// \brief Indicates whether the record is empty
    bool empty() const
    {
        return 0 == size();
    }

    /// \brief Returns the requested field
    ///
    /// \param index The index of the field to be returned. Must be less than the 
    /// value returned by size()
    field operator [](size_t index) const
    {
        openrj_assert(index <= size());

        return field(&m_record->fields[index]);
    }

    bool has_field(string_t const &name) const;

    string_t operator [](string_t const &name) const; // throw (std::out_of_range)

public:
    const_iterator begin() const
    {
        openrj_assert(NULL != m_record);

        return &m_record->fields[0];
    }
    const_iterator end() const
    {
        openrj_assert(NULL != m_record);

        return &m_record->fields[m_record->numFields];
    }

private:
    /// \brief Predicate for detecting name
    ///
    /// \note This is a horrible sneak of a class, since it provides both
    /// stateful unary function evaluating equality, and a stateless
    /// binary function evaluating ordering! The reason it's kept as one,
    /// rather than two providing alternate forms, is that this is seen
    /// as preferable to the situation of having two classes, not least
    /// what they'd be called!
    struct same_name
    {
    public:
        same_name()
            : m_name()
        {}
        same_name(string_t const &name)
            : m_name(name)
        {}

    public:
        bool operator ()(string_t const &lhs, string_t const &rhs) const
        {
            return lhs < rhs;
        }
        bool operator ()(ORJFieldA const &lhs, ORJFieldA const &rhs) const
        {
            return operator ()(string_t(lhs.name.ptr, lhs.name.len), string_t(rhs.name.ptr, rhs.name.len));
        }
        bool operator ()(string_t const &lhs, ORJFieldA const &rhs) const
        {
            return operator ()(lhs, string_t(rhs.name.ptr, rhs.name.len));
        }
        bool operator ()(ORJFieldA const &lhs, string_t const &rhs) const
        {
            return operator ()(string_t(lhs.name.ptr, lhs.name.len), rhs);
        }
        bool operator ()(ORJFieldA const &f) const
        {
            return m_name == f.name.ptr;
        }
        bool operator ()(field const &f) const
        {
            return m_name == f.name();
        }

    private:
        string_t const  m_name;

    private:
        same_name &operator =(same_name const &);
    };

private:
    static field create_field_(ORJFieldA const *r)
    {
        return field(r);
    }

    ORJField const  *find_field_(string_t const &name) const;

private:
    ORJRecord const *m_record;
    size_t          m_flags;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

#if !defined(__BORLANDC__) && \
    !defined(__DMC__)
inline bool operator ==(record::const_iterator const &lhs, record::const_iterator const &rhs)
{
    return lhs.is_equal(rhs);
}

inline bool operator !=(record::const_iterator const &lhs, record::const_iterator const &rhs)
{
    return !lhs.is_equal(rhs);
}
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline ORJField const *record::find_field_(string_t const &name) const
{
    // We do a boring linear search.
    ORJField const  *const  b           =   &m_record->fields[0];
    ORJField const  *const  e           =   &m_record->fields[m_record->numFields];
    ORJField const          *it;
    ORJDatabase const       *database   =   ORJ_Record_GetDatabaseA(m_record);

    if(ORJ_FLAG_ORDERFIELDS == (database->flags & ORJ_FLAG_ORDERFIELDS))
    {
        // Ordered, so we can do a binary search
        it  =   std::lower_bound(b, e, name, same_name());
    }
    else
    {
        // Unordered, so we must do a linear search
        it  =   std::find_if(b, e, same_name(name));
    }

    if(it == e)
    {
        it = NULL;
    }

    return it;
}

inline bool record::has_field(string_t const &name) const
{
    return NULL != find_field_(name);
}

inline string_t record::operator [](string_t const &name) const // throw (std::out_of_range)
{
    ORJField const  *r  =   find_field_(name);

    if(NULL == r)
    {
        throw std::out_of_range("record does not contain field named \"" + name + "\"");
    }

    return field(&*r).value();
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_H_RECORD */

/* ////////////////////////////////////////////////////////////////////////// */
