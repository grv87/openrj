/* /////////////////////////////////////////////////////////////////////////////
 * File:    Record.h
 *
 * Purpose: Definition of the OpenRJ::Record class
 *
 * Created: 3rd August 2004
 * Updated: 9th August 2006
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


#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_NET_H_RECORD_MAJOR       1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_RECORD_MINOR       9
# define OPENRJ_VER_OPENRJ_CPP_NET_H_RECORD_REVISION    1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_RECORD_EDIT        18
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "OpenRJ.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace OpenRJ
{
    public __gc class Field;
    public __gc class Fields;
    public __gc class Database;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
    using namespace System;
    using System::Collections::ArrayList;
    using System::Collections::IEnumerable;
    using System::Collections::IEnumerator;

    [System::Reflection::DefaultMemberAttribute("Item")]
    public __gc __sealed class Record
    {
    /// \name Member Types
    /// @{
    protected:
        typedef Fields  Fields_t;
        typedef Fields  *PFields_t;
    /// @}

    /// \name Construction
    /// @{
    private public:
        Record(::openrj::ORJRecordA const *record, ::OpenRJ::Database *database);
    /// @}

    /// \name Properties
    /// @{
    public:
        /// The record's comment
        __property String               *get_Comment();

        /// The number of fields in the record
        __property int                  get_NumFields();

        /// The record within which this record resides
        __property ::OpenRJ::Database   *get_Database();

        /// Enumerate the fields in the record
        IEnumerator                     *GetEnumerator();

        /// Indicates whether a record has one or more fields of the given name
        int                             HasField(String *fieldName);

        /// Returns the value associated with the (first) field with the
        /// given name.
        String                          *GetFieldValue(String *fieldName);
        /// Returns the value associated with the (first) field with the
        /// given name, or the given default if no fields exist with that
        /// name.
        String                          *GetFieldValue(String *fieldName, String *defaultValue);

        /// Access the fields by index
        __property Field                *get_Item(int index);
#ifdef INDEXER_RETURNS_STRING
        __property String               *get_Item(String *fieldName);
#else /* ? INDEXER_RETURNS_STRING */
        __property Field                *get_Item(String *fieldName);
#endif /* INDEXER_RETURNS_STRING */

        /// A collection of all fields in the database
        virtual PFields_t               GetNamedFields(String *fieldName);

        /// Converts the record to a string form
        String                          *ToString();
    /// @}

    /// \name Implementation
    /// @{
    private:
        int     HasField_(char const *fieldName);
        Fields  *GetNamedFields_(char const *fieldName);
        String  *GetFieldValue_(char const *fieldName);
        String  *GetFieldValue_(char const *fieldName, char const *defaultValue);
    /// @}

    /// \name Members
    /// @{
    private:
        ::openrj::ORJRecordA const  *m_record;
        ::OpenRJ::Database          *m_database;
        ArrayList                   *m_fields;
    };
    /// @}
}

/* ////////////////////////////////////////////////////////////////////////// */
