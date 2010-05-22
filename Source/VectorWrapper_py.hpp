/**
 * Authors: Michal Andrzejewski, Aleksy Barcz
 * Wrapper for std::vector to act like Python list
 */
#ifndef STL_TO_PYTHON_CONTAINERS_VECTOR_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_VECTOR_WRAPPER

#include <boost/python/class.hpp>
#include <boost/python/iterator.hpp>
#include <algorithm>
#include <vector>

namespace StlContainersWrappers {
    
template<typename V>
struct VectorWrapper {

    typedef std::vector<V, std::allocator<V> > Vec;

    static const V get(Vec const& x, int i);

    static void set(Vec& x, int i, V const& v);

    static void del(Vec& x, int i);

    static void add(Vec& x, V const& v);                                     

	static bool in(Vec const& x, V const& v);

	static int index(Vec const& x, V const& v);

	static int count(Vec const& x, V const& v);

	static void sort(Vec& x);

	static void reverse(Vec& x);
    
    typedef boost::python::class_<Vec> class_v_;
    
    static void wrap(std::string const& python_name);
};

#include "VectorWrapper_py_impl.hpp"
}

#endif
