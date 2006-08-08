/* /////////////////////////////////////////////////////////////////////////////
 * File:    MemoryDatabase.h
 *
 * Purpose: Definition of the MemoryDatabase class
 *
 * Created: 14th January 2005
 * Updated: 9th August 2006
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_NET_H_MEMORYDATABASE_MAJOR       1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_MEMORYDATABASE_MINOR       2
# define OPENRJ_VER_OPENRJ_CPP_NET_H_MEMORYDATABASE_REVISION    1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_MEMORYDATABASE_EDIT        7
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "Database.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace OpenRJ
{
    public __gc class Field;
    public __gc class Record;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
    /// \brief This class represents the Open-RJ database file, once read in and parsed
    public __gc class MemoryDatabase
        : public Database
    {
    /// \name Construction
    /// @{
    public:
        MemoryDatabase(String *contents); // flags == Flags::ElideBlankRecords
        MemoryDatabase(String *contents, Flags flags);
    /// @}

    /// \name Properties
    /// @{
    public:
        /// Converts the database to a string form
        String  *ToString();
    /// @}

    /// \name Implementation
    /// @{
    private:
        static ::openrj::ORJDatabaseA const *create_database_(char const *contents, size_t cbContents, unsigned int flags);
    /// @}

    /// \name Members
    /// @{
    private:
        String  *m_path;
    /// @}
    };
}

/* ////////////////////////////////////////////////////////////////////////// */
