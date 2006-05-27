/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj.python.c
 *
 * Purpose: Implementation for the Python mapping for Open-RJ
 *
 * Created: 1st October 2004
 * Updated: 24th May 2006
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
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_C_OPENRJ_PYTHON_MAJOR     1
# define OPENRJ_VER_C_OPENRJ_PYTHON_MINOR     4
# define OPENRJ_VER_C_OPENRJ_PYTHON_REVISION  2
# define OPENRJ_VER_C_OPENRJ_PYTHON_EDIT      17
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifdef _DEBUG
# undef     _DEBUG
# define    SKIP_DEBUG
#endif /* _DEBUG */

#include <Python.h>

#ifdef _MSC_VER
# undef		statichere
# define	statichere
#endif /* compiler */

#ifdef SKIP_DEBUG
# define _DEBUG
#endif /* SKIP_DEBUG */

#include <openrj/openrj.h>

#ifdef WIN32
# include <windows.h>
#else
# include <stdlib.h>
#endif /* WIn32 */

//#define TRACE_METHODS
//#define TRACE_CTORS
//#define TRACE_DTORS

#define DATABASE_HAS_FIELDS_MEMBER

/* /////////////////////////////////////////////////////////////////////////////
 * Debugging
 */

static long get_num_instances(void);
static long add_instance(void);
static long del_instance(void);

/* /////////////////////////////////////////////////////////////////////////////
 * openrj module exception type
 */

static PyObject *DatabaseExceptionObject;

/* /////////////////////////////////////////////////////////////////////////////
 * ORJDatabase_holder
 */

typedef struct
{
    ORJDatabase const   *database;
    long                cRefs;

} ORJDatabase_holder;

static ORJDatabase_holder   *ORJDatabase_holder_create(ORJDatabase const *database);
static void                 ORJDatabase_holder_addref(ORJDatabase_holder *dbh);
static void                 ORJDatabase_holder_release(ORJDatabase_holder *dbh);

/* /////////////////////////////////////////////////////////////////////////////
 * Field type and method declarations
 */

staticforward PyTypeObject openrj_Field_Type;

typedef struct
{
    /* Header */
    PyObject_HEAD

    /* Field specific information */
    ORJDatabase_holder  *dbh;
    ORJField const      *field;

} openrj_Field;


static openrj_Field *openrj_Field_alloc(PyObject *self, ORJField const *Field, ORJDatabase_holder *dbh);
static void         openrj_Field_dealloc(openrj_Field *self);
static int          openrj_Field_print(openrj_Field *self, FILE *file, int flags);
static PyObject     *openrj_Field_getattr(openrj_Field *self, char const *name);
static int          openrj_Field_compare(openrj_Field *lhs, openrj_Field *rhs);

static PyObject     *openrj_Field_name(openrj_Field *self);
static PyObject     *openrj_Field_value(openrj_Field *self);

static struct PyMethodDef   openrj_Field_methods[] =
{
        {   "name",     (PyCFunction)openrj_Field_name,      METH_NOARGS,    "The name of the field"     }
    ,   {   "value",    (PyCFunction)openrj_Field_value,     METH_NOARGS,    "The value of the field"    }
    ,   {   NULL,       NULL,								0,              NULL                        }
};

statichere PyTypeObject openrj_Field_Type =
{
        PyObject_HEAD_INIT(NULL)
        0
    ,   "Field"
    ,   sizeof(openrj_Field)
    ,   0
    ,   (destructor)    openrj_Field_dealloc        /* tp_dealloc               */
    ,   (printfunc)     openrj_Field_print          /* tp_print                 */
    ,   (getattrfunc)   openrj_Field_getattr        /* tp_getattr               */
    ,   0                                           /* tp_setattr               */
    ,   0                                           /* tp_compare               */
    ,   0                                           /* tp_repr                  */
    ,   0                                           /* tp_as_number     (PyNumberMethods*)      */
    ,   0                                           /* tp_as_sequence   (PySequenceMethods*)    */
    ,   0                                           /* tp_as_mapping    (PyMappingMethods*) */
    ,   0                                           /* tp_hash                  */
    ,   0                                           /* tp_call                  */
    ,   0                                           /* tp_str                   */
    ,   0                                           /* tp_getattro              */
    ,   0                                           /* tp_setattro              */
    ,   0                                           /* tp_as_buffer             */
    ,   0                                           /* tp_flags                 */
    ,   0                                           /* tp_doc                   */
    ,   0                                           /* tp_traverse              */
    ,   0                                           /* tp_clear                 */
    ,   0                                           /* tp_richcompare           */
    ,   0                                           /* tp_weaklistoffset        */
    ,   0                                           /* tp_iter                  */
    ,   0                                           /* tp_iternext              */
    ,   0                                           /* tp_methods               */
    ,   0                                           /* tp_members               */
    ,   0                                           /* tp_getset                */
    ,   0                                           /* tp_base                  */
    ,   0                                           /* tp_dict                  */
    ,   0                                           /* tp_descr_get             */
    ,   0                                           /* tp_descr_set             */
    ,   0                                           /* tp_dictoffset            */
    ,   0                                           /* tp_init                  */
    ,   0                                           /* tp_alloc                 */
    ,   0                                           /* tp_new                   */
    ,   0                                           /* tp_free                  */
    ,   0                                           /* tp_is_gc                 */
    ,   0                                           /* tp_bases                 */
    ,   0                                           /* tp_mro                   */
    ,   0                                           /* tp_cache                 */
    ,   0                                           /* tp_subclasses            */
    ,   0                                           /* tp_weaklist              */
#ifdef COUNT_ALLOCS
    ,   0                                           /* tp_allocs                */
    ,   0                                           /* tp_frees                 */
    ,   0                                           /* tp_maxalloc              */
    ,   0                                           /* tp_next                  */
#endif /* COUNT_ALLOCS */
};

