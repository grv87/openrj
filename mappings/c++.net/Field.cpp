/* /////////////////////////////////////////////////////////////////////////////
 * File:        Field.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Field class
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

//#include "Database.h"
//#include "Record.h"
#include "Field.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
    Field::Field(::openrj::ORJFieldA const *field, ::OpenRJ::Record *record)
        : m_field(field)
        , m_record(record)
    {}

    String *Field::get_Name()
    {
        return new String(m_field->name.ptr, 0, m_field->name.len);
    }

    String *Field::get_Value()
    {
        return new String(m_field->value.ptr, 0, m_field->value.len);
    }

    ::OpenRJ::Record *Field::get_Record()
    {
        return m_record;
    }

    String *Field::ToString()
    {
        return String::Concat(get_Name(), new String("="), get_Value());
    }
}

/* ////////////////////////////////////////////////////////////////////////// */
