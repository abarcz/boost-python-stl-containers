/**
* Author: Aleksy Barcz
* 
* Wraps C++ functions necessary to perform StlContainers tests 
* inside Python interpreter.
* 
*/
#ifndef STL_CONTAINERS_LIST_TEST_MODULE
#define STL_CONTAINERS_LIST_TEST_MODULE
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
//#define STL_TO_PYTHON_CONTAINERS_COMPARABLE
//#define STL_TO_PYTHON_CONTAINERS_PRINTABLE
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"
#include "SetWrapper_py.hpp"
#include "PyListToVector.hpp"
#include "PyDictToMap.hpp"


namespace TestModule {

/**
* For pyListToVector() tests, prints the sum of elements of a vector
* (elements must support the += operator)
*/
template<typename T>
T getVectorSum(std::vector<T>);

/**
 * For wrappers and converters tests
 */ 
class Foo
{
public:
    Foo() : id_(0) {}

    Foo(int p) : id_(p) {}
    
    int getId() { return id_; }
    
private:
    int id_;
};

}

#endif
