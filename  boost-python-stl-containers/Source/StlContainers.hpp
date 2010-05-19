/**
 * Autor: Aleksy Barcz
 * Opakowywanie specjalizacji nastepujacych klas stl:
 * - std::vector    jako list   (przy uzyciu VectorWrapper)
 * - std::map       jako list   (przy uzyciu MapWrapper) 
 * - std::set       jako dict   (przy uzyciu SetWrapper)
 */
#ifndef STL_TO_PYTHON_CONTAINERS_MAIN_MODULE
#define STL_TO_PYTHON_CONTAINERS_MAIN_MODULE

#include <boost/python/module.hpp>
#include <string>
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"
#include "SetWrapper_py.hpp"

namespace StlContainersWrappers {

/** 
 * Inicjalizuje opakowywanie kontenerow z stl do Pythona
 */
void init_container_wrappers();

}

#endif
