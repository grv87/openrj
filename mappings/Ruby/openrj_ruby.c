/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj_ruby.c
 *
 * Purpose: Implementation file of the Open-RJ Ruby mapping.
 *
 * Created: 15th June 2004
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


/* \file openrj_ruby.c Implementation file of the memory handling for the Open-RJ library
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_C_OPENRJ_RUBY_MAJOR     1
# define OPENRJ_VER_C_OPENRJ_RUBY_MINOR     6
# define OPENRJ_VER_C_OPENRJ_RUBY_REVISION  2
# define OPENRJ_VER_C_OPENRJ_RUBY_EDIT      11
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <ruby.h>
#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

#include <stdarg.h>
#if defined(WIN32)
# include <malloc.h>
# define alloca     _alloca
#else /* ? OS */
# include <stdio.h>
# include <alloca.h>
#endif /* OS */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef _MSC_VER
# pragma warning(disable : 4127)
# pragma warning(disable : 4505)
#endif /* _MSC_VER */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper functions & macros
 */

/* Extract from Synesis Software's SyBase.h */
#ifndef NUM_ELEMENTS
# define NUM_ELEMENTS(x)            (sizeof(x) / sizeof(0[(x)]))
#endif /* NUM_ELEMENTS */

/* /////////////////////////////////////////////////////////////////////////////
 * Simple debugging
 */

static void TraceToDebugger(char const *fmt, ...)
{
    va_list args;
    char    sz[2048];

    va_start(args, fmt);

#if defined(WIN32)
    _vsnprintf(sz, NUM_ELEMENTS(sz) - 1, fmt, args);
    OutputDebugStringA(sz);
#else /* ? OS */
    vprintf(
#endif /* OS */


    va_end(args);
}

//#define _DEBUG

#if !defined(NDEBUG) && \
    (   defined(_DEBUG) || \
        defined(DEBUG))
# define TRACETODEBUGGER    TraceToDebugger
#else
static void Trace_Stub(char const *fmt, ...)
{
    ((void)fmt);
}
# define TRACETODEBUGGER    (1) ? ((void)0) : Trace_Stub
#endif /* debug */    

/* /////////////////////////////////////////////////////////////////////////////
 * Classes & Modules
 */

static VALUE    mOpenRJ;                /* The Open-RJ module:  ::OpenRJ                            */
static VALUE    c__DatabaseHolder__;    /* Internal class used to manage the ORJDatabaseA pointer   */
static VALUE    cDatabase;              /* The Database class:  ::OpenRJ::Database                  */
static VALUE    cRecord;                /* The Record class:    ::OpenRJ::Record                    */
static VALUE    cField;                 /* The Field class:     ::OpenRJ::Field                     */
static VALUE    cFieldNameError;        /* Exception class, thrown when bad field name given        */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper functions & macros
 */

/** Constructs a Ruby string from a ORJStringA structure. */
static VALUE rb_str_from_ORJStringA(ORJStringA const *str)
{
    return rb_str_new(str->ptr, str->len);
}

/* /////////////////////////////////////////////////////////////////////////////
 * __DatabaseHolder__
 *
 * This class is used to hold a reference on to the Open-RJ database handle.
 * Because the database is required to be "alive" by all instances of the
 * Field, Record and Database classes, we use this __DatabaseHolder__ class to
 * hold a reference, rather than inventing our own reference counting mechanism
 * to do so.
 */

static void __DatabaseHolder___free_(void *p)
{
    ORJDatabase const *database =   (ORJDatabase const*)p;

    TRACETODEBUGGER("__DatabaseHolder___free_()\n");
    TRACETODEBUGGER("Closing database (0x%p, %u, %u, %u)\n", database, database->numLines, database->numFields, database->numRecords);

    ORJ_FreeDatabaseA(database);

    TRACETODEBUGGER("Closed database\n");
}

static VALUE Create___DatabaseHolder__(ORJDatabase const *database)
{
    TRACETODEBUGGER("Create___DatabaseHolder__ (0x%p, %u, %u, %u)\n", database, database->numLines, database->numFields, database->numRecords);

    return Data_Wrap_Struct(c__DatabaseHolder__, NULL, __DatabaseHolder___free_, (void*)database);
}

static ORJDatabase const *__DatabaseHolder___get_database_(VALUE __database__)
{
    ORJDatabase *database;

    Data_Get_Struct(__database__, ORJDatabase, database);

    TRACETODEBUGGER("__DatabaseHolder___get_database_ (0x%p, %u, %u, %u)\n", database, database->numLines, database->numFields, database->numRecords);

    openrj_assert(NULL != database);

    return database;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Field
 *
 * Instances of this class return their member 
 */

#if 0
class Field
  def initialize(name, value)
    @name   = name
    @value  = value
  end
end
#endif

static void Field_mark_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Field_mark_()\n");

    ((void)p);
}

static void Field_free_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Field_free_()\n");

    ((void)p);
}