/* /////////////////////////////////////////////////////////////////////////////
 * Record type and method declarations
 */

staticforward PyTypeObject openrj_Record_Type;

typedef struct
{
    /* Header */
    PyObject_HEAD

    /* Record specific information */
    ORJDatabase_holder  *dbh;
    ORJRecord const     *record;
    openrj_Field        **fields;

} openrj_Record;

static openrj_Record    *openrj_Record_alloc(PyObject *self, ORJRecord const *Record, ORJDatabase_holder *dbh);
static void             openrj_Record_dealloc(openrj_Record *self);
static int              openrj_Record_print(openrj_Record *self, FILE *file, int flags);
static PyObject         *openrj_Record_getattr(openrj_Record *self, char const *name);
static int              openrj_Record_compare(openrj_Record *lhs, openrj_Record *rhs);

static int              openrj_Record_length(openrj_Record *self);
static PyObject         *openrj_Record_item(openrj_Record *self, int index);
static PyObject         *openrj_Record_slice(openrj_Record *self, int from, int to);
#if 0
static PyObject         *openrj_Record_getitem(openrj_Record *self, PyObject *arg);
#endif /* 0 */

static struct PyMethodDef   openrj_Record_methods[] =
{
    /*  {   "lookup",   (PyCFunction)openrj_Record_lookup,   METH_NOARGS,    "Looks up a field by name"  }
    , */    {   NULL,       NULL,                   0,              NULL                        }
};

static PySequenceMethods openrj_Record_as_sequence =
{
        (inquiry)           openrj_Record_length    /* sq_length    "len(x)"    */
    ,   (binaryfunc)        0                       /* sq_concat    "x + y"     */
    ,   (intargfunc)        0                       /* sq_repeat    "x * n"     */
    ,   (intargfunc)        openrj_Record_item      /* sq_item      "x[i], in"  */
    ,   (intintargfunc)     openrj_Record_slice     /* sq_slice     "x[i:j]"    */
    ,   (intobjargproc)     0                       /* sq_ass_item  "x[i] = v"  */
    ,   (intintobjargproc)  0                       /* sq_ass_slice "x[i:j]=v"  */
    ,   (objobjproc)        0                       /* sq_contains              */
    ,   (binaryfunc)        0                       /* sq_inplace_concat        */
    ,   (intargfunc)        0                       /* sq_inplace_repeat        */
};

#if 0
static PyMappingMethods openrj_Record_as_mapping =
{
        (inquiry)           openrj_Record_length    /* sq_length    "len(x)"    */
    ,   (binaryfunc)        openrj_Record_getitem
    ,   (objobjargproc)     0
};
#endif /* 0 */

statichere PyTypeObject openrj_Record_Type =
{
        PyObject_HEAD_INIT(NULL)
        0
    ,   "Record"
    ,   sizeof(openrj_Record)
    ,   0
    ,   (destructor)    openrj_Record_dealloc       /* tp_dealloc               */
    ,   (printfunc)     openrj_Record_print         /* tp_print                 */
    ,   (getattrfunc)   openrj_Record_getattr       /* tp_getattr               */
    ,   0                                           /* tp_setattr               */
    ,   0                                           /* tp_compare               */
    ,   0                                           /* tp_repr                  */
    ,   0                                           /* tp_as_number     (PyNumberMethods*)      */
    ,   &openrj_Record_as_sequence                  /* tp_as_sequence   (PySequenceMethods*)    */
    ,   0/* &openrj_Record_as_mapping */                    /* tp_as_mapping    (PyMappingMethods*) */
    ,   0                                           /* tp_hash                  */
    ,   0                                           /* tp_call                  */
    ,   0                                           /* tp_str                   */
    ,   0                                           /* tp_getattro              */
    ,   0                                           /* tp_setattro              */
    ,   0                                           /* tp_as_buffer             */
    ,   0                                           /* tp_flags                 */
    ,   0                                           /* tp_doc                   */
    ,   0                                           /* tp_traverse              */
    ,   0                                           /* tp_clear                 */
    ,   0                                           /* tp_richcompare           */
    ,   0                                           /* tp_weaklistoffset        */
    ,   0                                           /* tp_iter                  */
    ,   0                                           /* tp_iternext              */
    ,   0                                           /* tp_methods               */
    ,   0                                           /* tp_members               */
    ,   0                                           /* tp_getset                */
    ,   0                                           /* tp_base                  */
    ,   0                                           /* tp_dict                  */
    ,   0                                           /* tp_descr_get             */
    ,   0                                           /* tp_descr_set             */
    ,   0                                           /* tp_dictoffset            */
    ,   0                                           /* tp_init                  */
    ,   0                                           /* tp_alloc                 */
    ,   0                                           /* tp_new                   */
    ,   0                                           /* tp_free                  */
    ,   0                                           /* tp_is_gc                 */
    ,   0                                           /* tp_bases                 */
    ,   0                                           /* tp_mro                   */
    ,   0                                           /* tp_cache                 */
    ,   0                                           /* tp_subclasses            */
    ,   0                                           /* tp_weaklist              */
#ifdef COUNT_ALLOCS
    ,   0                                           /* tp_allocs                */
    ,   0                                           /* tp_frees                 */
    ,   0                                           /* tp_maxalloc              */
    ,   0                                           /* tp_next                  */
#endif /* COUNT_ALLOCS */
};

/* /////////////////////////////////////////////////////////////////////////////
 * Database type and method declarations
 */

staticforward PyTypeObject openrj_Database_Type;

