#include <boost/python/exec.hpp>
#include <boost/python/import.hpp>
#include <iostream>
#include "stl_containers.h"

using namespace boost::python;

int main() {
    Py_Initialize();                    //inicjalizacja interpretera

    try  {
        object module = import("__main__");
        object globals = module.attr("__dict__");
        
        //Dodanie sciezki biblioteki .so do sciezki Pythona i jej zaladowanie
        exec(
            "print 'Loading shared library' \n"
            "import sys                     \n"
            "sys.path.append(\"./\")        \n"
            "import stl_containers          \n"
            ,globals, globals);
                   
        //test przekazania wektora z Pythona do C++
        std::cout << "\nLaunching cross-language vector passing tests..\n";
        exec(
                "print 'Python: creating wektorPyt containing 202'  \n"
                "wektorPyt = stl_containers.vector_int()            \n"
                "wektorPyt.append(202)                              \n"
                ,globals, globals);
                
        std::vector<int> wektor = extract<std::vector<int> >(globals["wektorPyt"]);
        std::cout << "C++: wektorPyt[0]== " << wektor[0] << std::endl;
        
        //test przekazania wektora z C++ do Pythona
        std::cout << "C++: creating wektorCpp containing 303" << std::endl;
        std::vector<int> wektorCpp;
        wektorCpp.push_back(303);
        globals["wektorCpp"] = ptr(&wektorCpp);
        exec(
                "print 'Python: wektorCpp[0]== '    \n"
                "print wektorCpp[0]                 \n"
                "wektorCpp.append(321)              \n"
                "print wektorCpp[1]                 \n"
                ,globals, globals);
        
        //testy z zewnetrznego pliku .py
        std::cout << "\nLaunching Python tests from test.py..\n";
        exec_file("test.py", globals, globals);
        std::cout << "\nEmbedded Python tests terminated.\n";
        
    } 
    catch (error_already_set) {     //lapie bledy Pythona
        PyErr_Print();
    }

    Py_Finalize();                  //zakonczenie pracy z interpreterem
    
    return 0;
}
