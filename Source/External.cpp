/**
 * Test uses embedded Pythona interperter to pass
 * wrapped STL container instances from C++ to Python and vice versa.
 *
 * @author: Michal Andrzejewski, Aleksy Barcz
 */ 
#include <boost/python/exec.hpp>
#include <boost/python/import.hpp>
#include <iostream>

using namespace boost::python;

int main() {
	/**
	 * Initialize embedded Python interpreter
	 */
    Py_Initialize();

    try  {
        object module = import("__main__");
        object globals = module.attr("__dict__");
        
		/**
         * Add the .so's current directory to Python module loader search path 
         * so we can import module StlContainers
		 */
        exec(
            "print 'Loading shared library' \n"
            "import sys                     \n"
            "sys.path.append(\"./\")        \n"
			"sys.path.append(\"./tests\")  	\n"
            "import StlContainers           \n"
            ,globals, globals);
                   

		/*
		 * Run .py tests from ./tests/ directory
		 */
        std::cout << "\nLaunching Python tests from Python_test.py..\n";
        exec_file("tests/Python_test.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_vectors.py..\n";
        exec_file("tests/Python_test_vectors.py", globals, globals);

        std::cout << "\nLaunching Python tests from Python_test_sets.py..\n";
        exec_file("tests/Python_test_sets.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_maps.py..\n";
        exec_file("tests/Python_test_maps.py", globals, globals);

        std::cout << "\nLaunching Python tests from Python_test_vector_foo.py..\n";
        exec_file("tests/Python_test_vector_foo.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_vector_foobar.py..\n";
        exec_file("tests/Python_test_vector_foobar.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_py_list_vector_conversions.py..\n";
        exec_file("tests/Python_test_py_list_vector_conversions.py", globals, globals);
        
        std::cout << "\nLaunching Python tests from Python_test_py_dict_map_conversions.py..\n";
        exec_file("tests/Python_test_py_dict_map_conversions.py", globals, globals);
        
        std::cout << "\nExternal Python tests terminated.\n";
    } 
    catch (error_already_set) {
        PyErr_Print();
    }

    //Py_Finalize();	//end interpreter            
    
    return 0;
}
