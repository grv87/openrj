/* /////////////////////////////////////////////////////////////////////////////
 * File:        OpenRJUtil.cpp
 *
 * Purpose:     Utility functions for the Open-RJ/C++.NET mapping
 *
 * Created:     15th January 2005
 * Updated:     18th February 2005
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, 2004-2005. All rights reserved.
 *
 * Home:        http://www.openrj.orj/
 *
 * ////////////////////////////////////////////////////////////////////////// */


#pragma once

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "stdafx.h"

#include "OpenRJUtil.h"

/* ////////////////////////////////////////////////////////////////////////// */

namespace OpenRJ
{
	namespace
	{
		void *_fnAlloc(::openrj::IORJAllocator * /* m */, size_t cb)
		{
			return (void*)System::Runtime::InteropServices::Marshal::AllocHGlobal(cb);
		}
		void *_fnRealloc(::openrj::IORJAllocator * /* m */, void *pv, size_t cb)
		{
			return (void*)System::Runtime::InteropServices::Marshal::ReAllocHGlobal(pv, (System::IntPtr)(void*)cb);
		}
		void _fnFree(::openrj::IORJAllocator * /* m */, void *pv)
		{
			System::Runtime::InteropServices::Marshal::FreeHGlobal(pv);
		}
	}

	::openrj::IORJAllocator *GetAllocator()
	{
		static ::openrj::IORJAllocator	allocator_ =
		{
				_fnAlloc
			,	_fnRealloc
			,	_fnFree
		};
		static ::openrj::IORJAllocator	*allocator	=	&allocator_;

		return allocator;
	}

} // namespace OpenRJ

/* ////////////////////////////////////////////////////////////////////////// */
