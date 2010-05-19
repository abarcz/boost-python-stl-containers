#include "StlContainers.hpp"

using namespace StlContainersWrappers;

void StlContainersWrappers::init_container_wrappers() {
    //tu nalezy wpisywac specjalizacje ktore maja byc
    //wrappowane do Pythona

    VectorWrapper<int>::wrap("vector_int");
    //VectorWrapper<double>::wrap("vector_double");
    //VectorWrapper<std::string>::wrap("vector_string");
    
    MapWrapper<int,std::string>::wrap("map_int_string");
    //MapWrapper<std::string,double>::wrap("map_string_double");
    
    SetWrapper<int>::wrap("set_int");

	VectorWrapper<double>::wrap("vector_double");
	SetWrapper<double>::wrap("set_double");

	VectorWrapper<std::string>::wrap("vector_string");
	SetWrapper<std::string>::wrap("set_string");

}

BOOST_PYTHON_MODULE(StlContainers) {
    StlContainersWrappers::init_container_wrappers();
}

