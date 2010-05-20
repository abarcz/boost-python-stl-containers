#include "StlContainers.hpp"

using namespace StlContainersWrappers;

void StlContainersWrappers::init_container_wrappers() {

    VectorWrapper<int>::wrap("vector_int");
    SetWrapper<int>::wrap("set_int");

	VectorWrapper<double>::wrap("vector_double");
	SetWrapper<double>::wrap("set_double");

	VectorWrapper<std::string>::wrap("vector_string");
	SetWrapper<std::string>::wrap("set_string");

    MapWrapper<int,std::string>::wrap("map_int_string");
}

BOOST_PYTHON_MODULE(StlContainers) {
    StlContainersWrappers::init_container_wrappers();
}

