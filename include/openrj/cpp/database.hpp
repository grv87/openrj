/* /////////////////////////////////////////////////////////////////////////////
 * File:    database.hpp
 *
 * Purpose: Database class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
 * Updated: 19th February 2005
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
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_MINOR     5
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_REVISION  3
# define OPENRJ_VER_OPENRJ_CPP_H_DATABASE_EDIT      16
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
    /// \brief Constructs a database instance from the given database file, and
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
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

#ifndef OPENRJ_NO_FILE_HANDLING
/// \brief This class represents the Open-RJ database file, once read in and parsed
class FileDatabase
    : public DatabaseBase
{
/// \name Types
/// @{
protected:
    typedef DatabaseBase    parent_class_type;
public:
    typedef FileDatabase    class_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs a database instance from the given database file, and
    /// the optional flags
    ///
    /// \param jarName The database name
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit FileDatabase(char const *jarName, unsigned flags = 0) // throw (DatabaseException)
        : parent_class_type(create_database_(jarName, flags))
        , m_name(alloc_name_(jarName))
    {}
    /// \brief Closes the database
    virtual ~FileDatabase()
    {
        Close();

        free(m_name);
    }

    /// \brief Closes the database
    virtual void Close()
    {
        this->parent_class_type::Close();
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the path of the database
    char const *GetPath() const
    {
        return m_name;
    }
/// @}

/// \name Implementation
/// @{
private:
    static char *alloc_name_(char const *s)
    {
        char    *new_s  =   strdup(s);

#if !defined(ORJ_NO_EXCEPTIONS)
        if(NULL == new_s)
        {
            throw std::bad_alloc();
        }
#endif /* !ORJ_NO_EXCEPTIONS */

        return new_s;
    }

    static ORJDatabase const *create_database_(char const *jarName, unsigned flags = 0) // throw (DatabaseException)
    {
        ORJDatabase const   *database;
        ORJError            error;
        ORJRC               rc = ORJ_ReadDatabase(jarName, NULL, flags, &database, &error);

        if(ORJ_RC_SUCCESS != rc)
        {
#if !defined(ORJ_NO_EXCEPTIONS)
            // throw something here
            throw DatabaseException(rc, error);
#endif /* !ORJ_NO_EXCEPTIONS */
        }

        return database;
    }

/// @}

/// \name Members
/// @{
private:
    char    *const  m_name;
/// @}

// Not to be implemented
private:
    FileDatabase(class_type const &);
    class_type &operator =(class_type const &);
};

typedef FileDatabase    Database;
#endif /* !OPENRJ_NO_FILE_HANDLING */

/// \brief This class opens and provides access to a memory-based Open-RJ database
class MemoryDatabase
    : public DatabaseBase
{
/// \name Types
/// @{
protected:
    typedef DatabaseBase    parent_class_type;
public:
    typedef MemoryDatabase    class_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs a database instance from the given memory, and
    /// the optional flags
    ///
    /// \param contents Pointer to the base of the memory contents to parse. May not be NULL
    /// \param cbContents Number of bytes in the memory contents to parse
    /// \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
    explicit MemoryDatabase(char const *contents, size_t cbContents, unsigned flags = 0) // throw (DatabaseException)
        : parent_class_type(create_database_(contents, cbContents, flags))
    {}
    /// \brief Closes the database
    virtual ~MemoryDatabase()
    {
        Close();
    }

    /// \brief Closes the database
    virtual void Close()
    {
        this->parent_class_type::Close();
    }
/// @}

/// \name Implementation
/// @{
private:
    static ORJDatabase const *create_database_(char const *contents, size_t cbContents, unsigned flags = 0) // throw (DatabaseException)
    {
        ORJDatabase const   *database;
        ORJError            error;
        ORJRC               rc = ORJ_CreateDatabaseFromMemory(contents, cbContents, NULL, flags, &database, &error);

        if(ORJ_RC_SUCCESS != rc)
        {
#if !defined(ORJ_NO_EXCEPTIONS)
            // throw something here
            throw DatabaseException(rc, error);
#endif /* !ORJ_NO_EXCEPTIONS */
        }

        return database;
    }
/// @}

// Not to be implemented
private:
    MemoryDatabase(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_H_DATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
