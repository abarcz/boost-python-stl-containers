/**
* Wraps C++ functions and classes necessary to perform StlContainers  
* tests inside Python interpreter.
* 
* @author: Aleksy Barcz
*/
#ifndef STL_CONTAINERS_LIST_TEST_MODULE
#define STL_CONTAINERS_LIST_TEST_MODULE
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <vector>
//#define STL_TO_PYTHON_CONTAINERS_COMPARABLE
//#define STL_TO_PYTHON_CONTAINERS_PRINTABLE
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"

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
    
    int getId() const { return id_; }
    
private:
    int id_;
};

}

#endif
