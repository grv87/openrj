/* /////////////////////////////////////////////////////////////////////////////
 * File:    std/openrj.d
 *
 * Purpose: D mapping for the Open-RJ library
 *
 * Created: 11th June 2004
 * Updated: 29th September 2004
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2004, Matthew Wilson and Synesis Software
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


/* \file std/openrj.d D mapping for the Open-RJ library
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Module
 */

module std.openrj;

/* /////////////////////////////////////////////////////////////////////////////
 * Imports
 */

private import etc.c.openrj.openrj;
private import std.string;

/* /////////////////////////////////////////////////////////////////////////////
 * Enumerations
 */

public enum ORJ_FLAG
{
        ORDER_FIELDS        =   etc.c.openrj.openrj.ORJ_FLAG.ORJ_FLAG_ORDERFIELDS       /*!< Arranges the fields in alphabetical order */
    ,   ELIDE_BLANK_RECORDS =   etc.c.openrj.openrj.ORJ_FLAG.ORJ_FLAG_ELIDEBLANKRECORDS /*!< Causes blank records to be ignored */
    ,   
};

public enum ORJRC
{
        SUCCESS             =   etc.c.openrj.openrj.ORJRC.ORJ_RC_SUCCESS
    ,   CANNOT_OPEN_JARFILE =   etc.c.openrj.openrj.ORJRC.ORJ_RC_CANNOTOPENJARFILE
    ,   NO_RECORDS          =   etc.c.openrj.openrj.ORJRC.ORJ_RC_NORECORDS
    ,   OUT_OF_MEMORY       =   etc.c.openrj.openrj.ORJRC.ORJ_RC_OUTOFMEMORY
    ,   BAD_FILE_READ       =   etc.c.openrj.openrj.ORJRC.ORJ_RC_BADFILEREAD
    ,   PARSE_ERROR         =   etc.c.openrj.openrj.ORJRC.ORJ_RC_PARSEERROR
    ,   INVALID_INDEX       =   etc.c.openrj.openrj.ORJRC.ORJ_RC_INVALIDINDEX
    ,   UNEXPECTED          =   etc.c.openrj.openrj.ORJRC.ORJ_RC_UNEXPECTED
    ,   INVALID_CONTENT     =   etc.c.openrj.openrj.ORJRC.ORJ_RC_INVALIDCONTENT
};

public enum ORJ_PARSE_ERROR
{
        SUCCESS                             =   etc.c.openrj.openrj.ORJ_PARSE_ERROR.ORJ_PARSE_SUCCESS
    ,   RECORD_SEPARATOR_IN_CONTINUATION    =   etc.c.openrj.openrj.ORJ_PARSE_ERROR.ORJ_PARSE_RECORDSEPARATORINCONTINUATION
    ,   UNFINISHED_RECORD                   =   etc.c.openrj.openrj.ORJ_PARSE_ERROR.ORJ_PARSE_UNFINISHEDRECORD
};

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

class OpenRjException
    : public Exception
{
/// \name Construction
/// @{
public:
    this(char[] message)
    {
        super(message);
    }
/// @}
}

class DatabaseException
    : public OpenRjException
{
/// \name Construction
/// @{
public:
    this(ORJRC rc, ORJError error)
    {
        m_rc    =   rc;
        m_error =   error;

        char    *err;
        char    message[1001];

        if(rc == ORJRC.PARSE_ERROR)
        {
            std.string.sprintf( message
                            ,   "Parsing error in database, at line %u, column %u; parse error: %u, %s"
                            ,   error.invalidLine
                            ,   error.invalidColumn
                            ,   error.parseError
                            ,   ORJ_GetParseErrorStringA(error.parseError));
        }
        else
        {
            std.string.sprintf( message
                            ,   "Failed to open database; error: %u, %s"
                            ,   rc
                            ,   ORJ_GetErrorStringA(rc));
        }

        super(message);
    }
/// @}

/// \name Attributes
/// @{
public:
    ORJRC rc()
    {
        return m_rc;
    }
    ORJError error()
    {
        return m_error;
    }
/// @}

private:
    ORJRC       m_rc;
    ORJError    m_error;
}

class InvalidKeyException
    : public OpenRjException
{
/// \name Construction
/// @{
public:
    this(char[] message)
    {
        super(message);
    }
/// @}
}


