/**
 * Autor: Aleksy Barcz, Michal Andrzejewski
 * Wrapper imitujący pythonowy dict za pomocą std::set
 */
#ifndef STL_TO_PYTHON_CONTAINERS_SET_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_SET_WRAPPER

#include <boost/python/class.hpp>
#include <set>

namespace StlContainersWrappers {

template<typename V>
struct SetWrapper {      

	typedef std::set<V, std::less<V>, std::allocator<V> > Set;

    static void add(Set& x, V const& v);                                     

	static void del(Set& x, const V& v);

	static bool in(Set& x, V const& v);
    
    typedef boost::python::class_<Set> Class_s_;
    
    static void wrap(std::string const& python_name);
};

#include "SetWrapper_py_impl.hpp"
}

#endif