/** Creates a Field instance, and adds in the two member variables. */
static VALUE Field_create_(VALUE __database__, VALUE record, ORJFieldA const *field)
{
    VALUE   self;

    TRACETODEBUGGER("Field_create_(); [%.*s:%.*s]\n", field->name.len, field->name.ptr, field->value.len, field->value.ptr);

    self    =   Data_Wrap_Struct(cField, Field_mark_, Field_free_, (void*)field);

    rb_iv_set(self, "@__database__", __database__);
    rb_iv_set(self, "@record", record);

    return self;
}

static ORJField const *Field_get_field_(VALUE self)
{
    ORJField const *field;

    Data_Get_Struct(self, ORJField const, field);

    openrj_assert(NULL != field);

    return field;
}

static VALUE Field_name_get(VALUE self)
{
    return rb_str_from_ORJStringA(&Field_get_field_(self)->name);
}

static VALUE Field_value_get(VALUE self)
{
    return rb_str_from_ORJStringA(&Field_get_field_(self)->value);
}

static VALUE Field_to_s(VALUE self)
{
    ORJField const *const   field   =   Field_get_field_(self);
    size_t                  cch     =   100 + field->name.len + 1 + field->value.len + 1;
    char                    *sz     =   (char*)alloca(1 + cch);

    cch = _snprintf(sz
                ,   cch
                ,   "OpenRJ::Field:0x%08x (name: %.*s; value: %.*s)"
                ,   self
                ,   field->name.len
                ,   field->name.ptr
                ,   field->value.len
                ,   field->value.ptr);

    return rb_str_new(sz, cch);
}

/** Evaluates whether the given argument is equivalent to this
 * field. Argument may be a field object
 */

static int Field_equals_(ORJField const *lhs, ORJField const *rhs)
{
    if(lhs == rhs)
    {
        return 1;
    }
    else if(lhs->name.len == rhs->name.len &&
            lhs->value.len == rhs->value.len &&
            0 == strncmp(lhs->name.ptr, rhs->name.ptr, lhs->name.len) &&
            0 == strncmp(lhs->value.ptr, rhs->value.ptr, lhs->value.len))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static VALUE Field_equals(VALUE lhs, VALUE rhs)
{
    return Field_equals_(Field_get_field_(lhs), Field_get_field_(rhs)) ? Qtrue : Qfalse;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Record
 */

static void Record_mark_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Record_mark_()\n");

    ((void)p);
}

static void Record_free_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Record_free_()\n");

    ((void)p);
}

/** Creates a Record instance, and adds in the two member variables. */
static VALUE Record_create_(VALUE __database__, VALUE database, ORJRecordA const *record)
{
    VALUE   self;

    TRACETODEBUGGER("Record_create_()\n");

    self    =   Data_Wrap_Struct(cRecord, Record_mark_, Record_free_, (void*)record);

    rb_iv_set(self, "@__database__", __database__);
    rb_iv_set(self, "@database", database);
    rb_iv_set(self, "@numFields", rb_uint2inum(record->numFields));

    return self;
}

static ORJRecord const *Record_get_record_(VALUE self)
{
    ORJRecord const *record;

    Data_Get_Struct(self, ORJRecord const, record);

    openrj_assert(NULL != record);

    return record;
}

