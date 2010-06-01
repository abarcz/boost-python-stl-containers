/**
 * Wraps specializations using:
 * - std::vector    as list   (using VectorWrapper)
 * - std::map       as dict   (using MapWrapper) 
 * - std::set       as set    (using SetWrapper)
 * (Wrappers include to Python converters as get_list(), get_dict())
 * 
 * Wraps converters:
 * list -> std::vector
 * list -> std::set
 * dict -> std::map 
 *
 * @author: Aleksy Barcz
 */
#ifndef STL_TO_PYTHON_CONTAINERS_MAIN_MODULE
#define STL_TO_PYTHON_CONTAINERS_MAIN_MODULE

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <string>
//add methods requiring element comparison to wrappers
#define STL_TO_PYTHON_CONTAINERS_COMPARABLE
//add methods requiring element printing to wrappers
#define STL_TO_PYTHON_CONTAINERS_PRINTABLE
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"
#include "SetWrapper_py.hpp"
#include "PyListToVector.hpp"
#include "PyListToSet.hpp"
#include "PyDictToMap.hpp"

namespace StlContainersWrappers {}

#endif
