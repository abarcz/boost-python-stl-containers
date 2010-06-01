#include "Foobar.hpp"

using namespace Foobars;

BOOST_PYTHON_MODULE(libFoobar) {
    boost::python::class_<Foobar> ("Foobar")
        .def(boost::python::init<int>())    //additional constructor Foo(int)
        .def("getId", &Foobar::getId)
        .def(boost::python::self < boost::python::self)     //operator <
        .def(boost::python::self == boost::python::self)    //operator ==
        
        //not necessary for the algorithms to work, but may prove useful:
        .def(boost::python::self > boost::python::self)
        .def(boost::python::self <= boost::python::self)
        .def(boost::python::self >= boost::python::self)
    ;
    
    //run containers wrappers
    StlContainersWrappers::VectorWrapper<Foobar>::wrap("vector_foobar");
    StlContainersWrappers::MapWrapper<int,Foobar>::wrap("map_int_foobar");
    StlContainersWrappers::SetWrapper<Foobar>::wrap("set_foobar");
}