class Field
{
/// \name Types
/// @{
public:
/+
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
+/
    alias   Field   class_type;
/+
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
+/
/// @}

/// \name Construction
/// @{
private:
    this(ORJFieldA *field, Record record)
    in
    {
        assert(null !== field);
    }
    body
    {
        m_field     =   field;
        m_record    =   record;
    }
/// @}

/// \name Attributes
/// @{
public:
    char[]  name()
    {
        return m_field.name;
    }
    char[]  value()
    {
        return m_field.value;
    }
    Record record()
    {
        return m_record;
    }
/// @}

// Members
private:
    ORJFieldA   *m_field;
    Record      m_record;
}

class Record
{
/// \name Types
/// @{
public:
/+
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
+/
    alias   Field   value_type;
    alias   Record  class_type;
/+
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
+/
/// @}

/// \name Construction
/// @{
private:
    this(ORJRecordA *record, inout Field[] databaseFields, Database database)
    in
    {
        assert(null !== record);
    }
    body
    {
        m_record    =   record;
        m_database  =   database;

        if(m_record.fields.length > 0) // This is necessary since taking the address of the 0th element of an empty array incurs ArrayBoundsError
        {
            ORJFieldA   *begin  =   &record.fields[0];
//          ORJFieldA   *end    =   &m_record.fields[m_record.fields.length]; // This causes ArrayBoundsError
            ORJFieldA   *end    =   begin + m_record.fields.length;

            for(; begin != end; ++begin)
            {
                Field   field = new Field(begin, this);

                m_fields        ~= field;
                databaseFields  ~= field;
            }
        }
    }
/// @}

/// \name Attributes
/// @{
public:
    uint length()
    {
        return m_fields.length;
    }

    Field[] fields()
    {
        return m_fields;
    }

    Field   opIndex(int index)
    in
    {
        assert(index >= 0);
        assert(index < m_fields.length);
    }
    body
    {
        return m_fields[index];
    }

    Field   opIndex(char[] fieldName)
    {
        return getField(fieldName);
    }

    Field   getField(char[] fieldName)
    in
    {
        assert(null !== fieldName);
    }
    body
    {
        Field   field   =   findField(fieldName);

        if(null === field)
        {
            throw new InvalidKeyException("field not found");
        }

        return field;
    }

    Field   findField(char[] fieldName)
    in
    {
        assert(null !== fieldName);
    }
    body
    {
        uint    flags   =   this.m_database.flags;

        if(ORJ_FLAG.ORDER_FIELDS == (flags & ORJ_FLAG.ORDER_FIELDS))
        {
            // We can do a sorted search
            foreach(Field field; this)
            {
                int res =   cmp(field.name, fieldName);

                if(0 == res)
                {
                    return field;
                }
                else if(res > 0)
                {
                    return null;
                }
            }
        }
        else
        {
            foreach(Field field; this)
            {
                if(field.name == fieldName)
                {
                    return field;
                }
            }
        }

        return null;
    }
/// @}

/// \name Enumeration
/// @{
public:
    int opApply(int delegate(inout Field field) dg)
    {
        int result  =   0;

        foreach(Field field; m_fields)
        {
            result = dg(field);

            if(0 != result)
            {
                break;
            }
        };

        return result;
    }

    int opApply(int delegate(in char[] name, in char[] value) dg)
    {
        int result  =   0;

        foreach(Field field; m_fields)
        {
            result = dg(field.name(), field.value());

            if(0 != result)
            {
                break;
            }
        };

        return result;
    }
/// @}

// Members
private:
    ORJRecordA  *m_record;
    Field[]     m_fields;
    Database    m_database;
}

/// \brief This class represents the Open-RJ database file, once read in and parsed
class Database
{
/+
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
+/
/// \name Types
/// @{
public:
    alias   Record      value_type;
    alias   Database    class_type;
/// @}
/+
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */
+/

/// \name Construction
/// @{
public:
    this(char[] jarName, uint flags = 0)
    {
        ORJError    error;
        ORJRC       rc  =   ORJ_ReadDatabaseA(std.string.toStringz(jarName), null, m_flags, m_database, &error);

        if(ORJRC.SUCCESS != rc)
        {
            throw new DatabaseException(rc, error);
        }
        else
        {
            assert(null !== m_database);

            m_jarName   =   jarName;
            m_flags     =   flags;

            ORJRecordA  *begin  =   &m_database.records[0];
//          ORJRecordA  *end    =   &m_database.records[m_database.records.length]; // This causes ArrayBoundsError
            ORJRecordA  *end    =   begin + m_database.records.length;

            for(; begin != end; ++begin)
            {
                m_records ~= new Record(begin, m_fields, this);
            }
        }
    }

