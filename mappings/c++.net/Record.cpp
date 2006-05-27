/* /////////////////////////////////////////////////////////////////////////////
 * File:    Record.cpp
 *
 * Purpose: Implementation file for OpenRJ::Record class
 *
 * Created: 3rd August 2004
 * Updated: 13th March 2006
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


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "Record.h"
#include "Field.h"
#include "Fields.h"
#include "Database.h"
#include "OpenRJException.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace OpenRJ
{
    Record::Record(::openrj::ORJRecordA const *record, ::OpenRJ::Database *database)
        : m_record(record)
        , m_database(database)
        , m_fields(new ArrayList(record->numFields))
    {
        ::openrj::ORJFieldA const   *begin  =   &record->fields[0];
        ::openrj::ORJFieldA const   *end    =   &record->fields[record->numFields];

        for(; begin != end; ++begin)
        {
            m_fields->Add(new Field(begin, this));
        }
    }

    String *Record::get_Comment()
    {
        return new String(m_record->comment.ptr, 0, m_record->comment.len);
    }

    int Record::get_NumFields()
    {
        return m_record->numFields;
    }

    ::OpenRJ::Database *Record::get_Database()
    {
        return m_database;
    }

    ::OpenRJ::Field *Record::get_Item(int index)
    {
        if( index < 0 ||
            !(index < get_NumFields()))
        {
            throw new IndexOutOfRangeException();
        }

        return static_cast<Field*>(m_fields->get_Item(index));
    }

    int Record::HasField(String *fieldName)
    {
        return this->HasField_(::dotnetstl::c_string_accessor<char>(fieldName));
    }

    int Record::HasField_(char const *fieldName)
    {
        int                         num     =   0;
        ::openrj::ORJFieldA const   *pField =   ::openrj::ORJ_Record_FindNextFieldA(m_record, NULL, fieldName, NULL);

        for(; NULL != pField; ++num)
        {
            pField = ::openrj::ORJ_Record_FindNextFieldA(m_record, pField, fieldName, NULL);
        }

        return num;
    }

// TODO: Show how, when using the String* returning form (using new String(pField->value.ptr, 0, pField->value.len);)
// that it confuses the C# client. :-(

#ifdef INDEXER_RETURNS_STRING
    String *Record::get_Item(String *fieldName)
#else /* ? INDEXER_RETURNS_STRING */
    ::OpenRJ::Field *Record::get_Item(String *fieldName)
#endif /* INDEXER_RETURNS_STRING */
    {
        ::openrj::ORJFieldA const   *pField =   ::openrj::ORJ_Record_FindFieldByNameA(m_record, ::dotnetstl::c_string_accessor<char>(fieldName), NULL);

        if(NULL == pField)
        {
            String  *message = String::Concat(new String("Record does not contain a field named \""), fieldName, "\"");

            throw new UnknownFieldNameException(fieldName, message);
        }

        // Now find our internal field that is pointing to that
        Field   *field  =   NULL;

        for(int i = 0; i < m_fields->get_Count(); ++i)
        {
            Field   *field2 =   static_cast<Field*>(m_fields->get_Item(i));

            if(field2->m_field == pField)
            {
                field = field2;
                break;
            }
        }

        if(NULL == field)
        {
            throw new ApplicationException("Unexpected condition");
        }

#ifdef INDEXER_RETURNS_STRING
        return new String(pField->value.ptr, 0, pField->value.len);
#else /* ? INDEXER_RETURNS_STRING */
        return field;
#endif /* INDEXER_RETURNS_STRING */
    }

    Fields *Record::GetNamedFields(String *fieldName)
    {
        return this->GetNamedFields_(::dotnetstl::c_string_accessor<char>(fieldName));
    }

    Fields *Record::GetNamedFields_(char const *fieldName)
    {
        size_t      numFields   =   m_record->numFields;
        ArrayList   *fields     =   new ArrayList(numFields);

        for(int i = 0; i < m_fields->get_Count(); ++i)
        {
            Field                       *field  =   static_cast<Field*>(m_fields->get_Item(i));
            ::openrj::ORJFieldA const   *pField =   field->m_field;

            if(pField == ORJ_Record_FindNextFieldA(m_record, (0 == i) ? NULL : (pField - 1), fieldName, NULL))
            {
                fields->Add(field);
            }
        }

        return new Fields(fields);
    }

    IEnumerator *Record::GetEnumerator()
    {
        return new ::dotnetstl::ArrayListEnumerator(m_fields);
    }

    String *Record::ToString()
    {
//      String  *s =

        return "";
    }
}

/* ////////////////////////////////////////////////////////////////////////// */
