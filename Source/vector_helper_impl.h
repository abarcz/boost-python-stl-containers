using namespace stl_containers_wrappers;

template<typename V>
const V vector_helper<V>::get(Vec const& x, int i) {
    if(i < 0) 
        i += x.size();
    if(i >= 0 && i < (int)x.size()) 
        return x[i];
}

template<typename V>
void vector_helper<V>::set(Vec& x, int i, V const& v) {
    if(i < 0) 
        i += x.size();
    if(i >= 0 && i < (int)x.size())
        x[i] = v;
}

template<typename V>
void vector_helper<V>::del(Vec& x, int i) {
    if(i < 0) 
        i += x.size();
    if(i >= 0 && i < (int)x.size()) {
        typename Vec::iterator iter;
        iter = x.begin();
        for(int j = 0; j < i; ++j, ++iter);
        x.erase(iter);
    }
}

template<typename V>
void vector_helper<V>::add(Vec& x, V const& v) {
    x.push_back(v);
}                                                                         

template<typename V>
bool vector_helper<V>::in(Vec const& x, V const& v) {
    typename Vec::const_iterator iter;
    iter = x.begin();
    while(iter != x.end()) {
        if(*iter == v)
            return true;
        ++iter;
    }
    return false;
}

template<typename V>
void vector_helper<V>::wrap(std::string const& python_name) {
    class_v_ wrapped(python_name.c_str());
    wrapped
      .def("__len__", &Vec::size)
      .def("clear", &Vec::clear)
      .def("append", &add,
            boost::python::with_custodian_and_ward<1,2>()) 
      .def("__getitem__", &get)
      .def("__setitem__", &set,
            boost::python::with_custodian_and_ward<1,2>()) 
      .def("__delitem__", &del)
      .def("__iter__", boost::python::iterator<Vec>())
      .def("__contains__", &in)
    ;
}
