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
void SetWrapper<V>::wrap(std::string const& python_name) {
    Class_s_ wrapped(python_name.c_str());
    wrapped
        .def("__len__", &Set::size)
        .def("clear", &Set::clear)
        .def("append", &add,
            boost::python::with_custodian_and_ward<1,2>())
        .def("__contains__", &in)
        .def("__delitem__", &del)
    ;
}