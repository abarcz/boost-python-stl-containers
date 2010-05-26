/**
* Author: Aleksy Barcz
* 
* Wraps C++ functions necessary to perform StlContainers tests 
* inside Python interpreter.
* 
*/
#ifndef STL_CONTAINERS_LIST_VECTOR_CONVERTER
#define STL_CONTAINERS_LIST_VECTOR_CONVERTER
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace TestModule {

/**
* for pyListToVector() tests, prints the contents of a vector
*/
template<typename T>
void printVector(std::vector<T>);

/**
* for pyListToVector() tests, prints the sum of elements of a vector
* (elements must support the += operator)
*/
template<typename T>
T getVectorSum(std::vector<T>);

}

#endif
