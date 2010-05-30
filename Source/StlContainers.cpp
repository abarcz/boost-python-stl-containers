#include "StlContainers.hpp"

using namespace StlContainersWrappers;

BOOST_PYTHON_MODULE(StlContainers) {
	/**
	 * Wraps common containers into their Python representatives
	 */
    VectorWrapper<int>::wrap("vector_int");
    SetWrapper<int>::wrap("set_int");

	VectorWrapper<double>::wrap("vector_double");
	SetWrapper<double>::wrap("set_double");

	VectorWrapper<std::string>::wrap("vector_string");
	SetWrapper<std::string>::wrap("set_string");

    MapWrapper<int, std::string>::wrap("map_int_string");
    MapWrapper<std::string, std::string>::wrap("map_string_string");
    MapWrapper<int, double>::wrap("map_int_double");
    
	/**
	 * Wraps commont converters of C++ and Python collections
	 */
    boost::python::def("py_list_to_vector_int", PyContainersConverters::pyListToVector<int>);
    boost::python::def("py_list_to_vector_double", PyContainersConverters::pyListToVector<double>);
    boost::python::def("py_list_to_vector_string", PyContainersConverters::pyListToVector<std::string>);
    
    boost::python::def("py_dict_to_map_int_string", PyContainersConverters::pyDictToMap<int, std::string>);
    boost::python::def("py_dict_to_map_string_string", PyContainersConverters::pyDictToMap<std::string, std::string>);
    boost::python::def("py_dict_to_map_int_double", PyContainersConverters::pyDictToMap<int, double>);
}

