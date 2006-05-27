/* /////////////////////////////////////////////////////////////////////////////
 * File:        Fields.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Fields class
 *
 * Created:     3rd August 2004
 * Updated:     24th May 2006
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, (c) 2004-2006. All rights reserved.
 *
 * Home:        http://www.openrj.orj/
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "Fields.h"
#include "Field.h"
#include "OpenRJException.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */


namespace OpenRJ
{
    Fields::Fields(ArrayList *fields)
        : m_fields(fields)
    {}

    int Fields::get_Count()
    {
        return m_fields->get_Count();
    }

    Field *Fields::get_Item(int index)
    {
        if( index < 0 ||
            !(index < get_Count()))
        {
            throw new IndexOutOfRangeException();
        }

        return static_cast<Field*>(m_fields->get_Item(index));
    }

    IEnumerator *Fields::GetEnumerator()
    {
        return new dotnetstl::ArrayListEnumerator(m_fields);
    }


} // namespace OpenRJ

/* ////////////////////////////////////////////////////////////////////////// */
