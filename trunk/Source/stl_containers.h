#ifndef STL_TO_PYTHON_CONTAINERS_MAIN_MODULE
#define STL_TO_PYTHON_CONTAINERS_MAIN_MODULE

#include <boost/python/module.hpp>
#include <string>
#include "vector_helper.h"
#include "map_helper.h"
#include "set_helper.h"

namespace stl_containers_wrappers {

/** Inicjalizuje specjalizacje kontenerow:
 *  - std::vector   (przy uzyciu vector_helper)
 *  - std::set      (przy uzyciu set_helper)
 *  - std::map      (przy uzyciu map_helper) 
 */
void init_container_wrappers();

}

#endif
