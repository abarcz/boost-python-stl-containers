using namespace StlContainersWrappers;

/**
 * Helper method for adding element into collection
 */
template<typename V>
void SetWrapper<V>::add(Set& x, const V& v) {
    x.insert(v);
}                                                                         

/**
 * Helper method for deleting element specified by its value
 */
template<typename V>
void SetWrapper<V>::del(Set& x, const V& v) {
    typename Set::iterator iter;
    iter = x.begin();
    for(; iter != x.end(); ++iter)
        if(*iter == v)
            x.erase(iter);
}

/**
 * Helper method for checking if element exists in collection
 * @returns true if element exists in collection, false otherwise
 */
template<typename V>
bool SetWrapper<V>::in(const Set& x, const V& v) {
    if(x.find(v) != x.end())
        return true;
    return false;
}

/**
 * Helper method making boost::python::list out of collection elements
 * @returns boost::python::list containing all collection elements
 */
template<typename V>
boost::python::list SetWrapper<V>::getPyList(const Set& x) {
    boost::python::list pyList;
    for(typename Set::const_iterator it = x.begin(); it != x.end(); ++it)
        pyList.append(*it);
    return pyList;
}

/**
 * Helper method for printing collection elements in Python style
 */
template<typename V>
void SetWrapper<V>::print(const Set& x) {
    int size = x.size();
    if(size == 0)
    {
        std::cout << "set([])" << std::endl;
        return;
    }
    typename std::set<V>::const_iterator it = x.begin();
    std::cout << "set([";
	for(int i = 0; i < x.size() - 1; i++)
	{
        std::cout << *it << ", ";
        ++it;
    }
	std::cout << *it << "])" << std::endl;
}

/**
 * Method for actual container wrapping into Python-recognizable names and methods
 */
template<typename V>
void SetWrapper<V>::wrap(const std::string& python_name) {
    Class_s_ wrapped(python_name.c_str());
    wrapped
        .def("__len__", &Set::size)
        .def("clear", &Set::clear)
        .def("append", &add,
            boost::python::with_custodian_and_ward<1,2>())
        .def("__contains__", &in)
        .def("__delitem__", &del)
        .def("get_list", &getPyList)
    ;
    #ifdef STL_TO_PYTHON_CONTAINERS_PRINTABLE
        wrapped.def("print_", &print);
    #endif
}
