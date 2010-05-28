
template<typename Key, typename V>	
std::map<Key, V> pyDictToMap(boost::python::dict pyDict) {
    std::map<Key, V> myMap;
    boost::python::list keys = pyDict.keys();
    boost::python::list values = pyDict.values();
    int length = boost::python::len(keys);
    for(int i = 0; i < length; i++) {
        try {
            boost::python::extract<Key> xkey(keys[i]);
            boost::python::extract<V> xval(values[i]);
            //check if key and value types are convertible
            if(xkey.check()) {
                if(xval.check())
                    myMap.insert(std::pair<Key, V>(xkey, xval));
                else {
                    if(StlContainersFlags::converterWarningsEnable)
                        std::cout << "warning(pyDictToMap): value at position "
                        << i << " couldn't be converted due to incorrect type." 
                        << std::endl;
                }
            }
            else {
                if(StlContainersFlags::converterWarningsEnable)
                    std::cout << "warning(pyDictToMap): key at position "
                    << i << " couldn't be converted due to incorrect type." 
                    << std::endl;
            }
           
        } catch(...) {
                if(StlContainersFlags::converterWarningsEnable)
                    std::cout << "warning(pyDictToMap): elements at position "
                    << i << " couldn't be converted, "
                    << "probably due to surpassing type limits."<< std::endl;
        }
    }
    return myMap;
}
