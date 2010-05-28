/**
 * Author: Aleksy Barcz
 * Converts a boost::python::list to std::vector
 * */
#ifndef STL_TO_PYTHON_CONTAINERS_LIST_VECTOR_CONVERTER
#define STL_TO_PYTHON_CONTAINERS_LIST_VECTOR_CONVERTER
#include <vector>
#include <iostream>
#include <boost/python/list.hpp>
#include <boost/python/object.hpp>
#include <boost/python/extract.hpp>
#include "Flags.hpp"

namespace PyContainersConverters{

/**
 * Converts a boost::python::list to std::vector
 */ 
template<typename T>	
std::vector<T> pyListToVector(boost::python::list pyList);

#include "PyListToVector_impl.hpp"
}
#endif
