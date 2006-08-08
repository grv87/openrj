/* /////////////////////////////////////////////////////////////////////////////
 * File:        Database.cpp
 *
 * Purpose:     Implementation file for OpenRJ::Database class
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

#include "Database.h"
#include "Record.h"
#include "Fields.h"
#include "Field.h"
#include "OpenRJException.h"

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */


namespace OpenRJ
{
    Database::Database(::openrj::ORJDatabaseA const *database)
        : m_database(database)
        , m_records(NULL)
        , m_fields(NULL)
    {
        int numFields   =   0;

        m_records   =   new ArrayList(m_database->numRecords);

        { ::openrj::ORJRecordA const    *begin  =   &m_database->records[0];
          ::openrj::ORJRecordA const    *end    =   &m_database->records[m_database->numRecords];
        for(; begin != end; ++begin)
        {
            numFields += begin->numFields;

            m_records->Add(new Record(begin, this));
        }}

        DOTNETSTL_ASSERT(numFields == m_database->numFields);

        m_fields    =   new ArrayList(m_database->numFields);

        IEnumerator *en =   m_records->GetEnumerator();
        for(en->Reset(); en->MoveNext(); )
        {
            Record  *record =   dotnetstl::check_cast<Record*>(en->get_Current());

            IEnumerator *en2    =   record->GetEnumerator();

            for(en2->Reset(); en2->MoveNext(); )
            {
				Field	*field	=	dotnetstl::check_cast<Field*>(en2->get_Current());

                m_fields->Add(field);
            }
        }
/*
        foreach 

        { ::openrj::ORJFieldA const     *begin  =   &m_database->fields[0];
          ::openrj::ORJFieldA const     *end    =   &m_database->fields[m_database->numFields];
        for(; begin != end; ++begin)
        {
            m_fields->Add(new Field(begin, this));
        }}
*/
    }

    Database::~Database()
    {
        Close();
    }

    void Database::Close()
    {
        if(NULL != m_database)
        {
            ::openrj::ORJ_FreeDatabaseA(m_database);

            m_database = NULL;
        }
    }

    void Database::Dispose()
    {
        Close();
    }

    int Database::get_NumLines()
    {
        return m_database->numLines;
    }

    int Database::get_NumFields()
    {
        return m_database->numFields;
    }

    int Database::get_NumRecords()
    {
        return m_database->numRecords;
    }

    IEnumerator *Database::GetEnumerator()
    {
        return new ::dotnetstl::ArrayListEnumerator(m_records);
    }

    Record *Database::get_Item(int index)
    {
        if( index < 0 ||
            !(index < get_NumRecords()))
        {
            throw new IndexOutOfRangeException();
        }

        return dotnetstl::check_cast<Record*>(m_records->get_Item(index));
    }

    Fields *Database::get_Fields()
    {
        return new Fields_t(m_fields);
    }

    Fields *Database::GetNamedFields(String *fieldName)
    {
        size_t      numFields   =   m_database->numFields;
        ArrayList   *fields     =   new ArrayList(numFields);

        for(int i = 0; i < m_records->get_Count(); ++i)
        {
            Record      *record =   dotnetstl::check_cast<Record*>(m_records->get_Item(i));
            PFields_t   fields2	=   record->GetNamedFields(fieldName);

            for(int j = 0; j < fields2->get_Count(); ++j)
            {
                fields->Add(fields2->get_Item(j));
            }
        }

        return new Fields_t(fields);
    }

} // namespace OpenRJ

/* ////////////////////////////////////////////////////////////////////////// */
