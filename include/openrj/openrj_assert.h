/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj_assert.h
 *
 * Purpose: Assertions for the Open-RJ C-API
 *
 * Created: 11th June 2004
 * Updated: 18th February 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
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


/* \file openrj/openrj_assert.h Assertions for the Open-RJ C-API
 *
 */

#ifndef OPENRJ_INCL_H_OPENRJ_ASSERT
#define OPENRJ_INCL_H_OPENRJ_ASSERT

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_H_OPENRJ_ASSERT_MAJOR       1
# define OPENRJ_VER_H_OPENRJ_ASSERT_MINOR       1
# define OPENRJ_VER_H_OPENRJ_ASSERT_REVISION    2
# define OPENRJ_VER_H_OPENRJ_ASSERT_EDIT        6
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#if defined(_MSC_VER)
# include <crtdbg.h>    /* for _ASSERTE() */
#else /* ? compiler */
# include <assert.h>    /* for assert() */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions and macros
 */

#if defined(_MSC_VER)
# define openrj_assert      _ASSERTE
#else /* ? compiler */
# define openrj_assert      assert
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_H_OPENRJ_ASSERT */

/* ////////////////////////////////////////////////////////////////////////// */