typedef struct
{
    /* Header */
    PyObject_HEAD

    /* Database specific information */
    ORJDatabase_holder  *dbh;
    ORJDatabase const   *database;
    char                *path;

    openrj_Record       **records;
#ifdef DATABASE_HAS_FIELDS_MEMBER
    openrj_Field        **fields;
#endif /* DATABASE_HAS_FIELDS_MEMBER */

} openrj_Database;


static openrj_Database  *openrj_Database_alloc(PyObject *self, ORJDatabase const *database, char const *path);
static void             openrj_Database_dealloc(openrj_Database *self);
static int              openrj_Database_print(openrj_Database *self, FILE *file, int flags);
static PyObject         *openrj_Database_getattr(openrj_Database *self, char const *name);

static PyObject         *openrj_Database_path(openrj_Database *self);
static PyObject         *openrj_Database_records(openrj_Database *self);
#ifdef DATABASE_HAS_FIELDS_MEMBER
static PyObject         *openrj_Database_fields(openrj_Database *self);
#endif /* DATABASE_HAS_FIELDS_MEMBER */
static PyObject         *openrj_Database_numRecords(openrj_Database *self);
static PyObject         *openrj_Database_numFields(openrj_Database *self);
static PyObject         *openrj_Database_numLines(openrj_Database *self);

static int              openrj_Database_length(openrj_Database *self);
static PyObject         *openrj_Database_item(openrj_Database *self, int index);
static PyObject         *openrj_Database_slice(openrj_Database *self, int from, int to);

static struct PyMethodDef openrj_Database_methods[] =
{
        {   "path",         (PyCFunction)openrj_Database_path,			METH_NOARGS,    "The path of the database"                      }
    ,   {   "records",      (PyCFunction)openrj_Database_records,		METH_NOARGS,    "A tuple of all the records in the database"    }
#ifdef DATABASE_HAS_FIELDS_MEMBER
    ,   {   "fields",       (PyCFunction)openrj_Database_fields,		METH_NOARGS,    "A tuple of all the fields in the database"     }
#endif /* DATABASE_HAS_FIELDS_MEMBER */
    ,   {   "numRecords",   (PyCFunction)openrj_Database_numRecords,	METH_NOARGS,    "The number of records in the database"         }
    ,   {   "numFields",    (PyCFunction)openrj_Database_numFields,		METH_NOARGS,    "The number of fields in the database"          }
    ,   {   "numLines",     (PyCFunction)openrj_Database_numLines,		METH_NOARGS,    "The number of lines in the database"           }
    ,   {   NULL,           NULL,										0,              NULL                                            }
};

static PySequenceMethods openrj_Database_as_sequence =
{
        (inquiry)           openrj_Database_length  /* sq_length    "len(x)"    */
    ,   (binaryfunc)        0                       /* sq_concat    "x + y"     */
    ,   (intargfunc)        0                       /* sq_repeat    "x * n"     */
    ,   (intargfunc)        openrj_Database_item    /* sq_item      "x[i], in"  */
    ,   (intintargfunc)     openrj_Database_slice   /* sq_slice     "x[i:j]"    */
    ,   (intobjargproc)     0                       /* sq_ass_item  "x[i] = v"  */
    ,   (intintobjargproc)  0                       /* sq_ass_slice "x[i:j]=v"  */
    ,   (objobjproc)        0                       /* sq_contains              */
    ,   (binaryfunc)        0                       /* sq_inplace_concat        */
    ,   (intargfunc)        0                       /* sq_inplace_repeat        */
};

statichere PyTypeObject openrj_Database_Type =
{
        PyObject_HEAD_INIT(NULL)
        0
    ,   "Database"
    ,   sizeof(openrj_Database)
    ,   0
    ,   (destructor)    openrj_Database_dealloc     /* tp_dealloc               */
    ,   (printfunc)     openrj_Database_print       /* tp_print                 */
    ,   (getattrfunc)   openrj_Database_getattr     /* tp_getattr               */
    ,   0                                           /* tp_setattr               */
    ,   0                                           /* tp_compare               */
    ,   0                                           /* tp_repr                  */
    ,   0                                           /* tp_as_number     (PyNumberMethods*)      */
    ,   &openrj_Database_as_sequence                /* tp_as_sequence   (PySequenceMethods*)    */
    ,   0                                           /* tp_as_mapping    (PyMappingMethods*) */
    ,   0                                           /* tp_hash                  */
    ,   0                                           /* tp_call                  */
    ,   0                                           /* tp_str                   */
    ,   0                                           /* tp_getattro              */
    ,   0                                           /* tp_setattro              */
    ,   0                                           /* tp_as_buffer             */
    ,   0                                           /* tp_flags                 */
    ,   0                                           /* tp_doc                   */
    ,   0                                           /* tp_traverse              */
    ,   0                                           /* tp_clear                 */
    ,   0                                           /* tp_richcompare           */
    ,   0                                           /* tp_weaklistoffset        */
    ,   0                                           /* tp_iter                  */
    ,   0                                           /* tp_iternext              */
    ,   0                                           /* tp_methods               */
    ,   0                                           /* tp_members               */
    ,   0                                           /* tp_getset                */
    ,   0                                           /* tp_base                  */
    ,   0                                           /* tp_dict                  */
    ,   0                                           /* tp_descr_get             */
    ,   0                                           /* tp_descr_set             */
    ,   0                                           /* tp_dictoffset            */
    ,   0                                           /* tp_init                  */
    ,   0                                           /* tp_alloc                 */
    ,   0                                           /* tp_new                   */
    ,   0                                           /* tp_free                  */
    ,   0                                           /* tp_is_gc                 */
    ,   0                                           /* tp_bases                 */
    ,   0                                           /* tp_mro                   */
    ,   0                                           /* tp_cache                 */
    ,   0                                           /* tp_subclasses            */
    ,   0                                           /* tp_weaklist              */
#ifdef COUNT_ALLOCS
    ,   0                                           /* tp_allocs                */
    ,   0                                           /* tp_frees                 */
    ,   0                                           /* tp_maxalloc              */
    ,   0                                           /* tp_next                  */
#endif /* COUNT_ALLOCS */
};

