/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/record.hpp
 *
 * Purpose: record class, in the STL mapping of the Open-RJ library
 *
 * Created: 15th June 2004
 * Updated: 23rd April 2007
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


/** \file openrj/stl/record.hpp
 *
 * \brief [C++ only] Definition of the openrj::stl::record class.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_RECORD
#define OPENRJ_INCL_OPENRJ_STL_HPP_RECORD

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_RECORD_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_HPP_RECORD_MINOR     7
# define OPENRJ_VER_OPENRJ_STL_HPP_RECORD_REVISION  6
# define OPENRJ_VER_OPENRJ_STL_HPP_RECORD_EDIT      30
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exception
#endif /* ORJ_NO_EXCEPTIONS */

#include <openrj/stl/field.hpp>

#include <algorithm>
#include <iterator>
#include <stdexcept>

#include <stlsoft/stlsoft.h>

#if !defined(_STLSOFT_VER_1_9_1) || \
    _STLSOFT_VER < _STLSOFT_VER_1_9_1
# error This requires STLSoft 1.9.1, or later
#endif /* STLSoft 1.9.1 */

#include <stlsoft/iterators/indirect_reverse_iterator.hpp>
#include <stlsoft/util/std/iterator_helper.hpp>

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
    /// This type
    typedef record                                          class_type;
    /// The value type
    typedef field                                           value_type;
    /// The non-mutating (const) reference type
    typedef value_type const                                const_reference;
    /// The non-mutating (const) pointer type
    typedef value_type const                                *const_pointer;
    /// The difference type
    typedef ptrdiff_t                                       difference_type;

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
public:
    class const_iterator;

    friend class const_iterator;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The non-mutating (const) reverse iterator type
#  if 0
    typedef stlsoft_ns_qual(const_reverse_iterator_base)<   const_iterator
                                                        ,   value_type
                                                        ,   value_type
                                                        ,   void
                                                        ,   difference_type
                                                        >   const_reverse_iterator;
#  else /* ? 0 */
    // Can't use reverse_iterator, because const_iterator is a forward-declared member 
    // class - this now appears incorrect. Somehow I've made subsequent changes that
    // nullify the requirement. TODO: Investigate further ...
    typedef stlsoft_ns_qual(indirect_reverse_iterator)<     const_iterator
                                                        ,   value_type
                                                        ,   value_type // Return by value!
                                                        ,   void
                                                        ,   difference_type
                                                        ,   stlsoft_ns_qual_std(random_access_iterator_tag)
                                                        >   const_reverse_iterator;
#  endif /* 0 */
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

public:
    /// Conversion constructor
    explicit record(ORJRecord const* record);
    /// Default constructor
    record();
    /// Copy constructor
    record(record const &rhs);

    /// Copy assignment operator
    record &operator =(record const &rhs);

public:
    /// \brief Returns the number of fields in the record
    size_t size() const;

    /// \brief Indicates whether the record is empty
    bool empty() const;

    /// \brief Returns the record comment string
    string_t comment() const;

    /// \brief Returns the requested field
    ///
    /// \param index The index of the field to be returned. Must be less than the
    /// value returned by size()
    ///
    /// \return The field corresponding to the given index
    const field operator [](size_t index) const;

    /// \brief Indicates whether the record contains one or more fields of the given name
    bool has_field(string_t const &name) const;

#if defined(STLSOFT_COMPILER_IS_INTEL)
    bool has_field(char const* name) const
    {
        return this->has_field(string_t(name));
    }
#endif /* compiler */

#if 0
    /// \brief Indicates whether the record contains one or more fields of the given name and value
    bool has_field(string_t const &name, string_t const &value) const;
#endif /* 0 */

    /// \brief Indicates the number of contained fields with the given name
    size_t count_fields(string_t const &name) const;

    /// \brief Returns the value of the first field with the given name
    ///
    /// \param name The name of the field whose value will be returned. If not
    /// present, then an instance of std::out_of_range is thrown
    ///
    /// \return The value of the named field. There is no error return
    const string_t operator [](string_t const &name) const; // throw (std::out_of_range)

#if defined(STLSOFT_COMPILER_IS_INTEL)
    const string_t operator [](char const* name) const
    {
        return this->operator [](string_t(name));
    }
