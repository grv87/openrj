/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/database.hpp
 *
 * Purpose: file_database and memory_database classes, in the STL mapping of the
 *          Open-RJ library
 *
 * Created: 15th June 2004
 * Updated: 26th December 2006
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


/** \file openrj/stl/database.hpp
 *
 * \brief [C++ only] Definition of openrj::stl::file_database and
 *  openrj::stl::memory_database classes.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_DATABASE
#define OPENRJ_INCL_OPENRJ_STL_HPP_DATABASE

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_DATABASE_MAJOR       1
# define OPENRJ_VER_OPENRJ_STL_HPP_DATABASE_MINOR       7
# define OPENRJ_VER_OPENRJ_STL_HPP_DATABASE_REVISION    7
# define OPENRJ_VER_OPENRJ_STL_HPP_DATABASE_EDIT        39
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#include <openrj/stl/openrj.hpp>
#include <openrj/stl/field.hpp>
#include <openrj/stl/record.hpp>

#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exception
#endif /* ORJ_NO_EXCEPTIONS */

#include <iterator>

#include <stlsoft/iterators/indirect_reverse_iterator.hpp>
#include <stlsoft/iterator.hpp>
#include <stlsoft/proxy_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef __BORLANDC__
# pragma warn -8027
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#if defined(__BORLANDC__) || \
    defined(__COMO__x) || \
    (   defined(__DMC__) && \
        __DMC__ < 0x0843)|| \
    (   defined(__GNUC__) && \
        (   __GNUC__ < 3) || \
            (   __GNUC__ == 3 && \
                __GNUC_MINOR__ < 2)) || \
    (   defined(_MSC_VER) && \
        (   _MSC_VER < 1200 || \
            _MSC_VER == 1300)) /* For some reason VC++ 7.0 (not 6.0, 7.1) has a fit with this. */
# define OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
#endif /* compiler */

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

/// \brief This class acts as an implementation parent for both the \c file_database
/// and \c memory_database classes
class database_base
{
private:
    struct proxy_traits_type
    {
        static field make_value(ORJField const &field_)
        {
            return field(&field_);
        }
    };
protected:
    /// This type
    typedef database_base                   class_type;
public:
    /// The value type
    typedef record                          value_type;
    /// The non-mutating (const) reference type
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
    typedef value_type const                &const_reference;
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    typedef value_type const                const_reference;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    /// The non-mutating (const) pointer type
    typedef value_type const                *const_pointer;
    /// The difference type
    typedef ptrdiff_t                       difference_type;
    /// The size type
    typedef size_t                          size_type;
#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
    // For some reason yet to be explained, these compilers fail to use
    // operator == / != on the proxy_iterator, irrespective of whether it's
    // implemented as a member function or a free function. I have, as yet, failed
    // to find any workaround.
    /// The non-mutating (const) iterator type for enumerating all fields in the database
    typedef stlsoft::proxy_iterator<const ORJField
                                ,   field
                                ,   proxy_traits_type
                                ,   std::random_access_iterator_tag
                                ,   field
                                >           const_field_iterator;

# if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The non-mutating (const) reverse iterator type
    typedef stlsoft_ns_qual(const_reverse_iterator_base)<   const_field_iterator
                                                        ,   field
                                                        ,   field // Return by value!
                                                        ,   void
                                                        ,   difference_type
                                                        >   const_reverse_field_iterator;
# endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */
    /// The distance type
    typedef size_t                          distance_type;

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
public:
    /// The non-mutating (const) iterator type
    class const_iterator;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The non-mutating (const) reverse iterator type
#  if 0
    typedef stlsoft_ns_qual(const_reverse_iterator_base)<   const_iterator
                                                        ,   value_type
                                                        ,   value_type // Return by value!
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
                                                        ,   std::random_access_iterator_tag
                                                        >   const_reverse_iterator;
#  endif /* 0 */
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

protected:
    explicit database_base(ORJDatabase const *database);
public:
    /// \brief Closes the database
    ~database_base();

public:
    /// Returns the number of lines in the database
    size_t num_lines() const;
    /// Returns the number of fields in the database
    size_t num_fields() const;
    /// Returns the number of records in the database
    size_t num_records() const;
    /// Returns the number of records in the database
    size_t size() const;

public:
    /// \brief Returns the requested record
    ///
    /// \param index The index of the record to be returned. Must be less than the
    /// value returned by size()
    const record operator [](size_t index) const;

public:
    /// Begins the iteration
    ///
    /// \return A non-mutating (const) iterator representing the start of the sequence
    const_iterator begin() const;
    /// Ends the iteration
    ///
    /// \return A non-mutating (const) iterator representing the end of the sequence
    const_iterator end() const;

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return A non-mutating (const) iterator representing the start of the reverse sequence
    const_reverse_iterator rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return A non-mutating (const) iterator representing the end of the reverse sequence
    const_reverse_iterator rend() const;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
    const_field_iterator fields_begin() const;
    const_field_iterator fields_end() const;
# if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    const_reverse_field_iterator fields_rbegin() const;
    const_reverse_field_iterator fields_rend() const;
# endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */

// Members
private:
    ORJDatabase const *m_database;

// Not to be implemented
private:
    database_base(class_type const &);
    class_type const &operator =(class_type const &);
};

