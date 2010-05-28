/**
 * Autor: Aleksy Barcz
 * Test uses embedded Pythona interperter to pass
 * wrapped STL container instances from C++ to Python and vice versa.
 */ 
#include <boost/python/exec.hpp>
#include <boost/python/import.hpp>
#include <iostream>
#include "StlContainers.hpp"

using namespace boost::python;

int main() {
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
            "import StlContainers           \n"
            ,globals, globals);
                   
        //passing std::vector from Python to C++
        std::cout << "\nLaunching cross-language vector passing tests..\n" << std::endl;
        exec(
                "print 'Python: creating wektorPyt containing 202'  \n"
                "wektorPyt = StlContainers.vector_int()            \n"
                "wektorPyt.append(202)                              \n"
                ,globals, globals);
                
        std::vector<int> wektor = extract<std::vector<int> >(globals["wektorPyt"]);
        std::cout << "C++: wektorPyt[0] == " << wektor[0] << std::endl;
		std::cout << "C++: wektorPyt.push_back(222);" << std::endl;
		wektor.push_back(222);
		std::cout << "C++: wektorPyt[1] == " << wektor[1] << std::endl;
        
        //passing std::vector from C++ to Python
        std::cout << "C++: creating wektorCpp containing 303" << std::endl;
        std::vector<int> wektorCpp;
        wektorCpp.push_back(303);
        globals["wektorCpp"] = ptr(&wektorCpp);
        exec(
                "print 'Python: wektorCpp[0] == '    \n"
                "print wektorCpp[0]                 \n"
				"print 'Python: wektorCpp.append(321)'		\n"
                "wektorCpp.append(321)              \n"
                "print 'Python: wektorCpp[1] == '    \n"
                "print wektorCpp[1]                 \n"
                ,globals, globals);
    
        //a couple of general tests
        std::cout << "\nLaunching Python tests from Python_test.py..\n";
        exec_file("Python_test.py", globals, globals);
        
        //unit tests from external .py files
        std::cout << "\nLaunching Python tests from Python_test_vectors.py..\n";
        exec_file("Python_test_vectors.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_vector_foo.py..\n";
        exec_file("Python_test_vector_foo.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_vector_foobar.py..\n";
        exec_file("Python_test_vector_foobar.py", globals, globals);
        
        //converters test from external .py files
        std::cout << "\nLaunching Python tests from Python_test_py_list_vector_conversions.py..\n";
        exec_file("Python_test_py_list_vector_conversions.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_py_dict_map_conversions.py..\n";
        exec_file("Python_test_py_dict_map_conversions.py", globals, globals);
        
        std::cout << "Embedded Python tests terminated.\n";
    } 
    catch (error_already_set) {
        PyErr_Print();
    }

    //Py_Finalize();	//end interpreter            
    
    return 0;
}
