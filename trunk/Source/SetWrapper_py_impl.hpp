using namespace StlContainersWrappers;

template<typename V>
void SetWrapper<V>::add(Set& x, V const& v) {
    x.insert(v);
}                                                                         

template<typename V>
void SetWrapper<V>::del(Set& x, const V& v) {
    typename Set::iterator iter;
    iter = x.begin();
    for(; iter != x.end(); ++iter);
        if(*iter == v)
            x.erase(iter);
    
}

template<typename V>
bool SetWrapper<V>::in(Set& x, V const& v) {
    if(x.find(v) != x.end())
        return true;
    return false;
}

template<typename V>
boost::python::list SetWrapper<V>::getPyList(Set& x) {
    boost::python::list pyList;
    for(typename Set::iterator it = x.begin(); it != x.end(); ++it)
        pyList.append(*it);
    return pyList;
}

template<typename V>
void SetWrapper<V>::print(Set& x) {
    int size = x.size();
    if(size == 0)
    {
        std::cout << "set([])" << std::endl;
        return;
    }
    typename std::set<V>::iterator it = x.begin();
    std::cout << "set([";
	for(int i = 0; i < x.size() - 1; i++)
	{
        std::cout << *it << ", ";
        ++it;
    }
	std::cout << *it << "])" << std::endl;
}

template<typename V>
void SetWrapper<V>::wrap(std::string const& python_name) {
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
