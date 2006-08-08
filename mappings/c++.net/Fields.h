/* /////////////////////////////////////////////////////////////////////////////
 * File:        Fields.h
 *
 * Purpose:     Definition of the OpenRJ::Fields class.
 *
 * Created:     3rd August 2004
 * Updated:     9th August 2006
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, (c) 2004-2006. All rights reserved.
 *
 * Home:        http://www.openrj.orj/
 *
 * ////////////////////////////////////////////////////////////////////////// */


#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELDS_MAJOR    1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELDS_MINOR    5
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELDS_REVISION 1
# define OPENRJ_VER_OPENRJ_CPP_NET_H_FIELDS_EDIT     18
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace OpenRJ
{
    public __gc class Field;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */


namespace OpenRJ
{
    using System::Collections::ArrayList;
    using System::Collections::IEnumerable;
    using System::Collections::IEnumerator;

    [System::Reflection::DefaultMemberAttribute("Item")]
    public __gc class Fields
        : public IEnumerable
    {
    public:
        Fields(ArrayList *fields);

    public:
        __property int      get_Count();
        __property Field    *get_Item(int index);

    public:
        IEnumerator* GetEnumerator();

    /// \name Members
    /// @{
    private:
        ArrayList   *m_fields;
    /// @}
    };

} // namespace OpenRJ

/* ////////////////////////////////////////////////////////////////////////// */