static VALUE Record_each_field(VALUE self)
{
    ORJRecord const *record         =   Record_get_record_(self);
    ORJField const  *begin          =   &record->fields[0];
    ORJField const  *end            =   &record->fields[record->numFields];
    VALUE           __database__    =   rb_iv_get(self, "@__database__");

    for(; begin != end; ++begin)
    {
        rb_yield(Field_create_(__database__, self, begin));
    }

    return self;
}

static VALUE Record_subscript_string(VALUE self, char const *index, int bThrowOnFail)
{
    ORJRecord const *record =   Record_get_record_(self);
    ORJFieldA const *field  =   ORJ_Record_FindFieldByNameA(record, index, NULL);

    if(NULL == field)
    {
        if(bThrowOnFail)
        {
            rb_raise(cFieldNameError, "record does not contain field named: %s", index);
        }

        return Qnil;
    }
    else
    {
        return rb_str_from_ORJStringA(&field->value);
    }
}

static VALUE Record_subscript_fixnum(VALUE self, int index, int bThrowOnFail)
{
    ORJRecord const *record =   Record_get_record_(self);
    size_t          cFields =   ORJ_Record_GetNumFieldsA(record);

    if( 0 <= index &&
        index < cFields)
    {
        VALUE   __database__    =   rb_iv_get(self, "@__database__");

        return Field_create_(__database__, self, &record->fields[index]);;
    }
    else
    {
        if(bThrowOnFail)
        {
            rb_raise(rb_eIndexError, "record does not contain field at index: %d", index);
        }

        return Qnil;
    }
}

/** Returns the field matching the given identity. Identity may be
 * integer index, or a string representing the name of the field
 * 
 */
static VALUE Record_subscript(VALUE self, VALUE index)
{
    VALUE   ret;

    switch(rb_type(index))
    {
        case    T_STRING:
            ret = Record_subscript_string(self, StringValuePtr(index), 1);
            break;
        case    T_FIXNUM:
            ret = Record_subscript_fixnum(self, FIX2INT(index), 1);
            break;
        default:
            rb_raise(rb_eTypeError, "record index / field name must be integer or string");
            break;
    }

    return ret;
}

static VALUE Record_subscript_default(VALUE self, VALUE index, VALUE def)
{
    VALUE   ret;

    switch(rb_type(index))
    {
        case    T_STRING:
            ret = Record_subscript_string(self, StringValuePtr(index), 0);
            break;
        case    T_FIXNUM:
            ret = Record_subscript_fixnum(self, FIX2INT(index), 0);
            break;
        default:
            rb_raise(rb_eTypeError, "record index must be string or integer");
            break;
    }

    if(Qnil == ret)
    {
        ret = def;
    }

    return ret;
}

static VALUE Record_subscript_v(int argc, VALUE *argv, VALUE self)
{
    VALUE   ret;

    switch(argc)
    {
        case    1:
            ret = Record_subscript(self, argv[0]);
            break;
        case    2:
            ret = Record_subscript_default(self, argv[0], argv[1]);
            break;
        default:
            rb_raise(rb_eArgError, "wrong number of arguments (%d)", argc);
            break;
    }

    return ret;
}

static VALUE Record_include_string(ORJRecord const *record, char const *index)
{
    return (NULL != ORJ_Record_FindFieldByNameA(record, index, NULL)) ? Qtrue : Qfalse;
}

static VALUE Record_include_fixnum(ORJRecord const *record, int index)
{
    return (index >=0 && index < record->numFields) ? Qtrue : Qfalse;
}

static VALUE Record_include_object(ORJRecord const *record, VALUE index)
{
    ORJField const  *begin  =   &record->fields[0];
    ORJField const  *end    =   &record->fields[record->numFields];
    ORJField const  *field  =   Field_get_field_(index);

    for(; begin != end; ++begin)
    {
        if(field == begin)
        {
            return Qtrue;
        }
    }

    return Qfalse;
}


/** Returns a Boolean indication of whether the record contains a
 * field with the given identity. Identity may be integer index,
 * string representing the name of the field, or a field object
 */
