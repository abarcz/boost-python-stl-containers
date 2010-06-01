#include "Foo.hpp"

using namespace Foos;

BOOST_PYTHON_MODULE(libFoo) {
    boost::python::class_<Foo> ("Foo")
        .def(boost::python::init<int>())    //additional constructor Foo(int)
        .def("getId", &Foo::getId)
    ;
    
    //run containers wrappers
    StlContainersWrappers::VectorWrapper<Foo>::wrap("vector_foo");
    StlContainersWrappers::MapWrapper<int,Foo>::wrap("map_int_foo");
}
