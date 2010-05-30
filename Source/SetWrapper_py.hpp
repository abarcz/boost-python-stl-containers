/**
 * Wrapper for std::set to act like Python set
 *
 * @author Michal Andrzejewski, Aleksy Barcz
 */
#ifndef STL_TO_PYTHON_CONTAINERS_SET_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_SET_WRAPPER

#include <boost/python/class.hpp>
#include <boost/python/list.hpp>
#include <set>
#include <iostream>

namespace StlContainersWrappers {

template<typename V>
struct SetWrapper {      

	typedef std::set<V, std::less<V>, std::allocator<V> > Set;

    static void add(Set& x, const V& v);                                     

	static void del(Set& x, const V& v);

	static bool in(const Set& x, const V& v);
    
    static boost::python::list getPyList(const Set& x);
    
    static void print(const Set& x);
    
    typedef boost::python::class_<Set> Class_s_;
    
    static void wrap(const std::string& python_name);
};

#include "SetWrapper_py_impl.hpp"
}

#endif
