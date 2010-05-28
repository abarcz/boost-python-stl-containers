/**
* Author: Aleksy Barcz
* 
* Wraps C++ functions and classes necessary to perform StlContainers 
* tests inside Python interpreter.
* 
*/
#ifndef STL_CONTAINERS_LIST_TEST_MODULE2
#define STL_CONTAINERS_LIST_TEST_MODULE2
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/operators.hpp>
#define STL_TO_PYTHON_CONTAINERS_COMPARABLE
//#define STL_TO_PYTHON_CONTAINERS_PRINTABLE
#include "VectorWrapper_py.hpp"
#include "MapWrapper_py.hpp"
#include "SetWrapper_py.hpp"

namespace TestModule {

/**
 * For wrappers and converters tests - a comparable user class
 * (not printable though)
 * uses boost::operators for generating additional comparison operators
 */ 
class Foobar : boost::operators<Foobar>
{
public:
    Foobar() : id_(0) {}

    Foobar(int p) : id_(p) {}
    
    bool operator<(const Foobar& x) const {
        return id_ < x.id_;
    }
    
    bool operator==(const Foobar& x) const {
        return id_ == x.id_;
    }
    
    int getId() const { return id_; }
    
private:
    int id_;
};

}

#endif
