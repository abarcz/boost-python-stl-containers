#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/class_fwd.hpp>
#include <boost/python/iterator.hpp>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef std::vector<int> Vec;
typedef std::map<int, string> Map;

template<class T>
struct vector_helper {

    typedef int V;

    static const int get(T const& x, int i) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < x.size()) 
			return x[i];
    }

    static void set(T& x, int i, V const& v) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < x.size())
			x[i] = v;
    }

    static void del(T& x, int i) {
        if(i < 0) 
			i += x.size();
        if(i >= 0 && i < x.size()) {
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

template<class T>
struct map_helper {

	typedef int K;
	typedef string V;

	static const string get(T& x, K const& i) {
     	if(x.find(i) != x.end()) 
			return x[i];
	}

	static void set(T& x, K const& i, V const& v) {
     	x[i] = v;
	}

	static void del(T& x, K const& i) {
     	if(x.find(i) != x.end())
			x.erase(i);
	}
};

using namespace boost::python;

BOOST_PYTHON_MODULE(zpr) {
 class_<Vec>("Vec")
  .def("__len__", &Vec::size)
  .def("clear", &Vec::clear)
  .def("append", &vector_helper<Vec>::add,
        with_custodian_and_ward<1,2>()) 
  .def("__getitem__", &vector_helper<Vec>::get)
  .def("__setitem__", &vector_helper<Vec>::set,
        with_custodian_and_ward<1,2>()) 
  .def("__delitem__", &vector_helper<Vec>::del)
  .def("__iter__", boost::python::iterator<Vec>())
  .def("__contains__", &vector_helper<Vec>::in)
  ;
 
 class_<Map>("Map")
  .def("__len__", &Map::size)
  .def("clear", &Map::clear)
  .def("__getitem__", &map_helper<Map>::get)
  .def("__setitem__", &map_helper<Map>::set,
  		with_custodian_and_ward<1,2>())
  .def("__delitem__", &map_helper<Map>::del)
  ;
}

int main() {
 	return 0;
}