/* /////////////////////////////////////////////////////////////////////////////
 * openrj module type and method declarations
 */

static PyObject *openrj_open_file(PyObject *self, PyObject *args);
static PyObject *openrj_open_memory(PyObject *self, PyObject *args);

static PyMethodDef openrj_methods[] =
{
        {
                "open"
            ,   (PyCFunction)openrj_open_file
            ,   METH_VARARGS
            ,   "Opens an Open-RJ database file, and returns a corresponding Database instance. This method is obsolete, and open_file() should be preferred."
        }
    ,   {
                "open_file"
            ,   (PyCFunction)openrj_open_file
            ,   METH_VARARGS
            ,   "Opens an Open-RJ database file, and returns a corresponding Database instance."
        }
    ,   {
                "open_memory"
            ,   (PyCFunction)openrj_open_memory
            ,   METH_VARARGS
            ,   "Opens an Open-RJ database in the given memory, and returns a corresponding Database instance."
        }
    ,   {
                NULL
            ,   NULL
            ,   0
            ,   NULL
        }
};

/* /////////////////////////////////////////////////////////////////////////////
 * Module entry
 */

DL_EXPORT(void) initopenrj(void)
{
    PyObject    *module;

    openrj_Database_Type.ob_type = &PyType_Type;
    openrj_Record_Type.ob_type = &PyType_Type;
    openrj_Field_Type.ob_type = &PyType_Type;

    module  =   Py_InitModule("openrj", openrj_methods);

    if(NULL != module)
    {
        char        openrjVersion[101];
        char        openrjPythonVersion[101];
        PyObject    *dictionary     =   PyModule_GetDict(module);
        PyObject    *ORDER_FIELDS;
        PyObject    *ELIDE_BLANK_RECORDS;
        PyObject    *IGNORE_CASE_ON_LOOKUP;
        PyObject    *NO_REINTERPRET_FIELD_IDS;
        PyObject    *OPENRJ_VERSION;
        PyObject    *VERSION;

        /* Create the module's exception type */
        DatabaseExceptionObject =   Py_BuildValue("s", "openrj.error");

        PyDict_SetItemString(dictionary, "error", DatabaseExceptionObject);

        /* Add the version constants */
        sprintf(openrjVersion, "%d.%d.%d", OPENRJ_VER_MAJOR, OPENRJ_VER_MINOR, OPENRJ_VER_REVISION);
        sprintf(openrjPythonVersion, "%d.%d.%d", OPENRJ_VER_C_OPENRJ_PYTHON_MAJOR, OPENRJ_VER_C_OPENRJ_PYTHON_MINOR, OPENRJ_VER_C_OPENRJ_PYTHON_REVISION);

        OPENRJ_VERSION      =   Py_BuildValue("s", openrjVersion);
        VERSION             =   Py_BuildValue("s", openrjPythonVersion);

        PyDict_SetItemString(dictionary, "OPENRJ_VERSION",OPENRJ_VERSION);
        PyDict_SetItemString(dictionary, "VERSION", VERSION);
        PyDict_SetItemString(dictionary, "__openrj_version__",OPENRJ_VERSION);
        PyDict_SetItemString(dictionary, "__version__", VERSION);

        /* Add the other "constants" */
        ORDER_FIELDS				=   PyInt_FromLong(ORJ_FLAG_ORDERFIELDS);
        ELIDE_BLANK_RECORDS			=   PyInt_FromLong(ORJ_FLAG_ELIDEBLANKRECORDS);
		IGNORE_CASE_ON_LOOKUP		=	PyInt_FromLong(ORJ_FLAG_IGNORECASEONLOOKUP);
		NO_REINTERPRET_FIELD_IDS	=	PyInt_FromLong(ORJ_FLAG_NOREINTERPRETFIELDIDS);

        PyDict_SetItemString(dictionary, "ORDER_FIELDS", ORDER_FIELDS);
        PyDict_SetItemString(dictionary, "ELIDE_BLANK_RECORDS", ELIDE_BLANK_RECORDS);
        PyDict_SetItemString(dictionary, "REINTERPRET_FIELD_IDS", ELIDE_BLANK_RECORDS);
        PyDict_SetItemString(dictionary, "IGNORE_CASE_ON_LOOKUP", IGNORE_CASE_ON_LOOKUP);
    }

    if(PyErr_Occurred())
    {
        Py_FatalError("can't initialize openrj module");
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * openrj module methods
 */

static PyObject *openrj_open_file(PyObject *self, PyObject *args)
{
    char    *path;
    long    flags;

    if(!PyArg_ParseTuple(args, "sl", &path, &flags))
    {
        return NULL;
    }
    else
    {
        ORJDatabase const   *database;
        ORJError            error;
        ORJRC               rc  =   ORJ_ReadDatabaseA(path, NULL, flags, &database, &error);

#ifdef TRACE_METHODS
        fprintf(stderr, "openrj.open_file(%s, 0x%08x)\n", path, flags);
#endif /* TRACE_METHODS */

        if(ORJ_RC_SUCCESS != rc)
        {
            char    szError[1001];

            if(rc == ORJ_RC_PARSEERROR)
            {
                sprintf(szError, "parsing error in database, at line %u, column %u; parse error: %u, %s", error.invalidLine, error.invalidColumn, error.parseError, ORJ_GetParseErrorStringA(error.parseError));
            }
            else
            {
                sprintf(szError, "failed to open database; error: %u, %s", rc, ORJ_GetErrorStringA(rc));
            }

            PyErr_SetString(DatabaseExceptionObject, szError);

            return NULL;
        }
        else
        {
            return (PyObject*)openrj_Database_alloc(self, database, path);
        }
    }
}

static PyObject *openrj_open_memory(PyObject *self, PyObject *args)
{
    char    *contents;
    long    flags;

    if(!PyArg_ParseTuple(args, "sl", &contents, &flags))
    {
        return NULL;
    }
    else
    {
        ORJDatabase const   *database;
        ORJError            error;
        size_t              len =   strlen(contents);
        ORJRC               rc  =   ORJ_CreateDatabaseFromMemoryA(contents, len, NULL, flags, &database, &error);

#ifdef TRACE_METHODS
        fprintf(stderr, "openrj.open_memory(0x%08x)\n", flags);
#endif /* TRACE_METHODS */

        if(ORJ_RC_SUCCESS != rc)
        {
            char    szError[1001];

            if(rc == ORJ_RC_PARSEERROR)
            {
                sprintf(szError, "parsing error in database, at line %u, column %u; parse error: %u, %s", error.invalidLine, error.invalidColumn, error.parseError, ORJ_GetParseErrorStringA(error.parseError));
            }
            else
            {
                sprintf(szError, "failed to open database; error: %u, %s", rc, ORJ_GetErrorStringA(rc));
            }

            PyErr_SetString(DatabaseExceptionObject, szError);

            return NULL;
        }
        else
        {
            return (PyObject*)openrj_Database_alloc(self, database, "");
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * ORJDatabase_holder methods
 */

static ORJDatabase_holder *ORJDatabase_holder_create(ORJDatabase const *database)
{
    ORJDatabase_holder  *dbh    =   (ORJDatabase_holder*)PyObject_Malloc(sizeof(ORJDatabase_holder));

    if(NULL != dbh)
    {
        dbh->database   =   database;
        dbh->cRefs      =   1;
    }

    return dbh;
}

static void ORJDatabase_holder_addref(ORJDatabase_holder *dbh)
{
#ifdef WIN32
    InterlockedIncrement(&dbh->cRefs);
#else /* ? WIN32 */
    ++dbh->cRefs;
#endif /* WIN32 */
}

static void ORJDatabase_holder_release(ORJDatabase_holder *dbh)
{
#ifdef WIN32
    if(0 == InterlockedDecrement(&dbh->cRefs))
#else /* ? WIN32 */
    if(0 == --dbh->cRefs)
#endif /* WIN32 */
    {
        ORJ_FreeDatabaseA(dbh->database);

        PyObject_Free(dbh);
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * Field methods
 */

static openrj_Field *openrj_Field_alloc(PyObject *self, ORJField const *field, ORJDatabase_holder *dbh)
{
    openrj_Field    *f  = PyObject_New(openrj_Field, &openrj_Field_Type);

    if(NULL == f)
    {
        PyErr_SetFromErrno(self);
    }
    else
    {
        f->field    =   field;
        f->dbh      =   dbh;

        ORJDatabase_holder_addref(dbh);

        add_instance();
    }

#ifdef TRACE_CTORS
    fprintf(stderr, "Field(0x%p) - %s, %d\n", f, (NULL != f) ? "succeeded" : "failed", get_num_instances());
#endif /* TRACE_CTORS */

    return f;
}

static void openrj_Field_dealloc(openrj_Field *self)
{
    ORJDatabase_holder_release(self->dbh);

    PyObject_Del(self);

    del_instance();

#ifdef TRACE_DTORS
    fprintf(stderr, "~Field(0x%p), %d\n", self, get_num_instances());
#endif /* TRACE_DTORS */
}

static int openrj_Field_print(openrj_Field *self, FILE *file, int flags)
{
    if(flags & Py_PRINT_RAW)
    {
        fprintf(file, "<Field object at 0x%p; field=0x%p; name=%.*s; value=%.*s>", self, self->field, self->field->name.len, self->field->name.ptr, self->field->value.len, self->field->value.ptr);
    }
    else
    {
        fprintf(file, "\"<Field object at 0x%p; field=0x%p; name=%.*s; value=%.*s>\"", self, self->field, self->field->name.len, self->field->name.ptr, self->field->value.len, self->field->value.ptr);
    }

    return 0;
}

static PyObject *openrj_Field_getattr(openrj_Field *self, char const *name)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Field(0x%p).__attr__(%s)\n", self, name);
#endif /* TRACE_METHODS */

    return Py_FindMethod(openrj_Field_methods, (PyObject*)self, (char*)name);
}

static int openrj_Field_compare(openrj_Field *lhs, openrj_Field *rhs)
{
    int		res;
	size_t	len	=	lhs->field->name.len;

	if(rhs->field->name.len < len)
	{
		len = rhs->field->name.len;
	}

#ifdef TRACE_METHODS
    fprintf(stderr, "Field(0x%p).compare(0x%p)\n", lhs, rhs);
#endif /* TRACE_METHODS */

    res = strncmp(lhs->field->name.ptr, rhs->field->name.ptr, min(lhs->field->name.len, rhs->field->name.len));

    if(0 == res)
    {
        res = strncmp(lhs->field->value.ptr, rhs->field->value.ptr, min(lhs->field->value.len, rhs->field->value.len));
    }

    return res;
}


static PyObject *openrj_Field_name(openrj_Field *self)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Field(0x%p).name()\n", self);
#endif /* TRACE_METHODS */

    return Py_BuildValue("s#", self->field->name.ptr, self->field->name.len);
}

static PyObject *openrj_Field_value(openrj_Field *self)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Field(0x%p).value()\n", self);
#endif /* TRACE_METHODS */

    return Py_BuildValue("s#", self->field->value.ptr, self->field->value.len);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Record methods
 */

static openrj_Record *openrj_Record_alloc(PyObject *self, ORJRecord const *record, ORJDatabase_holder *dbh)
{
    openrj_Record *r    = PyObject_New(openrj_Record, &openrj_Record_Type);

    if(NULL == r)
    {
        PyErr_SetFromErrno(self);
    }
    else
    {
        r->dbh      =   NULL;
        r->record   =   NULL;
        r->fields   =   NULL;

        r->dbh      =   dbh;
        ORJDatabase_holder_addref(dbh);
        r->record   =   record;
        r->fields   =   (openrj_Field**)PyObject_Malloc(r->record->numFields * sizeof(openrj_Field*));

        if(NULL == r->fields)
        {
            openrj_Record_dealloc(r);

            PyErr_SetFromErrno(self);

            return NULL;
        }
        else
        {
            size_t  n;

            for(n = 0; n < r->record->numFields; ++n)
            {
                r->fields[n] = NULL;
            }

            for(n = 0; n < r->record->numFields; ++n)
            {
                if(NULL == (r->fields[n] = openrj_Field_alloc(self, &record->fields[n], r->dbh)))
                {
                    openrj_Record_dealloc(r);

                    r = NULL;

                    break;
                }
            }
        }
    }

    if(NULL != r)
    {
        add_instance();
    }

#ifdef TRACE_CTORS
    fprintf(stderr, "Record(0x%p) - %s, %d\n", r, (NULL != r) ? "succeeded" : "failed", get_num_instances());
#endif /* TRACE_CTORS */

    return r;
}

static void openrj_Record_dealloc(openrj_Record *self)
{
    if(NULL != self->fields)
    {
        size_t  n;

        for(n = 0; n < self->record->numFields; ++n)
        {
            if(NULL != self->fields[n])
            {
                Py_DECREF(self->fields[n]);
            }
        }
    }

    if(NULL != self->dbh)
    {
        ORJDatabase_holder_release(self->dbh);
    }

    PyObject_Del(self);

    del_instance();

#ifdef TRACE_DTORS
    fprintf(stderr, "~Record(0x%p), %d\n", self, get_num_instances());
#endif /* TRACE_DTORS */
}

static int openrj_Record_print(openrj_Record *self, FILE *file, int flags)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "print Record(0x%p)\n", self);
#endif /* TRACE_METHODS */

    if(flags & Py_PRINT_RAW)
    {
        fprintf(file, "<Record object at 0x%p; #fields=%d>", self, self->record->numFields);
    }
    else
    {
        fprintf(file, "\"<Record object at 0x%p; #fields=%d>\"", self, self->record->numFields);
    }

    return 0;
}

static PyObject *openrj_Record_getattr(openrj_Record *self, char const *name)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Record(0x%p).__attr__(%s)\n", self, name);
#endif /* TRACE_METHODS */

    if(0 == strcmp(name, "len"))
    {
        return Py_BuildValue("i", openrj_Record_length(self));
    }
    else if(0 == strcmp(name, "comment"))
    {
	    return Py_BuildValue("s#", self->record->comment.ptr, self->record->comment.len);
    }
    else
    {
        return Py_FindMethod(openrj_Record_methods, (PyObject*)self, (char*)name);
    }
}

static int openrj_Record_compare(openrj_Record *lhs, openrj_Record *rhs)
{
    int res;

#ifdef TRACE_METHODS
    fprintf(stderr, "Record(0x%p).compare(0x%p)\n", lhs, rhs);
#endif /* TRACE_METHODS */

    if(lhs->record == rhs->record)
    {
        res = 0;
    }
    else
    {
        res =   (int)lhs->record->numFields - (int)rhs->record->numFields;

        if(0 == res)
        {
            size_t  i;

            for(i = 0; i < lhs->record->numFields && 0 == res; ++i)
            {
                res = openrj_Field_compare(lhs->fields[i], rhs->fields[i]);
            }
        }
    }

    return res;
}

static int openrj_Record_length(openrj_Record *self)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "len(Record(0x%p))\n", self);
#endif /* TRACE_METHODS */

    return self->record->numFields;
}

