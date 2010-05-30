/**
 * Wrapper for std::map to act like Python dict
 *
 * @author Michal Andrzejewski, Aleksy Barcz
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

/**
 * Template containing methods used to wrap std::map into Python data type
 */	
template<typename Key, typename V>
struct MapWrapper {

	typedef std::map<Key, V, std::less<Key>, std::allocator<std::pair<const Key,V> > > Map;

	static const V get(Map& x, const Key& i);

	static void set(Map& x, const Key& i, const V& v);

	static void del(Map& x, const Key& i);

	static bool in(Map& x, const Key k);

	static boost::python::list keys(const Map& x);

	static boost::python::list values(const Map& x);
	
	static boost::python::list items(const Map& x);
    
    static boost::python::dict getPyDict(const Map& x);
    
    static void print(const Map& x);
    
    typedef boost::python::class_<Map> Class_m_;

    static void wrap(const std::string& python_name);
};

#include "MapWrapper_py_impl.hpp"

}
#endif