    ~this()
    {
//      printf("\n\n\n~Database()\n\n\n");
        ORJ_FreeDatabaseA(m_database);
    }
/// @}

/// \name Attributes
/// @{
public:
    char[]      jarName()
    {
        return m_jarName;
    }

    uint        flags()
    {
        return m_flags;
    }

    Record[]    records()
    {
        return m_records;
    }

    Field[]     fields()
    {
        return m_fields;
    }

    uint length()
    {
        return m_records.length;
    }

    Record      opIndex(int index)
    in
    {
        assert(index >= 0);
        assert(index < m_records.length);
    }
    body
    {
        return m_records[index];
    }
/// @}

/// \name Searching
/// @{
public:
    Record[]    getRecordsContainingField(char[] fieldName)
    {
        Record[]    records;

        foreach(Record record; m_records)
        {
            if(null !== record.findField(fieldName))
            {
                records ~= record;
            }
        }

        return records;
    }

    Record[]    getRecordsContainingField(char[] fieldName, char[] fieldValue)
    {
        Record[]    records;
        uint        flags   =   this.m_database.flags;

        foreach(Record record; m_records)
        {
            Field   field   =   record.findField(fieldName);

            if(null !== field)
            {
                // Since there can be more than one field with the same name in
                // the same record, we need to search all fields in this record
                if(ORJ_FLAG.ORDER_FIELDS == (flags & ORJ_FLAG.ORDER_FIELDS))
                {
                    // We can do a sorted search
                    foreach(Field field; record)
                    {
                        int res =   cmp(field.name, fieldName);

                        if( 0 == res &&
                            field.value == fieldValue)
                        {
                            records ~= record;

                            break;
                        }
                        else if(res > 0)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    foreach(Field field; record)
                    {
                        if( field.name == fieldName &&
                            field.value == fieldValue)
                        {
                            records ~= record;

                            break;
                        }
                    }
                }
            }
        }

        return records;
    }

/+
    Record[]    getRecordsContainingField(char[] fieldName)
    {
        Record[]    records;
        uint        flags   =   this.m_database.flags;

        foreach(Record record; m_records)
        {
            Field   field   =   record.findField(fieldName);

            if(null !== field)
            {
                // Since there can be more than one field with the same name in
                // the same record, we need to search all fields in this record
                if(ORJ_FLAG.ORJ_FLAG_ORDERFIELDS == (flags & ORJ_FLAG.ORJ_FLAG_ORDERFIELDS))
                {
                    // We can do a sorted search
                    foreach(Field field; record)
                    {
                        int res =   cmp(field.name, fieldName);

                        if(0 == res)
                        {
                            records ~= record;

                            break;
                        }
                        else if(res > 0)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    foreach(Field field; record)
                    {
                        if(field.name == fieldName)
                        {
                            records ~= record;

                            break;
                        }
                    }
                }
            }
        }

        return records;
    }
+/
/// @}

/// \name Enumeration
/// @{
public:
    int opApply(int delegate(inout Record record) dg)
    {
        int result  =   0;

        foreach(Record record; m_records)
        {
            result = dg(record);

            if(0 != result)
            {
                break;
            }
        };

        return result;
    }
/// @}

// Members
private:
    char[]          m_jarName;
    uint            m_flags;
    ORJDatabaseA    *m_database;
    Record[]        m_records;
    Field[]         m_fields;
}

/* ////////////////////////////////////////////////////////////////////////// */

/+
version(MainTest)
{
    int main(char[][] args)
    {
        if(args.length < 2)
        {
            printf("Specify an Open-RJ file");
        }
        else
        {
            Database    *database;
            ORJRC       rc   =  ORJ_ReadDatabaseA(args[1], null, 0, database, null);

            if(0 != rc)
            {
                printf("Failed: %u\n", rc);
            }
            else
            {
                printf("Num lines:   %u\n", database.numLines);
                printf("Num fields:  %u\n", database.fields.length);
                printf("Num records: %u\n", database.records.length);

                foreach(Record record; database.records)
                {
                    printf("  Record; num fields: %u\n", record.fields.length);

                    foreach(Field field; record.fields)
                    {
                        printf("    name:  %.*s; value: %.*s\n", field.name, field.value);
                    }
                }

                ORJ_FreeDatabaseA(database);
            }
        }

        return 0;
    }
}
+/

/* ////////////////////////////////////////////////////////////////////////// */
