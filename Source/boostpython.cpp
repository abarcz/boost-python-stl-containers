#include <boost/python.hpp>

int fun(double d) {
 	return static_cast<int>(d);
}

BOOST_PYTHON_MODULE(example) {
  	boost::python::def("fun", fun); 	
}

int main() {
    return 0;
}