static PyObject *openrj_Record_item(openrj_Record *self, int index)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Record(0x%p)[%d]\n", self, index);
#endif /* TRACE_METHODS */

    if( index < 0 ||
        index >= (int)self->record->numFields)
    {
        PyErr_SetString(PyExc_IndexError, "index out-of-bounds");

        return NULL;
    }
    else
    {
        openrj_Field    *field =    self->fields[index];

        Py_INCREF(field);

        return (PyObject*)field;
    }
}

static PyObject *openrj_Record_slice(openrj_Record *self, int from, int to)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Record(0x%p)[%d:%d]\n", self, from, to);
#endif /* TRACE_METHODS */

    if( to < from ||
        from < 0 ||
        to > (int)self->record->numFields)
    {
        char    szError[1001];

        sprintf(szError, "invalid indexes in slice operands [%d:%d]; available range is [%d:%d]", from, to, 0, self->record->numFields);

        PyErr_SetString(PyExc_IndexError, szError);

        return NULL;
    }
    else
    {
        PyObject    *tuple  =   PyTuple_New(to - from);

        if(NULL == tuple)
        {
            PyErr_SetFromErrno((PyObject*)self);

            return NULL;
        }
        else
        {
            int index;

            for(index = 0; from != to; ++from, ++index)
            {
                openrj_Field    *field  =   self->fields[from];
/*
                int                 rc_pre  =   field->ob_refcnt;
                int                 rc_post;
*/

/*
    {
        PyObject    *tuple  =   PyTuple_New(1);
        int         rc_pre  =   field->ob_refcnt;
        int         rc_post;

        Py_INCREF((PyObject*)field);

        PyTuple_SetItem(tuple, 0, (PyObject*)field);

        rc_post = field->ob_refcnt;

        printf("field %p in TUPLE, ref-cnt: %d => %d\n", field, rc_pre, rc_post);

        Py_DECREF(tuple);

        rc_post = field->ob_refcnt;

        printf("field %p after ~TUPLE, ref-cnt: %d => %d\n", field, rc_pre, rc_post);

        exit(0);
    }
*/
                /* PyTuple_SetItem is one of the few functions that steals a reference,
                 * so we need to do an explicit reference increase to keep things
                 * balanced.
                 */
                Py_INCREF((PyObject*)field);

                if(-1 == PyTuple_SetItem(tuple, index, (PyObject*)field))
                {
                    Py_DECREF(tuple);

                    PyErr_SetFromErrno((PyObject*)self);

                    return NULL;
                }

/*
    printf("tuple[%d]: %p\n", index, PyTuple_GET_ITEM(tuple, index));

                rc_post = field->ob_refcnt;

    printf("field %p, ref-cnt: %d => %d\n", field, rc_pre, rc_post);
*/
            }
        }

        return tuple;
    }
}