#endif /* compiler */

    /// \brief Returns the value of the first field of the given name, or the given
    /// default if none exists
    ///
    /// \param name The name of the field whose value will be returned
    /// \param defValue The default value returned if the named field does not exist
    ///
    /// \return The value of the named field if found, or \c defValue
    string_t get_field_value(string_t const &name, string_t const &defValue) const;

public:
    /// Begins the iteration
    ///
    /// \return A non-mutating (const) iterator representing the start of the sequence
    const_iterator begin() const;
    /// Ends the iteration
    ///
    /// \return A non-mutating (const) iterator representing the end of the sequence
    const_iterator end() const;

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return A non-mutating (const) iterator representing the start of the reverse sequence
    const_reverse_iterator rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return A non-mutating (const) iterator representing the end of the reverse sequence
    const_reverse_iterator rend() const;
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

private:
    /// \brief Predicate for detecting name
    ///
    /// \note This is a horrible sneak of a class, since it provides both
    /// stateful unary function evaluating equality, and a stateless
    /// binary function evaluating ordering! The reason it's kept as one,
    /// rather than two providing alternate forms, is that this is seen
    /// as preferable to the situation of having two classes, not least
    /// what they'd be called!
    struct same_name;

private:
    static field create_field_(ORJFieldA const* r)
    {
        return field(r);
    }

    ORJField const  *find_field_(string_t const &name) const;
//    ORJField const  *find_field_(string_t const &name, string_t const &value) const;
    size_t          count_fields_(string_t const &name) const;

private:
    ORJRecord const*    m_record;
    size_t              m_flags;
};

class record::const_iterator
    : public stlsoft::iterator_base<std::random_access_iterator_tag, const record::value_type, record::difference_type, record::const_pointer, record::const_reference>
{
public:
    typedef field   value_type;

private:
    friend class    record;

    const_iterator(ORJFieldA const* field);
public:
    const_iterator();
    const_iterator(const_iterator const &rhs);
    const_iterator &operator =(const_iterator const &rhs);

public:
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
    const_reference operator *() const;
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    value_type operator *() const;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    const_iterator &operator ++();
    const_iterator operator ++(int);
    const_iterator &operator --();
    const_iterator operator --(int);

public:
    const_iterator operator -(difference_type d) const;
    difference_type operator -(const_iterator const &rhs) const;

public:
    bool is_equal(const_iterator const &rhs) const;

#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    defined(STLSOFT_COMPILER_IS_DMC)
    bool operator ==(const_iterator const &rhs) const;
    bool operator !=(const_iterator const &rhs) const;
#endif /* compiler */

private:
    ORJFieldA const     *m_field;
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
    mutable value_type  m_value;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
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

// record::const_iterator

inline record::const_iterator::const_iterator(ORJFieldA const* field)
    : m_field(field)
{}

inline record::const_iterator::const_iterator()
    : m_field(NULL)
{}

inline record::const_iterator::const_iterator(const_iterator const &rhs)
    : m_field(rhs.m_field)
{}

inline record::const_iterator &record::const_iterator::operator =(const_iterator const &rhs)
{
    m_field = rhs.m_field;

    return *this;
}

#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
inline record::const_reference record::const_iterator::operator *() const
{
    m_value = value_type(m_field);

    return m_value;
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
inline record::value_type record::const_iterator::operator *() const
{
    return create_field_(m_field);
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
}

inline record::const_iterator &record::const_iterator::operator ++()
{
    ++m_field;

    return *this;
}

inline record::const_iterator record::const_iterator::operator ++(int)
{
    const_iterator  ret(*this);

    operator ++();

    return ret;
}

inline record::const_iterator &record::const_iterator::operator --()
{
    --m_field;

    return *this;
}

inline record::const_iterator record::const_iterator::operator --(int)
{
    const_iterator  ret(*this);

    operator --();

    return ret;
}

inline record::const_iterator record::const_iterator::operator -(record::difference_type d) const
{
    return const_iterator(&m_field[-d]);
}

inline record::difference_type record::const_iterator::operator -(record::const_iterator const &rhs) const
{
    return &rhs.m_field[0] - &m_field[0];
}

inline bool record::const_iterator::is_equal(record::const_iterator const &rhs) const
{
    return rhs.m_field == m_field;
}

#if defined(__BORLANDC__) || \
    defined(__DMC__)
inline bool record::const_iterator::operator ==(record::const_iterator const &rhs) const
{
    return is_equal(rhs);
}

inline bool record::const_iterator::operator !=(record::const_iterator const &rhs) const
{
    return !is_equal(rhs);
}
#endif /* compiler */

// record::same_name

struct record::same_name
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

// record

inline ORJField const* record::find_field_(string_t const &name) const
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

        if(e != it)
        {
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
            // This copes with the non-standard GCC 2.x standard library, but
            // will also work with a good one (albeit less efficiently).
            if(0 == string_t((*it).name.ptr, (*it).name.len).compare(name))
#else /* ? compiler */
            if(0 != name.compare(0, (*it).name.len, (*it).name.ptr))
#endif /* compiler */
            {
                it = e;
            }
        }
    }
    else
    {
        // Unordered, so we must do a linear search
        it  =   std::find_if(b, e, same_name(name));
    }

    if(e == it)
    {
        it = NULL;
    }

    return it;
}

