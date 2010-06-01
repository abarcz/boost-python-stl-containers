/**
 * Method extracts Python List items and makes std::set out of those elements
 * @returns std::set made of Python List elements
 */
template<typename T>	
std::set<T> pyListToSet(boost::python::list pyList) {
	std::set<T> s;
    int length = boost::python::len(pyList);
	for(int i = 0; i < length; i++) {
        try {
            boost::python::extract<T> elem(pyList[i]);
            if(!elem.check()) {             //skip if element not convertible
                if(StlContainersFlags::converterWarningsEnable)
                    std::cout << "warning(pyListToSet): element at position "
                    << i << " couldn't be converted due to incorrect type." 
                    << std::endl;
            } 
            else
                s.insert(elem);
        } catch(...) {
            if(StlContainersFlags::converterWarningsEnable)
                std::cout << "warning(pyListToSet): element at position "
                << i << " couldn't be converted, "
                << "probably due to surpassing type limits."<< std::endl;
        }
	}
	return s;
}