#if 0
static PyObject *openrj_Record_getitem(openrj_Record *self, PyObject *arg)
{
    char    *index;

#ifdef TRACE_METHODS
    fprintf(stderr, "Record(0x%p)__get_item__\n", self);
#endif /* TRACE_METHODS */

    if(!PyArg_ParseTuple(arg, "(s)", &index))
    {
#ifdef TRACE_METHODS
        fprintf(stderr, "Record(0x%p)[\"\"]\n", self);
#endif /* TRACE_METHODS */

        return NULL;
    }
    else
    {
#ifdef TRACE_METHODS
        fprintf(stderr, "Record(0x%p)[%s]\n", self, index);
#endif /* TRACE_METHODS */

        return NULL;

#if 0
        if( index < 0 ||
            index >= (int)self->record->numFields)
        {
            return NULL;
        }
        else
        {
            openrj_Field    *field =    self->fields[index];

            Py_INCREF(field);

            return (PyObject*)field;
        }
#endif /* 0 */
    }
}
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Database methods
 */

static openrj_Database *openrj_Database_alloc(PyObject *self, ORJDatabase const *database, char const *path)
{
    openrj_Database *db = PyObject_New(openrj_Database, &openrj_Database_Type);

    if(NULL == db)
    {
        PyErr_SetFromErrno(self);
    }
    else
    {
        db->dbh         =   NULL;
        db->database    =   NULL;
        db->path        =   NULL;
        db->records     =   NULL;
#ifdef DATABASE_HAS_FIELDS_MEMBER
        db->fields      =   NULL;
#endif /* DATABASE_HAS_FIELDS_MEMBER */

        db->dbh         =   ORJDatabase_holder_create(database);
        db->database    =   database;
        db->path        =   strdup(path);
        db->records     =   (openrj_Record**)PyObject_Malloc(db->database->numRecords * sizeof(openrj_Record*));

        if( NULL == db->path ||
            NULL == db->records)
        {
            openrj_Database_dealloc(db);

            PyErr_SetFromErrno(self);

            db = NULL;
        }
        else
        {
            size_t  n;

            for(n = 0; n < db->database->numRecords; ++n)
            {
                db->records[n] = NULL;
            }

            for(n = 0; n < db->database->numRecords; ++n)
            {
                if(NULL == (db->records[n] = openrj_Record_alloc(self, &database->records[n], db->dbh)))
                {
                    openrj_Database_dealloc(db);

                    db = NULL;

                    break;
                }
            }

#ifdef DATABASE_HAS_FIELDS_MEMBER
            if(NULL != db)
            {
                db->fields      =   (openrj_Field**)PyObject_Malloc(db->database->numFields * sizeof(openrj_Field*));;

                if(NULL == db->fields)
                {
                    openrj_Database_dealloc(db);

                    PyErr_SetFromErrno(self);

                    db = NULL;
                }
                else
                {
                    size_t  m;

                    for(m = 0, n = 0; n < db->database->numRecords; ++n)
                    {
                        size_t          l;
                        openrj_Record   *record =   db->records[n];

                        for(l = 0; l < record->record->numFields; ++m, ++l)
                        {
//fprintf(stderr, "Making fields - 4; l=%d, m=%d, n=%d; numFields=%d\n", l, m, n, record->record->numFields);

                            db->fields[m] = record->fields[l];

                            Py_INCREF(db->fields[m]);
                        }
                    }
                }
            }
#endif /* DATABASE_HAS_FIELDS_MEMBER */
        }
    }

    if(NULL != db)
    {
        add_instance();
    }

#ifdef TRACE_CTORS
    fprintf(stderr, "Database(0x%p) - %s, %d\n", db, (NULL != db) ? "succeeded" : "failed", get_num_instances());
#endif /* TRACE_CTORS */

    return db;
}

