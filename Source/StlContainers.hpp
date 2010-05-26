/**
 * Author: Aleksy Barcz
 * Wrapping specializations using:
 * - std::vector    as list   (using VectorWrapper)
 * - std::map       as list   (using MapWrapper) 
 * - std::set       as dict   (using SetWrapper)
 */
#ifndef STL_TO_PYTHON_CONTAINERS_MAIN_MODULE
#define STL_TO_PYTHON_CONTAINERS_MAIN_MODULE

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <string>
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"
#include "SetWrapper_py.hpp"
#include "PyListToVector.hpp"

namespace StlContainersWrappers {}

#endif
