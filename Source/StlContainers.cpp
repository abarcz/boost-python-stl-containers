#include "StlContainers.hpp"

using namespace StlContainersWrappers;

BOOST_PYTHON_MODULE(StlContainers) {
    
    //run containers wrappers
    VectorWrapper<int>::wrap("vector_int");
    SetWrapper<int>::wrap("set_int");

	VectorWrapper<double>::wrap("vector_double");
	SetWrapper<double>::wrap("set_double");

	VectorWrapper<std::string>::wrap("vector_string");
	SetWrapper<std::string>::wrap("set_string");

    MapWrapper<int,std::string>::wrap("map_int_string");
    
    //run converters wrappers
    boost::python::def("py_list_to_vector_int", PyContainersConverters::pyListToVector<int>);
    boost::python::def("py_list_to_vector_double", PyContainersConverters::pyListToVector<double>);
    boost::python::def("py_list_to_vector_string", PyContainersConverters::pyListToVector<std::string>);
}

