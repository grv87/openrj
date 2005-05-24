/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/openrj_implicit_link.h
 *
 * Purpose: Implicit linking for the Open-RJ API
 *
 * Created: 8th April 2005
 * Updated: 25th May 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2005, Matthew Wilson and Synesis Software
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


/** \file openrj/openrj_implicit_link.h Implicit linking for the Open-RJ API
 *
 */

#ifndef OPENRJ_INCL_H_OPENRJ_IMPLICIT_LINK
#define OPENRJ_INCL_H_OPENRJ_IMPLICIT_LINK

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_H_OPENRJ_IMPLICIT_LINK_MAJOR       1
# define OPENRJ_VER_H_OPENRJ_IMPLICIT_LINK_MINOR       0
# define OPENRJ_VER_H_OPENRJ_IMPLICIT_LINK_REVISION    1
# define OPENRJ_VER_H_OPENRJ_IMPLICIT_LINK_EDIT        2
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef OPENRJ_INCL_H_OPENRJ
# include <openrj/openrj.h>
#endif /* !OPENRJ_INCL_H_OPENRJ */

#if defined(__BORLANDC__)
#elif defined(__COMO__)
#elif defined(__DMC__)
#elif defined(__GNUC__)
#elif defined(__INTEL_COMPILER)

# if defined(WIN32)

#  if __INTEL_COMPILER == 600
#   define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl6"
#  elif __INTEL_COMPILER == 700
#   define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl7"
#  elif __INTEL_COMPILER == 800
#   define   OPENRJ_IMPL_LINK_COMPILER_NAME  "icl8"
#  else
#   error Intel C/C++ version not supported
#  endif /* _MSC_VER */

#  if defined(_MT)
#   if defined(_DLL)
#    define  OPENRJ_IMPL_LINK_THREADING_TYPE ".dll"
#   else /* ? _DLL */
#    define  OPENRJ_IMPL_LINK_THREADING_TYPE ".mt"
#   endif /* _DLL */
#  else /* ? _MT */
#   define   OPENRJ_IMPL_LINK_THREADING_TYPE ""
#  endif /* _MT */

#  if defined(_DEBUG)
#   define   OPENRJ_IMPL_LINK_DEBUG_TYPE     ".debug"
#  else /* ? _DEBUG */
#   define   OPENRJ_IMPL_LINK_DEBUG_TYPE     ""
#  endif /* _DEBUG */

#  define    OPENRJ_IMPL_LINK_LIBRARY_NAME   "openrj." OPENRJ_IMPL_LINK_COMPILER_NAME OPENRJ_IMPL_LINK_THREADING_TYPE OPENRJ_IMPL_LINK_DEBUG_TYPE ".lib"

#  pragma comment(lib, OPENRJ_IMPL_LINK_LIBRARY_NAME)



# else /* ? WIN32 */
#  error Open-RJ only supports implicit linking pragmas for Intel compiler on Win32 platform
# endif /* WIN32 */


#elif defined(__MWERKS__)
#elif defined(__WATCOMC__)
#elif defined(_MSC_VER)

# if _MSC_VER == 1200
#  define   OPENRJ_IMPL_LINK_COMPILER_NAME  "vc6"
# elif _MSC_VER == 1300
#  define   OPENRJ_IMPL_LINK_COMPILER_NAME  "vc7"
# elif _MSC_VER == 1310
#  define   OPENRJ_IMPL_LINK_COMPILER_NAME  "vc71"
# elif _MSC_VER == 1400
#  define   OPENRJ_IMPL_LINK_COMPILER_NAME  "vc8"
# else
#  error Visual C++ version not supported
# endif /* _MSC_VER */

# if defined(_MT)
#  if defined(_DLL)
#   define  OPENRJ_IMPL_LINK_THREADING_TYPE ".dll"
#  else /* ? _DLL */
#   define  OPENRJ_IMPL_LINK_THREADING_TYPE ".mt"
#  endif /* _DLL */
# else /* ? _MT */
#  define   OPENRJ_IMPL_LINK_THREADING_TYPE ""
# endif /* _MT */

# if defined(_DEBUG)
#  define   OPENRJ_IMPL_LINK_DEBUG_TYPE     ".debug"
# else /* ? _DEBUG */
#  define   OPENRJ_IMPL_LINK_DEBUG_TYPE     ""
# endif /* _DEBUG */

# define    OPENRJ_IMPL_LINK_LIBRARY_NAME   "openrj." OPENRJ_IMPL_LINK_COMPILER_NAME OPENRJ_IMPL_LINK_THREADING_TYPE OPENRJ_IMPL_LINK_DEBUG_TYPE ".lib"

# pragma comment(lib, OPENRJ_IMPL_LINK_LIBRARY_NAME)

#else /* ? compiler */
# error Compiler not recognised
#endif /* compiler */


/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_H_OPENRJ_IMPLICIT_LINK */

/* ////////////////////////////////////////////////////////////////////////// */
