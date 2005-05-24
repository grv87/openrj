/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/memorydatabase.hpp
 *
 * Purpose: MemoryDatabase class, in the C++ mapping of the Open-RJ library
 *
 * Created: 18th June 2004
 * Updated: 25th May 2005
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


/** \file openrj/cpp/memorydatabase.hpp MemoryDatabase class, in the C++ mapping of the Open-RJ library
 *
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_HPP_MEMORYDATABASE
#define OPENRJ_INCL_OPENRJ_CPP_HPP_MEMORYDATABASE

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_HPP_MEMORYDATABASE_MAJOR     1
# define OPENRJ_VER_OPENRJ_CPP_HPP_MEMORYDATABASE_MINOR     0
# define OPENRJ_VER_OPENRJ_CPP_HPP_MEMORYDATABASE_REVISION  1
# define OPENRJ_VER_OPENRJ_CPP_HPP_MEMORYDATABASE_EDIT      2
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/databasebase.hpp>

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

/// \brief This class opens and provides access to a memory-based Open-RJ database
class MemoryDatabase
    : public DatabaseBase
{
/// \name Types
/// @{
protected:
    typedef DatabaseBase    parent_class_type;
public:
    typedef MemoryDatabase  class_type;
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

#endif /* !OPENRJ_INCL_OPENRJ_CPP_HPP_MEMORYDATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
