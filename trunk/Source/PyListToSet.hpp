/**
 * Converts a boost::python::list to std::set
 *
 * @author: Aleksy Barcz
 */
#ifndef STL_TO_PYTHON_CONTAINERS_LIST_SET_CONVERTER
#define STL_TO_PYTHON_CONTAINERS_LIST_SET_CONVERTER
#include <set>
#include <iostream>
#include <boost/python/list.hpp>
#include <boost/python/object.hpp>
#include <boost/python/extract.hpp>
#include "Flags.hpp"

namespace PyContainersConverters{

/**
 * Converts a boost::python::list to std::set
 */ 
template<typename T>	
std::set<T> pyListToSet(boost::python::list pyList);

#include "PyListToSet_impl.hpp"
}
#endif
