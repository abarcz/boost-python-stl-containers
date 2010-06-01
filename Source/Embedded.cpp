/**
 * Test uses embedded Python interpreter to pass
 * wrapped STL container instances from C++ to Python and vice versa.
 *
 * @author: Aleksy Barcz
 */ 
#include <boost/python/exec.hpp>
#include <boost/python/import.hpp>
#include <boost/test/minimal.hpp>
#include <iostream>
#include <string>
#include "StlContainers.hpp"

using namespace boost::python;

int test_main(int, char* []) {
    Py_Initialize();                    //interpreter

    try  {
        object module = import("__main__");
        object globals = module.attr("__dict__");
        
        //Add the .so's current directory to Python module loader search path 
        //so we can import module StlContainers
        exec(
            "print 'Loading shared library' \n"
            "import sys                     \n"
            "sys.path.append(\"./\")        \n"
            "import libStlContainers        \n"
            ,globals, globals);
                   
        //passing std::vector from Python to C++
        std::cout << "\nLaunching cross-language vector (int, std::string) passing tests..\n" << std::endl;
        exec(
                "wektorPyt = libStlContainers.vector_int()          \n"
                "wektorPyt.append(202)                              \n"
                "wektorPyt.append(123)                              \n"
                "wektorPyt.append(5)                                \n"
                ,globals, globals);
                
        std::vector<int> wektor = extract<std::vector<int> >(globals["wektorPyt"]);
		wektor.push_back(222);
        
        std::vector<int> result;
        result.push_back(202);
        result.push_back(123);
        result.push_back(5);
        result.push_back(222);
        
        BOOST_CHECK((result == wektor));

        //passing std::vector from C++ to Python
        std::vector<std::string> wektorCpp;
        wektorCpp.push_back("agfa");
        wektorCpp.push_back("fasfsdfds");
        wektorCpp.push_back("blabla");
        wektorCpp.push_back("mimi");
        globals["wektorCpp"] = ptr(&wektorCpp);
        exec(
                "wektorCpp.append('gag')            \n"
                "wektorCpp[0] = 'aaaaaaa'           \n"
                ,globals, globals);
        
        std::vector<std::string> result2;      
        result2.push_back("aaaaaaa");
        result2.push_back("fasfsdfds");
        result2.push_back("blabla");
        result2.push_back("mimi");
        result2.push_back("gag");
        
        BOOST_CHECK((result2 == wektorCpp));
    
        std::cout << "Embedded Python tests terminated.\n";
    } 
    catch (error_already_set) {
        PyErr_Print();
    }

    //Py_Finalize();	//end interpreter            
    
    return 0;
}
