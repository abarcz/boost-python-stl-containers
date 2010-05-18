#ifndef STL_TO_PYTHON_CONTAINERS_MAP_HELPER
#define STL_TO_PYTHON_CONTAINERS_MAP_HELPER

#include <boost/python/class.hpp>
#include <map>

namespace stl_containers_wrappers {
    
template<typename K, typename V>
struct map_helper {

	typedef std::map<K, V, std::less<K>, std::allocator<std::pair<const K,V> > > Map;

	static const V get(Map& x, K const& i);

	static void set(Map& x, K const& i, V const& v);

	static void del(Map& x, K const& i);
    
    typedef boost::python::class_<Map> class_m_;
    
    static void wrap(std::string const& python_name);
};

#include "map_helper_impl.h"

}
#endif
