/* /////////////////////////////////////////////////////////////////////////////
 * File:    database.hpp
 *
 * Purpose: Database class, in the STL mapping of the Open-RJ library
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


/* \file openrj/stl/database.hpp Database class, in the STL mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_H_DATABASE
#define OPENRJ_INCL_OPENRJ_STL_H_DATABASE

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_H_DATABASE_MAJOR     1
# define OPENRJ_VER_OPENRJ_STL_H_DATABASE_MINOR     4
# define OPENRJ_VER_OPENRJ_STL_H_DATABASE_REVISION  2
# define OPENRJ_VER_OPENRJ_STL_H_DATABASE_EDIT      13
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#if defined(ORJ_NO_EXCEPTIONS)
# error The Open-RJ STL mapping is not compilable in the absence of exception
#endif /* ORJ_NO_EXCEPTIONS */

#include <iterator>

#include <stlsoft_iterator.h>
#include <stlsoft_proxy_iterator.h>

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

/// \brief This class the database
class database
{
private:
    struct proxy_traits_type
    {
        static field make_value(ORJField const &field_)
        {
            return field(&field_);
        }
    };
public:
    /// This type
    typedef database                        class_type;
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
#if !defined(__DMC__)
    /// The non-mutating (const) iterator type for enumerating all fields in the database
    typedef stlsoft::proxy_iterator<const ORJField
                                ,   field
                                ,   proxy_traits_type
                                ,   std::random_access_iterator_tag
                                >           const_field_iterator;
#endif /* !__DMC__ */
    /// The distance type
    typedef size_t                          distance_type;

public:
    /// The non-mutating (const) iterator type
    class const_iterator
        : public stlsoft::iterator_base<std::random_access_iterator_tag, const value_type, distance_type, const_pointer, const_reference>
    {
    public:
        typedef record              value_type;

    private:
        friend class database;

        const_iterator(ORJRecordA const *record)
            : m_record(record)
        {}
    public:
        const_iterator()
            : m_record(NULL)
        {}
        const_iterator(const_iterator const &rhs)
            : m_record(rhs.m_record)
        {}

        const_iterator &operator =(const_iterator const &rhs)
        {
            m_record = rhs.m_record;

            return *this;
        }

    public:
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
        const_reference operator *() const
        {
            m_value = value_type(m_record);

            return m_value;
#else /* ? OPENRJ_STL_ITERATOR_HOLDS_VALUE */
        value_type operator *() const
        {
            return record(m_record);
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
        }
        const_iterator &operator ++()
        {
            ++m_record;

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
            return const_iterator(&m_record[d]);
        }
        difference_type operator -(const_iterator const &rhs) const
        {
            return &rhs.m_record[0] - &m_record[0];
        }

    public:
        bool equal(const_iterator const &rhs) const
        {
            return rhs.m_record == m_record;
        }

#if defined(__BORLANDC__) || \
    defined(__DMC__)
        bool operator ==(const_iterator const &rhs)
        {
            return equal(rhs);
        }

        bool operator !=(const_iterator const &rhs)
        {
            return !equal(rhs);
        }
#endif /* compiler */

    private:
        ORJRecordA const    *m_record;
#ifdef OPENRJ_STL_ITERATOR_HOLDS_VALUE
        mutable value_type  m_value;
#endif /* OPENRJ_STL_ITERATOR_HOLDS_VALUE */
    };

//  typedef value_type const        &const_iterator;

public:
    /// \brief Constructs a database instance from the given database file, and 
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit database(char const *jarName, unsigned flags = 0)
        : m_database(create_database_(jarName, flags))
    {}
    /// \brief Constructs a database instance from the given database file, and 
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    template <typename S>
    explicit database(S const &jarName, unsigned flags = 0)
        : m_database(create_database_(::stlsoft::c_str_ptr(jarName), flags))
    {}
    /// \brief Closes the database
    ~database()
    {
        ORJ_FreeDatabase(m_database);
    }

public:
    /// Returns the number of lines in the database
    size_t num_lines() const
    {
        openrj_assert(NULL != m_database);

        return m_database->numLines;
    }
    /// Returns the number of fields in the database
    size_t num_fields() const
    {
        openrj_assert(NULL != m_database);

        return m_database->numFields;
    }
    /// Returns the number of records in the database
    size_t num_records() const
    {
        openrj_assert(NULL != m_database);

        return m_database->numRecords;
    }

    /// Returns the number of records in the database
    size_t size() const
    {
        return num_records();
    }

public:
    /// \brief Returns the requested record
    ///
    /// \param index The index of the record to be returned. Must be less than the 
    /// value returned by GetNumRecords()
    record operator [](size_t index) const
    {
        openrj_assert(index <= num_records());

        return record(&m_database->records[index]);
    }

public:
    const_iterator begin() const
    {
        openrj_assert(NULL != m_database);

        return &m_database->records[0];
    }
    const_iterator end() const
    {
        openrj_assert(NULL != m_database);

        return &m_database->records[m_database->numRecords];
    }
#if !defined(__DMC__)
    const_field_iterator fields_begin() const
    {
        openrj_assert(NULL != m_database);

        return const_field_iterator(&m_database->fields[0], &m_database->fields[m_database->numFields]);
    }
    const_field_iterator fields_end() const
    {
        return const_field_iterator();
    }
#endif /* !__DMC__ */

// Implementation
private:
    static ORJDatabase const *create_database_(char const *jarName, unsigned flags)
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

// Members
private:
    ORJDatabase const *m_database;

// Not to be implemented
private:
    database(database const &);
    database const &operator =(database const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

#if !defined(__BORLANDC__) && \
    !defined(__DMC__)
inline bool operator ==(database::const_iterator const &lhs, database::const_iterator const &rhs)
{
    return lhs.equal(rhs);
}

inline bool operator !=(database::const_iterator const &lhs, database::const_iterator const &rhs)
{
    return !lhs.equal(rhs);
}
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_H_DATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
