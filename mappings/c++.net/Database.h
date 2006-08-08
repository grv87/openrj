/* /////////////////////////////////////////////////////////////////////////////
 * File:    Database.h
 *
 * Purpose: Definition of the Database class
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
# define OPENRJ_VER_OPENRJ_CPP_NET_H_DATABASE_MAJOR     1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_DATABASE_MINOR     5
# define OPENRJ_VER_OPENRJ_CPP_NET_H_DATABASE_REVISION  1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_DATABASE_EDIT      17
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
    public __gc class Record;
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
    /// \brief This class represents the Open-RJ database file, once read in and parsed
    public __gc class Database
      : public IEnumerable
    {
    /// \name Member Types
    /// @{
    protected:
        typedef Fields  Fields_t;
        typedef Fields  *PFields_t;
    /// @}

    /// \name Construction
    /// @{
    protected:
        Database(::openrj::ORJDatabaseA const *database);
    public:
        ~Database();
    /// @}

    /// \name Values
    /// @{
        [Flags]
        __value enum Flags
        {
                OrderFields             =   ::openrj::ORDER_FIELDS
            ,   ElideBlankRecords       =   ::openrj::ELIDE_BLANK_RECORDS
            ,   IgnoreCaseOnLookup      =   ::openrj::IGNORE_CASE_ON_LOOKUP
            ,   NoReinterpretFieldIds   =   ::openrj::NO_REINTERPRET_FIELD_IDS
        };

        __value enum ErrorCode
        {
                Success                 =   ::openrj::ORJ_RC_SUCCESS                          /*!< Operation was successful                                   */
            ,   CannotOpenJarFile       =   ::openrj::ORJ_RC_CANNOTOPENJARFILE                /*!< The given file does not exist, or cannot be accessed       */
            ,   NoRecords               =   ::openrj::ORJ_RC_NORECORDS                        /*!< The database file contained no records                     */
            ,   OutOfMemory             =   ::openrj::ORJ_RC_OUTOFMEMORY                      /*!< The API suffered memory exhaustion                         */
            ,   BadFileRead             =   ::openrj::ORJ_RC_BADFILEREAD                      /*!< A read operation failed                                    */
            ,   ParseError              =   ::openrj::ORJ_RC_PARSEERROR                       /*!< Parsing of the database file failed due to a syntax error  */
            ,   InvalidIndex            =   ::openrj::ORJ_RC_INVALIDINDEX                     /*!< An invalid index was specified                             */
            ,   Unexpected              =   ::openrj::ORJ_RC_UNEXPECTED                       /*!< An unexpected condition was encountered                    */
            ,   InvalidContent          =   ::openrj::ORJ_RC_INVALIDCONTENT                   /*!< The database file contained invalid content                */
        };

        __value enum ParseErrorCode
        {
                ParseSuccess            =   ::openrj::ORJ_PARSE_SUCCESS                       /*!< Parsing was successful                                                         */
            ,   RecordSeparatorInContinuation               =   ::openrj::ORJ_PARSE_RECORDSEPARATORINCONTINUATION /*!< A record separator was encountered during a content line continuation          */
            ,   UnfinishedLine          =   ::openrj::ORJ_PARSE_UNFINISHEDLINE                /*!< The last line in the database was not terminated by a line-feed                */
            ,   UnfinishedField         =   ::openrj::ORJ_PARSE_UNFINISHEDFIELD               /*!< The last record in the database file was not terminated by a record separator  */
            ,   UnfinishedRecord        =   ::openrj::ORJ_PARSE_UNFINISHEDRECORD              /*!< The last record in the database file was not terminated by a record separator  */
        };
    /// @}

    /// \name Operations
    /// @{
    private:
        void Close();
    protected:
        void Dispose();
    /// @}

    /// \name Properties
    /// @{
    public:
        /// The number of lines in the database
        __property int                  get_NumLines();
        /// The number of fields in the database
        __property int                  get_NumFields();
        /// The number of records in the database
        __property int                  get_NumRecords();

        /// Enumerate the records in the database
        IEnumerator                     *GetEnumerator();

        /// Access the records by index
        __property virtual Record       *get_Item(int index);

        /// A collection of all fields in the database
        __property virtual PFields_t    get_Fields();

        /// A collection of all fields in the database
        virtual PFields_t               GetNamedFields(String *fieldName);
    /// @}

    /// \name Members
    /// @{
    private:
        ::openrj::ORJDatabaseA const    *m_database;
        ArrayList                       *m_records;
        ArrayList                       *m_fields;
    /// @}
    };
}

/* ////////////////////////////////////////////////////////////////////////// */
