/**
 * Method extracts Python List items and makes std::vector out of those elements
 * @returns std::vector made of Python List elements
 */
template<typename T>	
std::vector<T> pyListToVector(boost::python::list pyList) {
	std::vector<T> vec;
    int length = boost::python::len(pyList);
	for(int i = 0; i < length; i++) {
        try {
            boost::python::extract<T> elem(pyList[i]);
            if(!elem.check()) {             //skip if element not convertible
                if(StlContainersFlags::converterWarningsEnable)
                    std::cout << "warning(pyListToVector): element at position "
                    << i << " couldn't be converted due to incorrect type." 
                    << std::endl;
            } 
            else
                vec.push_back(elem);
        } catch(...) {
            if(StlContainersFlags::converterWarningsEnable)
                std::cout << "warning(pyListToVector): element at position "
                << i << " couldn't be converted, "
                << "probably due to surpassing type limits."<< std::endl;
        }
	}
	return vec;
}