#ifndef OPENRJ_NO_FILE_HANDLING
/// \brief This class opens and provides access to a file-based Open-RJ database
class file_database
    : public database_base
{
private:
    typedef database_base       parent_class_type;
public:
    typedef file_database       class_type;

public:
    /// \brief Constructs a database instance from the given database file, and
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit file_database(char const *jarName, unsigned flags = 0);
    /// \brief Constructs a database instance from the given database file, and
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    template <typename S>
    explicit file_database(S const &jarName, unsigned flags = 0)
        : parent_class_type(create_database_(::stlsoft::c_str_ptr(jarName), flags))
    {}

// Implementation
private:
    static ORJDatabase const *create_database_(char const *jarName, unsigned flags);

// Not to be implemented
private:
    file_database(class_type const &);
    class_type const &operator =(class_type const &);
};

typedef file_database   database;
#endif /* !OPENRJ_NO_FILE_HANDLING */

/// \brief This class opens and provides access to a memory-based Open-RJ database
class memory_database
    : public database_base
{
private:
    typedef database_base       parent_class_type;
public:
    typedef memory_database     class_type;

public:
    /// \brief Constructs a database instance from the given memory, and
    /// the optional flags
    ///
    /// \param contents Pointer to the base of the memory contents to parse. May not be NULL
    /// \param cbContents Number of bytes in the memory contents to parse
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit memory_database(char const *contents, size_t cbContents, unsigned flags = 0);
    /// \brief Constructs a database instance from the given string, and
    /// the optional flags
    ///
    /// \param contents String containing the database contents
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    template <typename S>
    explicit memory_database(S const &contents, unsigned flags = 0)
        : parent_class_type(create_database_(::stlsoft::c_str_data(contents), ::stlsoft::c_str_len(contents), flags))
    {}
#ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
    /// \brief Constructs a database instance from the given character array, and
    /// the optional flags
    ///
    /// \param contents String containing the database contents
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    template <size_t N>
    explicit memory_database(const char (&contents)[N], unsigned flags = 0)
        : parent_class_type(create_database_(&contents[0], N, flags))
    {}
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

// Implementation
private:
    static ORJDatabase const *create_database_(char const *contents, size_t cbContents, unsigned flags);

// Not to be implemented
private:
    memory_database(class_type const &);
    class_type const &operator =(class_type const &);
};

