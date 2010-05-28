/**
 * Authors: Michal Andrzejewski, Aleksy Barcz
 * Wrapper for std::map to act like Python dict
 */
#ifndef STL_TO_PYTHON_CONTAINERS_MAP_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_MAP_WRAPPER

#include <boost/python/class.hpp>
#include <boost/python/list.hpp>
#include <boost/python/dict.hpp>
#include <boost/python.hpp>
#include <map>
#include <iostream>

namespace StlContainersWrappers {
    
template<typename Key, typename V>
struct MapWrapper {

	typedef std::map<Key, V, std::less<Key>, std::allocator<std::pair<const Key,V> > > Map;

	static const V get(Map& x, Key const& i);

	static void set(Map& x, Key const& i, V const& v);

	static void del(Map& x, Key const& i);

	static bool in(Map& x, const Key k);

	static boost::python::list keys(Map& x);

	static boost::python::list values(Map& x);
	
	static boost::python::list items(Map& x);
    
    static boost::python::dict getPyDict(Map& x);
    
    static void print(Map& x);
    
    typedef boost::python::class_<Map> Class_m_;
    
    static void wrap(std::string const& python_name);
};

#include "MapWrapper_py_impl.hpp"

}
#endif
