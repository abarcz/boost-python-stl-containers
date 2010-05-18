using namespace stl_containers_wrappers;

template<typename K, typename V>
const V map_helper<K,V>::get(Map& x, K const& i) {
    if(x.find(i) != x.end()) 
        return x[i];
}

template<typename K, typename V>
void map_helper<K,V>::set(Map& x, K const& i, V const& v) {
    x[i] = v;
}

template<typename K, typename V>
void map_helper<K,V>::del(Map& x, K const& i) {
    typename Map::iterator iter;
    iter = x.begin();
    for(; iter != x.end(); ++iter);
        if(iter->first == i)
            x.erase(iter);
}

template<typename K, typename V>
void map_helper<K,V>::wrap(std::string const& python_name) {
    class_m_ wrapped(python_name.c_str());
    wrapped
        .def("__len__", &Map::size)
        .def("clear", &Map::clear)
        .def("__getitem__", &get)
        .def("__setitem__", &set,
            boost::python::with_custodian_and_ward<1,2>())
        .def("__delitem__", &del)
    ;
}
