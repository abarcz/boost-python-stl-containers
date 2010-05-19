using namespace StlContainersWrappers;

template<typename Key, typename V>
const V MapWrapper<Key,V>::get(Map& x, Key const& i) {
    if(x.find(i) != x.end()) 
        return x[i];
}

template<typename Key, typename V>
void MapWrapper<Key,V>::set(Map& x, Key const& i, V const& v) {
    x[i] = v;
}

template<typename Key, typename V>
void MapWrapper<Key,V>::del(Map& x, Key const& i) {
    typename Map::iterator iter;
    iter = x.begin();
    for(; iter != x.end(); ++iter);
        if(iter->first == i)
            x.erase(iter);
}

template<typename Key, typename V>
void MapWrapper<Key,V>::wrap(std::string const& python_name) {
    Class_m_ wrapped(python_name.c_str());
    wrapped
        .def("__len__", &Map::size)
        .def("clear", &Map::clear)
        .def("__getitem__", &get)
        .def("__setitem__", &set,
            boost::python::with_custodian_and_ward<1,2>())
        .def("__delitem__", &del)
    ;
}