static VALUE Record_includeQ(VALUE self, VALUE index)
{
    ORJRecord const *record =   Record_get_record_(self);
    
    switch(rb_type(index))
    {
        case    T_STRING:
            return Record_include_string(record, StringValuePtr(index));
        case    T_FIXNUM:
            return Record_include_fixnum(record, FIX2INT(index));
        case    T_OBJECT:
            return Record_include_object(record, index);
        default:
            break;
    }

    rb_raise(rb_eTypeError, "field identity must be string, integer or OpenRJ::Field");

    return Qfalse;
}

static VALUE Record_to_s(VALUE self)
{
    ORJRecord const *record =   Record_get_record_(self);
    char            sz[1001];
    int             cch;

    cch = _snprintf(sz
                ,   NUM_ELEMENTS(sz)
                ,   "OpenRJ::Record:0x%08x (#fields: %d)"
                ,   self
                ,   record->numFields);

    return rb_str_new(sz, cch);
}

static int Record_equals_(ORJRecord const *lhs, ORJRecord const *rhs)
{
    if(lhs == rhs)
    {
        return 1;
    }
    else if(lhs->numFields != rhs->numFields)
    {
        return 0;
    }
    else
    {
        size_t  i;
        size_t  n;

        for(i = 0, n = lhs->numFields; i < n; ++i)
        {
            if(!Field_equals_(lhs->fields + i, rhs->fields + i))
            {
                return 0;
            }
        }

        return 1;
    }
}

static VALUE Record_equals(VALUE lhs, VALUE rhs)
{
    return Record_equals_(Record_get_record_(lhs), Record_get_record_(rhs)) ? Qtrue : Qfalse;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Database
 */

static void Database_mark_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Database_mark_()\n");

    ((void)p);
}

static void Database_free_(void *p)
{
    /* Do nothing */
    TRACETODEBUGGER("Database_free_()\n");

    ((void)p);
}

/** Creates a Database instance, and adds in the two member variables. */
static VALUE Database_initialize(VALUE self, VALUE jarName_, VALUE flags_)
{
    char const          *jarName;
    IORJAllocator       *ator;
    unsigned            flags;
    ORJDatabaseA const  *database;
    ORJError            error;
    ORJRC               rc;

    TRACETODEBUGGER("Database_initialize()\n");

    if(Qnil == flags_)
    {
        flags = 0;
    }
    else
    {
        Check_Type(flags_, T_FIXNUM);

        flags = FIX2INT(flags_);
    }

    Check_Type(jarName_, T_STRING);

    jarName     =   StringValuePtr(jarName_);
    ator        =   NULL;
    database    =   NULL;

    TRACETODEBUGGER("Database_initialize(); jarName: %s; flags: 0x%08x\n", jarName, flags);

    rc = ORJ_ReadDatabaseA(jarName, ator, flags, &database, &error);

    if(ORJ_RC_SUCCESS != rc)
    {
        /* Throw */
        char    szError[1001];

        if(rc == ORJ_RC_PARSEERROR)
        {
            sprintf(szError, "Parsing error in database, at line %u, column %u; parse error: %u, %s", error.invalidLine, error.invalidColumn, error.parseError, ORJ_GetParseErrorStringA(error.parseError));
        }
        else
        {
            sprintf(szError, "Failed to open database; error: %u, %s", rc, ORJ_GetErrorStringA(rc));
        }

        rb_throw(szError, Qnil);
    }
    else
    {
        VALUE               __database__    =   Create___DatabaseHolder__(database);
        ORJDatabase const   *bd_2           =   __DatabaseHolder___get_database_(__database__);

        rb_iv_set(self, "@__database__", __database__);
        rb_iv_set(self, "@path", jarName_);
        rb_iv_set(self, "@numLines", rb_uint2inum(database->numLines));
        rb_iv_set(self, "@numFields", rb_uint2inum(database->numFields));
        rb_iv_set(self, "@numRecords", rb_uint2inum(database->numRecords));
    }

    return self;
}

