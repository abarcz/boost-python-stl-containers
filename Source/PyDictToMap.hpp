/**
 * Converts a boost::python::dict to std::map
 *
 * @author: Aleksy Barcz
 */
#ifndef STL_TO_PYTHON_CONTAINERS_DICT_MAP_CONVERTER
#define STL_TO_PYTHON_CONTAINERS_DICT_MAP_CONVERTER
#include <map>
#include <iostream>
#include <boost/python/dict.hpp>
#include <boost/python/object.hpp>
#include <boost/python/extract.hpp>
#include "Flags.hpp"

namespace PyContainersConverters{

/**
 * Converts a boost::python::dict to std::map
 */ 
template<typename Key, typename V>	
std::map<Key, V> pyDictToMap(boost::python::dict);

#include "PyDictToMap_impl.hpp"
}
#endif
