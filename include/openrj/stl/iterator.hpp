/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/stl/iterator.hpp
 *
 * Purpose: Iterator adaptors for use with the Open-RJ STL mapping
 *
 * Created: 4th September 2005
 * Updated: 28th May 2006
 *
 * Home:    http://openrj.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/** \file openrj/stl/iterator.hpp
 *
 * \brief [C++ only] Iterator type(s) for use with the
 *  \link openrj::stl Open-RJ/STL\endlink mapping.
 */

#ifndef OPENRJ_INCL_OPENRJ_STL_HPP_ITERATOR
#define OPENRJ_INCL_OPENRJ_STL_HPP_ITERATOR

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_OPENRJ_STL_HPP_ITERATOR_MAJOR       1
# define OPENRJ_VER_OPENRJ_STL_HPP_ITERATOR_MINOR       0
# define OPENRJ_VER_OPENRJ_STL_HPP_ITERATOR_REVISION    1
# define OPENRJ_VER_OPENRJ_STL_HPP_ITERATOR_EDIT        3
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <openrj/stl/openrj.hpp>
#include <openrj/stl/field.hpp>

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef __BORLANDC__
# pragma warn -8027
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace openrj
{
namespace stl
{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Class which inserts a field into an associative container
 */
template <typename C>
struct field_assoc_insert_iterator
{
public:
    typedef C                               container_type;
    typedef field_assoc_insert_iterator<C>  class_type;

public:
    /** \brief Constructs an instance which will act on the given container.
     *
     * \param cont [in] The container instance into which elements will be inserted
     */
    field_assoc_insert_iterator(container_type &cont)
        : m_cont(cont)
    {}

    class_type &operator =(openrj::stl::field const &f)
    {
        m_cont[stlsoft::c_str_ptr(f.name())] = stlsoft::c_str_ptr(f.value());

        return *this;
    }

public:
    class_type &operator *()
    {
        return *this;
    }

    class_type &operator ++()
    {
        return *this;
    }

    class_type &operator ++(int)
    {
        return *this;
    }

private:
    container_type  &m_cont;
};

/** \brief Creator function that creates an instance of field_assoc_insert_iterator
 *
 * \param c The container in which elements are to be inserted via the iterator
 */
template <typename C>
inline field_assoc_insert_iterator<C> field_assoc_inserter(C &c)
{
    return field_assoc_insert_iterator<C>(c);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stl
} // namespace openrj

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_OPENRJ_STL_HPP_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