static void openrj_Database_dealloc(openrj_Database *self)
{
#ifdef DATABASE_HAS_FIELDS_MEMBER
    if(NULL != self->fields)
    {
        size_t  n;

        for(n = 0; n < self->database->numFields; ++n)
        {
            if(NULL != self->fields[n])
            {
                Py_DECREF(self->fields[n]);
            }
        }

        PyObject_Free(self->fields);
    }
#endif /* DATABASE_HAS_FIELDS_MEMBER */

    if(NULL != self->records)
    {
        size_t  n;

        for(n = 0; n < self->database->numRecords; ++n)
        {
            if(NULL != self->records[n])
            {
                Py_DECREF(self->records[n]);
            }
        }

        PyObject_Free(self->records);
    }

    if(NULL != self->path)
    {
        free(self->path);
    }

    if(NULL != self->dbh)
    {
        ORJDatabase_holder_release(self->dbh);
    }

    PyObject_Del(self);

    del_instance();

#ifdef TRACE_DTORS
    fprintf(stderr, "~Database(0x%p), %d\n", self, get_num_instances());
#endif /* TRACE_DTORS */
}

static int openrj_Database_print(openrj_Database *self, FILE *file, int flags)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "print Database(0x%p)\n", self);
#endif /* TRACE_METHODS */

    if(flags & Py_PRINT_RAW)
    {
        fprintf(file, "<Database object at 0x%p; path=%s; flags=0x%08x>", self, self->path, self->database->flags);
    }
    else
    {
        fprintf(file, "\"<Database object at 0x%p; path=%s; flags=0x%08x>\"", self, self->path, self->database->flags);
    }

    return 0;
}

