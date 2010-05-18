#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/class_fwd.hpp>
#include <boost/python/iterator.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

typedef std::vector<int> Vec;
typedef std::map<int, string> Map;
typedef std::set<int> Set;




template<typename V, template <typename Element, typename Allocator> class Contener = std::vector>
struct vector_helper {

    typedef Contener<V, std::allocator<V> > T;

    static const int get(T const& x, int i) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < (int)x.size()) 
			return x[i];
    }

    static void set(T& x, int i, V const& v) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < (int)x.size())
			x[i] = v;
    }

    static void del(T& x, int i) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < (int)x.size()) {
			typename T::iterator iter;
			iter = x.begin();
			for(int j = 0; j < i; ++j, ++iter);
			x.erase(iter);
		}
    }

    static void add(T& x, V const& v) {
        x.push_back(v);
    }                                                                         

	static bool in(T const& x, V const& v) {
		typename T::const_iterator iter;
		iter = x.begin();
		while(iter != x.end()) {
			if(*iter == v)
				return true;
			++iter;
		}
     	return false;
	}
};


template<typename K, typename V, template <typename Key, typename Element, 
    typename Compare, typename Allocator> class Contener = std::map>
struct map_helper {

	typedef Contener<K, V, std::less<K>, std::allocator<std::pair<const K,V> > > T;

	static const string get(T& x, K const& i) {
     	if(x.find(i) != x.end()) 
			return x[i];
	}

	static void set(T& x, K const& i, V const& v) {
     	x[i] = v;
	}

	static void del(T& x, K const& i) {
		typename T::iterator iter;
		iter = x.begin();
		for(; iter != x.end(); ++iter);
			if(iter->first == i)
				x.erase(iter);
	}
};

template<typename V, template <typename Element, typename Compare, typename Allocator> class Contener = std::set>
struct set_helper {      

	typedef Contener<V, std::less<V>, std::allocator<V> > T;

    static void add(T& x, V const& v) {
        x.insert(v);
    }                                                                         

	static void del(T& x, const V& v) {
		typename T::iterator iter;
		iter = x.begin();
		for(; iter != x.end(); ++iter);
			if(*iter == v)
				x.erase(iter);
     	
	}

	static bool in(T& x, V const& v) {
     	if(x.find(v) != x.end())
			return true;
		return false;
	}
};

using namespace boost::python;


BOOST_PYTHON_MODULE(zpr) {
 class_<Vec>("Vec")
  .def("__len__", &Vec::size)
  .def("clear", &Vec::clear)
  .def("append", &vector_helper<int>::add,
        with_custodian_and_ward<1,2>()) 
  .def("__getitem__", &vector_helper<int>::get)
  .def("__setitem__", &vector_helper<int>::set,
        with_custodian_and_ward<1,2>()) 
  .def("__delitem__", &vector_helper<int>::del)
  .def("__iter__", boost::python::iterator<Vec>())
  .def("__contains__", &vector_helper<int>::in)
  ;
 
 class_<Map>("Map")
  .def("__len__", &Map::size)
  .def("clear", &Map::clear)
  .def("__getitem__", &map_helper<int, std::string>::get)
  .def("__setitem__", &map_helper<int, std::string>::set,
  		with_custodian_and_ward<1,2>())
  .def("__delitem__", &map_helper<int, std::string>::del)
  ;

 class_<Set>("Set")
  .def("__len__", &Set::size)
  .def("clear", &Set::clear)
  .def("append", &set_helper<int>::add,
  		with_custodian_and_ward<1,2>())
  .def("__contains__", &set_helper<int>::in)
  .def("__delitem__", &set_helper<int>::del)
  ;
}


