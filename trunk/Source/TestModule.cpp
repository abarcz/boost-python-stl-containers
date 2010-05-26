#include "TestModule.hpp"

using namespace TestModule;

template<typename T>
void TestModule::printVector(std::vector<T> vec) {
	std::cout << "[";
	for(int i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << ", ";
	std::cout << vec[vec.size() - 1] << "]" << std::endl;
}

template<typename T>
T TestModule::getVectorSum(std::vector<T> vec) {
    T sum = 0;
    for(int i = 0; i < vec.size(); i++)
		sum += vec[i];
	return sum;
}

BOOST_PYTHON_MODULE(TestModule) {
    boost::python::def("print_vector_int", printVector<int>);
    boost::python::def("print_vector_double", printVector<double>);
    boost::python::def("print_vector_string", printVector<std::string>);
    
    boost::python::def("get_vector_sum_int", getVectorSum<int>);
    boost::python::def("get_vector_sum_double", getVectorSum<double>);
}
