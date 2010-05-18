#ifndef STL_TO_PYTHON_CONTAINERS_VECTOR_HELPER
#define STL_TO_PYTHON_CONTAINERS_VECTOR_HELPER

#include <boost/python/class.hpp>
#include <boost/python/iterator.hpp>
#include <vector>

namespace stl_containers_wrappers {
    
template<typename V>
struct vector_helper {

    typedef std::vector<V, std::allocator<V> > Vec;

    static const V get(Vec const& x, int i);

    static void set(Vec& x, int i, V const& v);

    static void del(Vec& x, int i);

    static void add(Vec& x, V const& v);                                     

	static bool in(Vec const& x, V const& v);
    
    typedef boost::python::class_<Vec> class_v_;
    
    static void wrap(std::string const& python_name);
};

#include "vector_helper_impl.h"
}

#endif
