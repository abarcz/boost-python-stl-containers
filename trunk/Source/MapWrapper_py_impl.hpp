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
bool MapWrapper<Key,V>::in(Map& x, const Key k) {
	return x.find(k) != x.end();
}

template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::keys(Map& x) {
	boost::python::list t;
	typename Map::iterator iter;
	iter = x.begin();
	for(; iter != x.end(); ++iter)
		t.append(iter->first);
	return t;
}

template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::values(Map& x) {
	boost::python::list t;
	typename Map::iterator iter;
	iter = x.begin();
	for(;iter != x.end(); ++iter)
		t.append(iter->second);
	return t;
}

template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::items(Map& x) {
	boost::python::list t;
	typename Map::iterator iter;
	iter = x.begin();
	for(; iter != x.end(); ++iter)
		t.append(boost::python::make_tuple(iter->first, iter->second));
	return t;
}         

template<typename Key, typename V>
boost::python::dict MapWrapper<Key,V>::getPyDict(Map& x) {
    return boost::python::dict(items(x));
}

template<typename Key, typename V>
void MapWrapper<Key,V>::print(Map& x) {
    int size = x.size();
    if(size == 0)
    {
        std::cout << "{}" << std::endl;
        return;
    }
    typename std::map<Key, V>::iterator it = x.begin();
	std::cout << "{";
	for(int i = 0; i < x.size() - 1; i++)
	{
        std::cout << it->first << ": " << it->second << ", ";
        ++it;
    }
	std::cout << it->first << ": " << it->second << "}" << std::endl;
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
		.def("__contains__", &in)
		.def("has_key", &in)
		.def("keys", &keys)
		.def("values", &values)
		.def("items", &items)
        .def("get_dict", &getPyDict)
    ;
    #ifdef STL_TO_PYTHON_CONTAINERS_PRINTABLE
        wrapped.def("print_", &print);
    #endif
}

