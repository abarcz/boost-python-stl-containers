#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/class_fwd.hpp>
#include <vector>

using namespace std;

typedef std::vector<int> Int;

template<class T>
struct item {

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
};

using namespace boost::python;

BOOST_PYTHON_MODULE(example2) {
 class_<Int>("Int")
  .def("__len__", &Int::size)
  .def("clear", &Int::clear)
  .def("append", &std_item<Int>::add,
        with_custodian_and_ward<1,2>()) 
  .def("__getitem__", &std_item<Int>::get)
  .def("__setitem__", &std_item<Int>::set,
        with_custodian_and_ward<1,2>()) 
  .def("__delitem__", &std_item<Int>::del)
  ;
}

int main() {
 	return 0;
}
