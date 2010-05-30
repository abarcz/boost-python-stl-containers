/**
 * Wrapper for std::vector to act like Python list
 *
 * @author Michal Andrzejewski, Aleksy Barcz
 */
#ifndef STL_TO_PYTHON_CONTAINERS_VECTOR_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_VECTOR_WRAPPER

#include <boost/python/class.hpp>
#include <boost/python/iterator.hpp>
#include <boost/python/list.hpp>
#include <algorithm>
#include <vector>
#include <iostream>

namespace StlContainersWrappers {
    
template<typename V>
struct VectorWrapper {

    typedef std::vector<V, std::allocator<V> > Vec;

    static const V get(const Vec& x, int i);

    static void set(Vec& x, int i, const V& v);

    static void del(Vec& x, int i);

    static void add(Vec& x, const V& v);                                     

	static bool in(const Vec& x, const V& v);

	static int index(const Vec& x, const V& v);

	static int count(const Vec& x, const V& v);

	static void sort(Vec& x);

	static void reverse(Vec& x);
    
    static boost::python::list getPyList(const Vec& x);
    
    static void print(const Vec& x);
    
    typedef boost::python::class_<Vec> class_v_;
    
    static void wrap(const std::string& python_name);
};

#include "VectorWrapper_py_impl.hpp"
}

#endif
