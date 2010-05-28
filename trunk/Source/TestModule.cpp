#include "TestModule.hpp"

using namespace TestModule;

template<typename T>
T TestModule::getVectorSum(std::vector<T> vec) {
    T sum = 0;
    for(int i = 0; i < vec.size(); i++)
		sum += vec[i];
	return sum;
}

BOOST_PYTHON_MODULE(TestModule) {
    boost::python::def("get_vector_sum_int", getVectorSum<int>);
    boost::python::def("get_vector_sum_double", getVectorSum<double>);
    
    boost::python::class_<Foo> ("Foo")
        .def(boost::python::init<int>())    //additional constructor Foo(int)
        .def("getId", &Foo::getId)
    ;
}
