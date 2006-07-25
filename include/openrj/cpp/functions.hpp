/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/cpp/functions.hpp
 *
 * Purpose: Helper functions for the Open-RJ C++ mapping
 *
 * Created: 12th April 2005
 * Updated: 14th July 2006
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


/** \file openrj/cpp/functions.hpp
 *
 * \brief [C++ only] Helper functions for the Open-RJ C++ mapping
 */

#ifndef OPENRJ_INCL_OPENRJ_CPP_HPP_FUNCTIONS
#define OPENRJ_INCL_OPENRJ_CPP_HPP_FUNCTIONS

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_HPP_FUNCTIONS_MAJOR      1
# define OPENRJ_VER_OPENRJ_CPP_HPP_FUNCTIONS_MINOR      1
# define OPENRJ_VER_OPENRJ_CPP_HPP_FUNCTIONS_REVISION   3
# define OPENRJ_VER_OPENRJ_CPP_HPP_FUNCTIONS_EDIT       8
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/cpp/openrj.hpp>
#include <openrj/cpp/field.hpp>
#include <openrj/cpp/record.hpp>
#include <openrj/cpp/databasebase.hpp>

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <stdio.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
namespace cpp
{

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
namespace helper
{
    inline Record throw_for_missing_Record(char const *reason, char const *recordName)
    {
        try
        {
            const size_t                cchReason       =   ::strlen(reason);
            const size_t                cchRecordName   =   ::strlen(recordName);
            stlsoft::auto_buffer<char>  message(cchReason + 2 + cchRecordName + 1);

            if(message.empty())
            {
                goto plain_throw;
            }
            else
            {
                ::sprintf(&message[0], "%*s: %*s", (int)cchReason, reason, (int)cchRecordName, recordName);

                throw ::std::out_of_range(message.data());
            }
        }
        catch(std::out_of_range &)
        {
            throw;
        }
        catch(...)
        {
plain_throw:
            throw ::std::out_of_range(reason);
        }

        return Record();
    }

} // namespace helper
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

/// \brief Looks up the named field in a record, or returns a default value if not found
///
/// \param fieldName The named of the field to be searched for
/// \param r0 The record to be searched
/// \param defaultValue The default value to be used if the named field is not found in the record
///
/// \return The value matching the field found in r0, or \c defaultValue if not found
inline String Lookup(char const *fieldName, Record const &r0, char const *defaultValue)
{
    return r0.HasField(fieldName) ? r0[fieldName] : defaultValue;
}

/// \brief Looks up the named field in one of two records, or throws exception if not found in either
///
/// \param fieldName The named of the field to be searched for
/// \param r0 The first record to be searched
/// \param r1 The second record to be searched
///
/// \return The value matching the field found in r0 or r1
///
/// \note If the field is not found in either record, an instance of std::out_of_range exception is thrown
inline String Lookup(char const *fieldName, Record const &r0, Record const &r1)
{
    return r0.HasField(fieldName) ? r0[fieldName] : r1[fieldName];
}

/// \brief Looks up the named field in one of two records, or returns a default value if not found in either
///
/// \param fieldName The named of the field to be searched for
/// \param r0 The first record to be searched
/// \param r1 The second record to be searched
/// \param defaultValue The default value to be used if the named field is not found in either record
///
/// \return The value matching the field found in r0 or r1, or \c defaultValue if not found in either
inline String Lookup(char const *fieldName, Record const &r0, Record const &r1, char const *defaultValue)
{
    return r0.HasField(fieldName) ? r0[fieldName] : r1.HasField(fieldName) ? r1[fieldName] : defaultValue;
}


inline Record FindFirstRecordWithFieldName(DatabaseBase const &db, char const *name)
{
    { for(size_t i = 0; i < db.GetNumRecords(); ++i)
    {
        if(db[i].HasField(name))
        {
            return db[i];
        }
    }}

    return helper::throw_for_missing_Record("Matching record not found", name);
}

template <typename S>
inline Record FindFirstRecordWithFieldName(DatabaseBase const &db, S const &name)
{
    return FindFirstRecordWithFieldName(db, ::stlsoft::c_str_ptr(name));
}

#if 0
inline 

inline Record find_first_record_with_field(DatabaseBase const &db, Field const &f)
{
    { for(size_t i = 0; i < db.GetNumRecords(); ++i)
    {
        if(db[i].HasFieldWithValue(name, value))
        {
            return db[i];
        }
    }

    throw ::std::out_of_range("Matching record not found");

    return Record();
}


inline Record find_first_record_match(DatabaseBase const &db, Field const &f)
{
}

template <typename S>
inline Record find_first_record_match(DatabaseBase const &db, S const &name)
{
}

inline Record find_first_record_match(DatabaseBase const &db, Field const &f)
{
}

#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace cpp
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_CPP_HPP_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