static PyObject *openrj_Database_getattr(openrj_Database *self, char const *name)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p).__attr__(%s)\n", self, name);
#endif /* TRACE_METHODS */

    if(0 == strcmp(name, "len"))
    {
        return Py_BuildValue("i", openrj_Database_length(self));
    }
    else
    {
        return Py_FindMethod(openrj_Database_methods, (PyObject*)self, (char*)name);
    }
}

static PyObject *openrj_Database_path(openrj_Database *self)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p).path()\n", self);
#endif /* TRACE_METHODS */

    return Py_BuildValue("s", self->path);
}

static PyObject *openrj_Database_records(openrj_Database *self)
{
    return openrj_Database_slice(self, 0, self->database->numRecords);
}

#ifdef DATABASE_HAS_FIELDS_MEMBER
static PyObject *openrj_Database_fields(openrj_Database *self)
{
    PyObject    *tuple  =   PyTuple_New(self->database->numFields);

#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p).fields\n", self);
#endif /* TRACE_METHODS */

    if(NULL == tuple)
    {
        PyErr_SetFromErrno((PyObject*)self);

        return NULL;
    }
    else
    {
        size_t index;

//  fprintf(stderr, "Database(0x%p).fields (%d)\n", self, self->database->numFields);

        for(index = 0; index < self->database->numFields; ++index)
        {
            openrj_Field *field =   self->fields[index];

//  fprintf(stderr, "Database(0x%p).fields (%d); [%d]: %p\n", self, self->database->numFields, index, field);


            Py_INCREF((PyObject*)field);

            if(-1 == PyTuple_SetItem(tuple, index, (PyObject*)field))
            {
                Py_DECREF(tuple);

                PyErr_SetFromErrno((PyObject*)self);

                return NULL;
            }
        }
    }

    return tuple;
}
#endif /* DATABASE_HAS_FIELDS_MEMBER */

static PyObject *openrj_Database_numRecords(openrj_Database *self)
{
    return PyInt_FromLong(self->database->numRecords);
}

static PyObject *openrj_Database_numFields(openrj_Database *self)
{
    return PyInt_FromLong(self->database->numFields);
}

static PyObject *openrj_Database_numLines(openrj_Database *self)
{
    return PyInt_FromLong(self->database->numLines);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Database PySequence methods
 */

static int openrj_Database_length(openrj_Database *self)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p).length()\n", self);
#endif /* TRACE_METHODS */

    return self->database->numRecords;
}

static PyObject *openrj_Database_item(openrj_Database *self, int index)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p)[%d]\n", self, index);
#endif /* TRACE_METHODS */

    if( index < 0 ||
        index >= (int)self->database->numRecords)
    {
        PyErr_SetString(PyExc_IndexError, "index out-of-bounds");

        return NULL;
    }
    else
    {
        openrj_Record *record = self->records[index];

        Py_INCREF(record);

        return (PyObject*)record;
    }
}

static PyObject *openrj_Database_slice(openrj_Database *self, int from, int to)
{
#ifdef TRACE_METHODS
    fprintf(stderr, "Database(0x%p)[%d:%d]\n", self, from, to);
#endif /* TRACE_METHODS */

    if( to < from ||
        from < 0 ||
        to > (int)self->database->numRecords)
    {
        char    szError[1001];

        sprintf(szError, "invalid indexes in slice operands [%d:%d]; available range is [%d:%d]", from, to, 0, self->database->numRecords);

        PyErr_SetString(PyExc_IndexError, szError);

        return NULL;
    }
    else
    {
        PyObject    *tuple  =   PyTuple_New(to - from);

        if(NULL == tuple)
        {
            PyErr_SetFromErrno((PyObject*)self);

            return NULL;
        }
        else
        {
            int index;

            for(index = 0; from != to; ++from, ++index)
            {
                openrj_Record *record = self->records[from];

                Py_INCREF((PyObject*)record);

                if(-1 == PyTuple_SetItem(tuple, index, (PyObject*)record))
                {
                    Py_DECREF(tuple);

                    PyErr_SetFromErrno((PyObject*)self);

                    return NULL;
                }
            }
        }

        return tuple;
    }
}

/* ////////////////////////////////////////////////////////////////////////// */

static long     s_cInstances;

static long get_num_instances()
{
    return s_cInstances;
}

static long add_instance()
{
#ifdef WIN32
    return InterlockedIncrement(&s_cInstances);
#else /* ? WIN32 */
    return ++s_cInstances;
#endif /* WIN32 */
}

static long del_instance()
{
#ifdef WIN32
    return InterlockedDecrement(&s_cInstances);
#else /* ? WIN32 */
    return --s_cInstances;
#endif /* WIN32 */
}

/* ////////////////////////////////////////////////////////////////////////// */