static VALUE Database_each_record(VALUE self)
{
    TRACETODEBUGGER("Database_each_record()\n");
    {
        VALUE           __database__    =   rb_iv_get(self, "@__database__");
        ORJDatabase const *database     =   __DatabaseHolder___get_database_(__database__);
        ORJRecord const *begin          =   &database->records[0];
        ORJRecord const *end            =   &database->records[database->numRecords];

        TRACETODEBUGGER("Database_each_record() - 2; num records: %u\n", database->numRecords);

        for(; begin != end; ++begin)
        {
            TRACETODEBUGGER("Database_each_record() - 3; 0x%p %u\n", begin);

            rb_yield(Record_create_(__database__, self, begin));
        }

        TRACETODEBUGGER("Database_each_record() - 4\n");

        return self;
    }
}

static VALUE Database_each_field(VALUE self)
{
    VALUE               __database__    =   rb_iv_get(self, "@__database__");
    ORJDatabase const   *database       =   __DatabaseHolder___get_database_(__database__);
    ORJField const      *begin          =   &database->fields[0];
    ORJField const      *end            =   &database->fields[database->numFields];

    for(; begin != end; ++begin)
    {
        ORJRecord const *record =   ORJ_Field_GetRecordA(begin);

        rb_yield(Field_create_(__database__, Qnil, begin));
    }

    return self;
}

static VALUE Database_subscript(VALUE self, VALUE index_)
{
    VALUE               __database__    =   rb_iv_get(self, "@__database__");
    ORJDatabase const   *database       =   __DatabaseHolder___get_database_(__database__);
    size_t              cRecords        =   ORJ_Database_GetNumRecordsA(database);
    int                 index           =   FIX2INT(index_);

    if( 0 <= index &&
        index < cRecords)
    {
        return Record_create_(__database__, self, &database->records[index]);
    }
    else
    {
        rb_raise(rb_eIndexError, "database does not contain record at index: %d", index);

        return Qnil;
    }
}

static VALUE Database_to_s(VALUE self)
{
    VALUE               __database__    =   rb_iv_get(self, "@__database__");
    ORJDatabase const   *database       =   __DatabaseHolder___get_database_(__database__);
    VALUE               path            =   rb_iv_get(self, "@path");
    char                sz[1001];
    int                 cch;

    cch = _snprintf(sz
                ,   NUM_ELEMENTS(sz)
                ,   "OpenRJ::Database:0x%08x (%s; #records: %d; #fields: %d; flags: 0x%08x)"
                ,   self
                ,   StringValuePtr(path)
                ,   database->numRecords
                ,   database->numFields
                ,   database->flags);

    return rb_str_new(sz, cch);
}

static int Database_equals_(ORJDatabase const *lhs, ORJDatabase const *rhs)
{
    if(lhs == rhs)
    {
        return 1;
    }
    else if(lhs->numFields != rhs->numFields ||
            lhs->numRecords != rhs->numRecords)
    {
        return 0;
    }
    else
    {
        size_t  i;
        size_t  n;

        for(i = 0, n = lhs->numRecords; i < n; ++i)
        {
            if(!Record_equals_(lhs->records + i, rhs->records + i))
            {
                return 0;
            }
        }

        return 1;
    }
}

static VALUE Database_equals(VALUE lhs, VALUE rhs)
{
    VALUE               lhs___database__    =   rb_iv_get(lhs, "@__database__");
    ORJDatabase const   *lhs_database       =   __DatabaseHolder___get_database_(lhs___database__);
    VALUE               rhs___database__    =   rb_iv_get(rhs, "@__database__");
    ORJDatabase const   *rhs_database       =   __DatabaseHolder___get_database_(rhs___database__);

    return Database_equals_(lhs_database, rhs_database) ? Qtrue : Qfalse;
}

/* /////////////////////////////////////////////////////////////////////////////
 * module functions
 */

