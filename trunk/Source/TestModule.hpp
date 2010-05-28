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
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>

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
