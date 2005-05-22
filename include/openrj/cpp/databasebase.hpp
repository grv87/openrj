/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/databasebase.hpp
 *
 * Purpose: DatabaseBase class, in the C++ mapping of the Open-RJ library
 *
 * Created: 12th April 2005
 * Updated: 23rd May 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2005, Matthew Wilson and Synesis Software
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


/* \file openrj/cpp/databasebase.hpp DatabaseBase class, in the C++ mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_HPP_DATABASEBASE
#define OPENRJ_INCL_OPENRJ_CPP_HPP_DATABASEBASE

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_HPP_DATABASEBASE_MAJOR       1
# define OPENRJ_VER_OPENRJ_CPP_HPP_DATABASEBASE_MINOR       0
# define OPENRJ_VER_OPENRJ_CPP_HPP_DATABASEBASE_REVISION    1
# define OPENRJ_VER_OPENRJ_CPP_HPP_DATABASEBASE_EDIT        2
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>
#include <openrj/cpp/field.hpp>
#include <openrj/cpp/record.hpp>

#include <stlsoft/operator_bool_adaptor.hpp>

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

/// \brief This class implements the common database manipulation for the \c FileDatabase
/// and \c MemoryDatabase classes.
class DatabaseBase
    : public ::stlsoft::operator_bool_adaptor<DatabaseBase>
{
/// \name Types
/// @{
public:
    typedef DatabaseBase    class_type;
    typedef Record          value_type;
/// @}

/// \name Construction
/// @{
protected:
    /// \brief Constructs a database instance from the given database structure
    ///
    /// \param database The pointer to the database structure
    explicit DatabaseBase(ORJDatabase const *database)
        : m_database(database)
    {}
public:
    /// \brief Closes the database
    virtual ~DatabaseBase()
    {
        Close();
    }

    /// \brief Closes the database
    virtual void Close()
    {
        if(NULL != m_database)
        {
            ORJ_FreeDatabase(m_database);
            m_database = NULL;
        }
    }
/// @}

/// \name State
/// @{
public:
    /// Indicates whether the database is open
    bool is_open() const
    {
        return NULL != m_database;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the number of lines in the database
    size_t GetNumLines() const
    {
        openrj_assert(NULL != m_database);

        return ORJ_Database_GetNumLinesA(m_database);
    }
    /// Returns the number of fields in the database
    size_t GetNumFields() const
    {
        openrj_assert(NULL != m_database);

        return ORJ_Database_GetNumFieldsA(m_database);
    }
    /// Returns the number of records in the database
    size_t GetNumRecords() const
    {
        openrj_assert(NULL != m_database);

        return ORJ_Database_GetNumRecordsA(m_database);
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief Returns the requested record
    ///
    /// \param index The index of the record to be returned. Must be less than the
    /// value returned by GetNumRecords()
    Record operator [](size_t index) const
    {
        openrj_assert(index <= GetNumRecords());

        return Record(m_database->records[index]);
    }
/// @}

/// \name Members
/// @{
private:
    ORJDatabase const   *m_database;
/// @}

// Not to be implemented
private:
    DatabaseBase(DatabaseBase const &);
    DatabaseBase const &operator =(DatabaseBase const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_HPP_DATABASEBASE */

/* ////////////////////////////////////////////////////////////////////////// */
