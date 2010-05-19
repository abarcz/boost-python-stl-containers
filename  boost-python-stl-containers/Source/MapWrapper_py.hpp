/**
 * Autor: Michal Andrzejewski, Aleksy Barcz
 * Wrapper imitujący pythonowy list za pomocą std::map
 */
#ifndef STL_TO_PYTHON_CONTAINERS_MAP_WRAPPER
#define STL_TO_PYTHON_CONTAINERS_MAP_WRAPPER

#include <boost/python/class.hpp>
#include <map>

namespace StlContainersWrappers {
    
template<typename Key, typename V>
struct MapWrapper {

	typedef std::map<Key, V, std::less<Key>, std::allocator<std::pair<const Key,V> > > Map;

	static const V get(Map& x, Key const& i);

	static void set(Map& x, Key const& i, V const& v);

	static void del(Map& x, Key const& i);
    
    typedef boost::python::class_<Map> Class_m_;
    
    static void wrap(std::string const& python_name);
};

#include "MapWrapper_py_impl.hpp"

}
#endif
