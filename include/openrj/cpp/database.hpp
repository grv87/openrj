/* /////////////////////////////////////////////////////////////////////////////
 * File:    database.hpp
 *
 * Purpose: Database class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
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


/* \file openrj/cpp/database.hpp Database class, in the C++ mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_H_DATABASE
#define OPENRJ_INCL_OPENRJ_CPP_H_DATABASE

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_MAJOR     1
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_MINOR     3
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_REVISION  1
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_EDIT      10
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>
#include <openrj/cpp/field.hpp>
#include <openrj/cpp/record.hpp>

#include <stlsoft_operator_bool.h>  // For "safe bool"

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

/// \brief This class represents the Open-RJ database file, once read in and parsed
class Database
{
/// \name Types
/// @{
public:
    typedef Database        class_type;
    typedef Record          value_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs a database instance from the given database file, and 
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit Database(char const *jarName, unsigned flags = 0) // throw (DatabaseException)
        : m_database(NULL)
    {
        ORJError    error;
        ORJRC       rc = ORJ_ReadDatabase(jarName, NULL, flags, &m_database, &error);

        if(ORJ_RC_SUCCESS != rc)
        {
#if !defined(ORJ_NO_EXCEPTIONS)
            // throw something here
            throw DatabaseException(rc, error);
#endif /* !ORJ_NO_EXCEPTIONS */
        }
    }
    /// \brief Closes the database
    ~Database()
    {
        if(NULL != m_database)
        {
            ORJ_FreeDatabase(m_database);
        }
    }

    /// 
    /// \brief Closes the database
    void Close()
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
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES(class_type, boolean_generator_type, boolean_type);
public:
    /// Indicates the state of the instance, i.e. whether it is contains a valid recls_info_t or not
    operator boolean_type() const
    {
        return boolean_generator_type::translate(NULL != m_database);
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

private:
    ORJDatabase const *m_database;

// Not to be implemented
private:
    Database(Database const &);
    Database const &operator =(Database const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_DATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
