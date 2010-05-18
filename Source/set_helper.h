#ifndef STL_TO_PYTHON_CONTAINERS_SET_HELPER
#define STL_TO_PYTHON_CONTAINERS_SET_HELPER

#include <boost/python/class.hpp>
#include <set>

namespace stl_containers_wrappers {

template<typename V>
struct set_helper {      

	typedef std::set<V, std::less<V>, std::allocator<V> > Set;

    static void add(Set& x, V const& v);                                     

	static void del(Set& x, const V& v);

	static bool in(Set& x, V const& v);
    
    typedef boost::python::class_<Set> class_s_;
    
    static void wrap(std::string const& python_name);
};

#include "set_helper_impl.h"
}

#endif
