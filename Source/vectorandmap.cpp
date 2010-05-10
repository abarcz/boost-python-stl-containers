#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/class_fwd.hpp>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef std::vector<int> Int;
typedef std::map<int, string> Map;

template<class T>
struct vector_item {

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
struct map_item {
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

BOOST_PYTHON_MODULE(example2) {
 class_<Int>("Int")
  .def("__len__", &Int::size)
  .def("clear", &Int::clear)
  .def("append", &vector_item<Int>::add,
        with_custodian_and_ward<1,2>()) 
  .def("__getitem__", &vector_item<Int>::get)
  .def("__setitem__", &vector_item<Int>::set,
        with_custodian_and_ward<1,2>()) 
  .def("__delitem__", &vector_item<Int>::del)
  //.def("__iter__", iterator<Int>())
  .def("__contains__", &vector_item<Int>::in)
  ;
 
 class_<Map>("Map")
  .def("__len__", &Map::size)
  .def("clear", &Map::clear)
  .def("__getitem__", &map_item<Map>::get)
  .def("__setitem__", &map_item<Map>::set,
  		with_custodian_and_ward<1,2>())
  .def("__delitem__", &map_item<Map>::del)
  ;
}

int main() {
 	return 0;
}
