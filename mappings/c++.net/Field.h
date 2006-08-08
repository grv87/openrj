/* /////////////////////////////////////////////////////////////////////////////
 * File:    Field.h
 *
 * Purpose: Definition of the Field class
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
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELD_MAJOR    1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELD_MINOR    2
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELD_REVISION 1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELD_EDIT     14
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
    public __gc class Record;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace OpenRJ
{
    using namespace System;

    public __gc __sealed class Field
    {
    /// \name Construction
    /// @{
    private public:
        Field(::openrj::ORJFieldA const *field, ::OpenRJ::Record *record);
    /// @}

    /// \name Properties
    /// @{
    public:
        /// The name of the field
        __property String           *get_Name();
        /// The value of the field
        __property String           *get_Value();

        /// The record within which this field resides
        __property ::OpenRJ::Record *get_Record();

        /// Converts the field to a string form
        String                      *ToString();
    /// @}

    /// \name Members
    /// @{
    public private:
        ::openrj::ORJFieldA const   *m_field;
    private:
        ::OpenRJ::Record            *m_record;
    /// @}
    };
}

/* ////////////////////////////////////////////////////////////////////////// */
