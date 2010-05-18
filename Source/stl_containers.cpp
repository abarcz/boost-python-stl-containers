#include "stl_containers.h"

using namespace stl_containers_wrappers;

void stl_containers_wrappers::init_container_wrappers() {
    //tu nalezy wpisywac specjalizacje ktore maja byc
    //wrappowane do Pythona

    vector_helper<int>::wrap("vector_int");
    //vector_helper<double>::wrap("vector_double");
    //vector_helper<std::string>::wrap("vector_string");
    
    map_helper<int,std::string>::wrap("map_int_string");
    //map_helper<std::string,double>::wrap("map_string_double");
    
    set_helper<int>::wrap("set_int");
}

BOOST_PYTHON_MODULE(stl_containers) {
    stl_containers_wrappers::init_container_wrappers();
}

