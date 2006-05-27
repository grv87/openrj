/* /////////////////////////////////////////////////////////////////////////////
 * File:    OpenRJException.h
 *
 * Purpose: Definition of the OpenRJ::Database class
 *
 * Created: 3rd August 2004
 * Updated: 15th March 2006
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


#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "OpenRJ.h"
#include "Database.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
    using namespace System;

    public __gc class OpenRJException
        : public System::ApplicationException
    {
    public:
        typedef System::ApplicationException    parent_class_type;
    public:
        OpenRJException(String *message);
    };

    public __gc class DatabaseException
        : public OpenRJException
    {
    public:
        typedef OpenRJException parent_class_type;
    public:
        DatabaseException(::openrj::ORJRC rc, ::openrj::ORJError err);
        DatabaseException(String *message, ::openrj::ORJRC rc, ::openrj::ORJError err);

    public:
        /// The Open-RJ error code associated with the exception
        __property Database::ErrorCode      get_ErrorCode();
        /// The parse error associated with the exception
        ///
        /// \note This is only meaningful if the ErrorCode is ORJRC.ParseError
        __property Database::ParseErrorCode get_ParseError();
        /// The line at which the parse error occurred
        ///
        /// \note This is only meaningful if the ErrorCode is ORJRC.ParseError
        __property int                      get_ParseLine();
        /// The column at which the parse error occurred
        ///
        /// \note This is only meaningful if the ErrorCode is ORJRC.ParseError
        __property int                      get_ParseColumn();

    public:
        String                              *ToString();

    private:
        ::openrj::ORJRC     m_rc;
        ::openrj::ORJError  m_error;
    };

    public __gc class UnknownFieldNameException
        : public OpenRJException
    {
    public:
        typedef OpenRJException parent_class_type;
    public:
        UnknownFieldNameException(String *fieldName);
        UnknownFieldNameException(String *fieldName, String *message);

    public:
        __property String   *get_FieldName();

    private:
        String  *m_fieldName;
    };
}

/* ////////////////////////////////////////////////////////////////////////// */