static VALUE openrj_usage(VALUE self)
{
    VALUE       ar          =   rb_ary_new();
    char const  *lines[]    =
    {
            "Module: OpenRJ"
        ,   ""
        ,   "Author: Matthew Wilson, Synesis Software; http://synesis.com.au/software/"
        ,   ""
        ,   "  Constants:"
        ,   "    ORDER_FIELDS                - causes fields to be ordered"
        ,   "    ELIDE_BLANK_RECORDS         - skips empty records"
        ,   "  Functions:"
        ,   "    usage() - shows this usage"
        ,   "  Classes:"
        ,   "    Class: Database"
        ,   "      Construction:"
        ,   "        new (jarName, flags)"
        ,   "          jarName               - the name of the database file"
        ,   "          flags                 - flags to alter the behaviour of the loading,"
        ,   "                                  or the form of the loaded database"
        ,   "      Attributes:"
        ,   "        path                    - the database file path"
        ,   "        numLines                - the number of lines in the database file"
        ,   "        numFields               - the total number of fields in the database"
        ,   "        numRecords              - the total number of records in the database"
        ,   "      Methods:"
        ,   "        each                    - enumerates the records in the database"
        ,   "        each_record             - same as each"
        ,   "        each_field              - enumerates the fields in the database"
        ,   "        [<index>]               - accesses the record corresponding to the index"
        ,   "                                  (integer). It throws IndexError if the index is"
        ,   "                                  out of bounds."
        ,   "        to_s                    - returns a string form of the database"
        ,   "    Class: FieldNameError"
        ,   "    Class: Record"
        ,   "      Attributes:"
        ,   "        numFields               - the total number of fields in the record"
        ,   "        database                - the database object of which this record is part"
        ,   "      Methods:"
        ,   "        each                    - enumerates the fields in the record"
        ,   "        [<index>]               - accesses the field corresponding to the index."
        ,   "                                  If the index is a string, it must correspond to"
        ,   "                                  the name of the field, and the value of the"
        ,   "                                  field (a string) is returned. If the name is not"
        ,   "                                  found, then a FieldNameError is thrown."
        ,   "                                  If the index is an integer, it must correspond"
        ,   "                                  to the 0-based index of the field, and the Field"
        ,   "                                  instance is returned. If the index is out of"
        ,   "                                  bounds, then an IndexError is thrown."
        ,   "        [<index>, <def-value>]  - accesses the field corresponding to the index."
        ,   "                                  If the index is a string, it must correspond to"
        ,   "                                  the name of the field, and the value of the"
        ,   "                                  field (a string) is returned. If the name is not"
        ,   "                                  found, then the default value provided is"
        ,   "                                  returned."
        ,   "                                  If the index is an integer, it must correspond"
        ,   "                                  to the 0-based index of the field, and the Field"
        ,   "                                  instance is returned. If the index is out of"
        ,   "                                  bounds, then the default value provided is"
        ,   "                                  returned."
        ,   "        to_s                    - returns a string form of the record"
        ,   "    Class: Field"
        ,   "      Attributes:"
        ,   "        name                    - the field name"
        ,   "        value                   - the field value"
        ,   "        record                  - the record object of which this field is part"
        ,   "      Methods:"
        ,   "        to_s                    - returns a string form of the field"
    };
    char const  **begin =   &lines[0];
    char const  **end   =   &lines[NUM_ELEMENTS(lines)];

    for(; begin != end; ++begin)
    {
        TRACETODEBUGGER("%s\n", *begin);
        rb_ary_push(ar, rb_str_new2(*begin));
    }

    return ar;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Module registration
 */

void Init_openrj()
{
    char    openrjVersion[101];
    char    openrjRubyVersion[101];

    TRACETODEBUGGER("Initialising openrj extension for Ruby\n");

    sprintf(openrjVersion, "%d.%d.%d", OPENRJ_VER_MAJOR, OPENRJ_VER_MINOR, OPENRJ_VER_REVISION);
    sprintf(openrjRubyVersion, "%d.%d.%d", OPENRJ_VER_C_OPENRJ_RUBY_MAJOR, OPENRJ_VER_C_OPENRJ_RUBY_MINOR, OPENRJ_VER_C_OPENRJ_RUBY_REVISION);

    /* OpenRJ module */
    TRACETODEBUGGER("Creating Open-RJ module\n");
    mOpenRJ = rb_define_module("OpenRJ");
    rb_define_const(mOpenRJ, "OPENRJ_VERSION",rb_str_new2(openrjVersion));
    rb_define_const(mOpenRJ, "VERSION",rb_str_new2(openrjRubyVersion));
    rb_define_const(mOpenRJ, "ORJ_FLAG_ORDERFIELDS", rb_uint2inum(ORJ_FLAG_ORDERFIELDS));
    rb_define_const(mOpenRJ, "ORJ_FLAG_ELIDEBLANKRECORDS", rb_uint2inum(ORJ_FLAG_ELIDEBLANKRECORDS));
    rb_define_const(mOpenRJ, "ORDER_FIELDS", rb_uint2inum(ORJ_FLAG_ORDERFIELDS));
    rb_define_const(mOpenRJ, "ELIDE_BLANK_RECORDS", rb_uint2inum(ORJ_FLAG_ELIDEBLANKRECORDS));
    rb_define_module_function(mOpenRJ, "usage", openrj_usage, 0);

    /* __DatabaseHolder__ */
    TRACETODEBUGGER("Creating __DatabaseHolder__ class\n");
    c__DatabaseHolder__ = rb_define_class_under(mOpenRJ, "__DatabaseHolder__", rb_cObject);

    /* FieldNameError */
    cFieldNameError     = rb_define_class_under(mOpenRJ, "FieldNameError", rb_eStandardError);

    /* Database class */
    TRACETODEBUGGER("Creating Database class\n");
    cDatabase = rb_define_class_under(mOpenRJ, "Database", rb_cObject);
    rb_include_module(cDatabase, rb_mEnumerable);
    rb_define_method(cDatabase, "initialize", Database_initialize, 2);
    rb_define_method(cDatabase, "each", Database_each_record, 0);
    rb_define_method(cDatabase, "each_record", Database_each_record, 0);
    rb_define_method(cDatabase, "each_field", Database_each_field, 0);
    rb_define_method(cDatabase, "[]", Database_subscript, 1);
    rb_define_method(cDatabase, "to_s", Database_to_s, 0);
    rb_define_method(cDatabase, "==", Database_equals, 1);
    rb_define_method(cDatabase, "eql?", Database_equals, 1);
    rb_define_attr(cDatabase,   "path", 1, 0);
    rb_define_attr(cDatabase,   "numLines", 1, 0);
    rb_define_attr(cDatabase,   "numFields", 1, 0);
    rb_define_attr(cDatabase,   "numRecords", 1, 0);

    /* Record class */
    TRACETODEBUGGER("Creating Record class\n");
    cRecord = rb_define_class_under(mOpenRJ, "Record", rb_cObject);
    rb_include_module(cRecord, rb_mEnumerable);
    rb_define_method(cRecord,   "each", Record_each_field, 0);
    rb_define_method(cRecord,   "[]", Record_subscript_v, -1);
    rb_define_method(cRecord,   "include?", Record_includeQ, 1);
    rb_define_method(cRecord,   "member?", Record_includeQ, 1);
    rb_define_method(cRecord,   "to_s", Record_to_s, 0);
    rb_define_method(cRecord,   "==", Record_equals, 1);
    rb_define_method(cRecord,   "eql?", Record_equals, 1);
    rb_define_attr(cRecord,     "numFields", 1, 0);
    rb_define_attr(cRecord,     "database", 1, 0);

    /* Field class */
    TRACETODEBUGGER("Creating Field class\n");
    cField = rb_define_class_under(mOpenRJ, "Field", rb_cObject);
    rb_include_module(cField, rb_mComparable);
    rb_define_method(cField, "name", Field_name_get, 0);
    rb_define_method(cField, "value", Field_value_get, 0);
    rb_define_method(cField,  "to_s", Field_to_s, 0);
    rb_define_method(cField,  "==", Field_equals, 1);
    rb_define_method(cField,  "eql?", Field_equals, 1);
    rb_define_attr(cField, "record", 1, 0);

    TRACETODEBUGGER("Initialised openrj extension for Ruby\n");
}

/* ////////////////////////////////////////////////////////////////////////// */