inline size_t record::count_fields_(string_t const &name) const
{
    ORJField const  *const  b           =   &m_record->fields[0];
    ORJField const  *const  e           =   &m_record->fields[m_record->numFields];
    ORJDatabase const       *database   =   ORJ_Record_GetDatabaseA(m_record);

    if(ORJ_FLAG_ORDERFIELDS == (database->flags & ORJ_FLAG_ORDERFIELDS))
    {
        // Ordered, so we can do a binary search
        ORJField const  *lower  =   std::lower_bound(b, e, name, same_name());
        ORJField const  *upper  =   std::upper_bound(b, e, name, same_name());

        return static_cast<size_t>(std::distance(lower, upper)); // distance() return ptrdiff_t
    }
    else
    {
        // Unordered, so we must do a linear search
        return static_cast<size_t>(std::count_if(b, e, same_name(name))); // some impls do not return size_t
    }
}

inline record::record(ORJRecord const* record)
    : m_record(record)
{}

inline record::record()
    : m_record(NULL)
{}

inline record::record(record const &rhs)
    : m_record(rhs.m_record)
{}

inline record &record::operator =(record const &rhs)
{
    m_record = rhs.m_record;

    return *this;
}

inline size_t record::size() const
{
    openrj_assert(NULL != m_record);

    return ORJ_Record_GetNumFieldsA(m_record);
}

inline string_t record::comment() const
{
    openrj_assert(NULL != m_record);

    return string_t(m_record->comment.ptr, m_record->comment.len);
}

inline bool record::empty() const
{
    return 0 == size();
}

inline const field record::operator [](size_t index) const
{
    openrj_assert(index <= size());

    return field(&m_record->fields[index]);
}

inline bool record::has_field(string_t const &name) const
{
    return NULL != find_field_(name);
}

#if 0
inline bool record::has_field(string_t const &name, string_t const &value) const
{
    return NULL != find_field_(name, value);
}
#endif /* 0 */

inline size_t record::count_fields(string_t const &name) const
{
    return count_fields_(name);
}

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1200
# pragma warning(push)
# pragma warning(disable : 4702)
#endif /* compiler */

inline const string_t record::operator [](string_t const &name) const // throw (std::out_of_range)
{
    ORJField const  *r  =   find_field_(name);

    if(NULL == r)
    {
        throw std::out_of_range(stlsoft::c_str_ptr("record does not contain field named \"" + name + "\""));
    }

    return field(&*r).value();
}

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1200
# pragma warning(pop)
#endif /* compiler */

inline string_t record::get_field_value(string_t const &name, string_t const &defValue) const
{
    ORJField const  *r  =   find_field_(name);

    return (NULL == r) ? defValue : field(&*r).value();
}

inline record::const_iterator record::begin() const
{
    openrj_assert(NULL != m_record);

    return &m_record->fields[0];
}

inline record::const_iterator record::end() const
{
    openrj_assert(NULL != m_record);

    return &m_record->fields[m_record->numFields];
}

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
inline record::const_reverse_iterator record::rbegin() const
{
    return const_reverse_iterator(end());
}

inline record::const_reverse_iterator record::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_RECORD */

/* ////////////////////////////////////////////////////////////////////////// */