/// \brief This class implements iterator behaviour for the database classes
class database_base::const_iterator
    : public stlsoft::iterator_base<std::random_access_iterator_tag, const database_base::value_type, database_base::distance_type, database_base::const_pointer, database_base::const_reference>
{
public:
    typedef database_base::value_type        value_type;
    typedef database_base::distance_type     distance_type;
    typedef database_base::difference_type   difference_type;

private:
    friend class database_base;

    const_iterator(ORJRecordA const *record);
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
    bool equal(const_iterator const &rhs) const;

#if defined(__BORLANDC__) || \
defined(__DMC__)
    bool operator ==(const_iterator const &rhs) const;
    bool operator !=(const_iterator const &rhs) const;
#endif /* compiler */

private:
    ORJRecordA const    *m_record;
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
    mutable value_type  m_value;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

#if !defined(__BORLANDC__) && \
    !defined(__DMC__)
inline bool operator ==(database_base::const_iterator const &lhs, database_base::const_iterator const &rhs)
{
    return lhs.equal(rhs);
}

inline bool operator !=(database_base::const_iterator const &lhs, database_base::const_iterator const &rhs)
{
    return !lhs.equal(rhs);
}
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

// database_base::const_iterator

inline database_base::const_iterator::const_iterator(ORJRecordA const *record)
    : m_record(record)
{}

inline database_base::const_iterator::const_iterator()
    : m_record(NULL)
{}

inline database_base::const_iterator::const_iterator(database_base::const_iterator const &rhs)
    : m_record(rhs.m_record)
{}

inline database_base::const_iterator &database_base::const_iterator::operator =(database_base::const_iterator const &rhs)
{
    m_record = rhs.m_record;

    return *this;
}

#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
inline database_base::const_reference database_base::const_iterator::operator *() const
{
    m_value = value_type(m_record);

    return m_value;
}
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
inline database_base::value_type database_base::const_iterator::operator *() const
{
    return record(m_record);
}
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */

inline database_base::const_iterator &database_base::const_iterator::operator ++()
{
    ++m_record;

    return *this;
}

inline database_base::const_iterator database_base::const_iterator::operator ++(int)
{
    const_iterator  ret(*this);

    operator ++();

    return ret;
}

inline database_base::const_iterator &database_base::const_iterator::operator --()
{
    --m_record;

    return *this;
}

inline database_base::const_iterator database_base::const_iterator::operator --(int)
{
    const_iterator  ret(*this);

    operator --();

    return ret;
}

inline database_base::const_iterator database_base::const_iterator::operator -(database_base::const_iterator::difference_type d) const
{
    return const_iterator(&m_record[-d]);
}

inline database_base::difference_type database_base::const_iterator::operator -(database_base::const_iterator const &rhs) const
{
    return &rhs.m_record[0] - &m_record[0];
}

inline bool database_base::const_iterator::equal(database_base::const_iterator const &rhs) const
{
    return rhs.m_record == m_record;
}

#if defined(__BORLANDC__) || \
    defined(__DMC__)
inline bool database_base::const_iterator::operator ==(database_base::const_iterator const &rhs) const
{
    return equal(rhs);
}

inline bool database_base::const_iterator::operator !=(database_base::const_iterator const &rhs) const
{
    return !equal(rhs);
}
#endif /* compiler */

// file_database

#ifndef OPENRJ_NO_FILE_HANDLING
inline /* static */ ORJDatabase const *file_database::create_database_(char const *jarName, unsigned flags)
{
    ORJDatabase const   *database;
    ORJError            error;
    ORJRC               rc = ORJ_ReadDatabase(jarName, NULL, flags, &database, &error);

    if(ORJ_RC_SUCCESS != rc)
    {
        throw database_exception(rc, error);
    }

    return database;
}

inline file_database::file_database(char const *jarName, unsigned flags /* = 0 */)
    : parent_class_type(create_database_(jarName, flags))
{}
#endif /* !OPENRJ_NO_FILE_HANDLING */

// memory_database

inline /* static */ ORJDatabase const *memory_database::create_database_(char const *contents, size_t cbContents, unsigned flags)
{
    ORJDatabase const   *database;
    ORJError            error;
    ORJRC               rc = ORJ_CreateDatabaseFromMemory(contents, cbContents, NULL, flags, &database, &error);

    if(ORJ_RC_SUCCESS != rc)
    {
        throw database_exception(rc, error);
    }

    return database;
}

inline memory_database::memory_database(char const *contents, size_t cbContents, unsigned flags)
    : parent_class_type(create_database_(contents, cbContents, flags))
{}

// database_base

inline database_base::database_base(ORJDatabase const *database)
    : m_database(database)
{
    stlsoft_message_assert("Initialisng database_base with NULL database", NULL != m_database);
}

inline database_base::~database_base()
{
    ORJ_FreeDatabase(m_database);
}

inline size_t database_base::num_lines() const
{
    openrj_assert(NULL != m_database);

    return m_database->numLines;
}

inline size_t database_base::num_fields() const
{
    openrj_assert(NULL != m_database);

    return m_database->numFields;
}

inline size_t database_base::num_records() const
{
    openrj_assert(NULL != m_database);

    return m_database->numRecords;
}

inline size_t database_base::size() const
{
    return num_records();
}

inline const record database_base::operator [](size_t index) const
{
    openrj_assert(index <= num_records());

    return record(&m_database->records[index]);
}

inline database_base::const_iterator database_base::begin() const
{
    openrj_assert(NULL != m_database);

    return &m_database->records[0];
}

inline database_base::const_iterator database_base::end() const
{
    openrj_assert(NULL != m_database);

    return &m_database->records[m_database->numRecords];
}

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
inline database_base::const_reverse_iterator database_base::rbegin() const
{
    return const_reverse_iterator(end());
}

inline database_base::const_reverse_iterator database_base::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

#ifndef OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS
inline database_base::const_field_iterator database_base::fields_begin() const
{
    openrj_assert(NULL != m_database);

    return const_field_iterator(&m_database->fields[0], &m_database->fields[m_database->numFields]);
}

inline database_base::const_field_iterator database_base::fields_end() const
{
    openrj_assert(NULL != m_database);

    return const_field_iterator(&m_database->fields[m_database->numFields], &m_database->fields[m_database->numFields]);
}

# if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
inline database_base::const_reverse_field_iterator database_base::fields_rbegin() const
{
    return const_reverse_field_iterator(fields_end());
}

inline database_base::const_reverse_field_iterator database_base::fields_rend() const
{
    return const_reverse_field_iterator(fields_begin());
}
# endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* !OPENRJ_STL_DATABASE_NO_FIELD_ITERATORS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_DATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
