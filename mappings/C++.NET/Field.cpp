// Implementation file for OpenRJ::Field class

#include "stdafx.h"

//#include "Database.h"
//#include "Record.h"
#include "Field.h"

namespace OpenRJ
{
	String *Field::get_Name()
	{
		return new String(m_field->name.ptr);
	}

	String *Field::get_Value()
	{
		return new String(m_field->value.ptr);
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
