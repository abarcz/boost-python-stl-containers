using namespace StlContainersWrappers;

/**
 * Helper method for getting map element by key
 * @returns value associated with specified key
 */
template<typename Key, typename V>
const V MapWrapper<Key,V>::get(Map& x, const Key& i) {
    if(x.find(i) != x.end()) 
        return x[i];
}

/**
 * Helper method for setting value of key-specified element
 */
template<typename Key, typename V>
void MapWrapper<Key,V>::set(Map& x, const Key& i, const V& v) {
    x[i] = v;
}

/**
 * Helper method for deleting key-value pair specified by given key
 */
template<typename Key, typename V>
void MapWrapper<Key,V>::del(Map& x, const Key& i) {
    typename Map::iterator iter;
    iter = x.begin();
    for(; iter != x.end(); ++iter);
        if(iter->first == i)
            x.erase(iter);
}                             

/**
 * Helper method for checking if specified key exists in collection
 * @returns true if specified key exists, false otherwise
 */
template<typename Key, typename V>
bool MapWrapper<Key,V>::in(Map& x, const Key k) {
	return x.find(k) != x.end();
}

/**
 * Helper method for getting list of all keys existing in collection
 * @returns boost::python::list of keys
 */
template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::keys(const Map& x) {
	boost::python::list t;
	typename Map::const_iterator iter;
	iter = x.begin();
	for(; iter != x.end(); ++iter)
		t.append(iter->first);
	return t;
}

/**
 * Helper method for getting list of all values existing in collection
 * @returns boost::python::list of values
 */
template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::values(const Map& x) {
	boost::python::list t;
	typename Map::const_iterator iter;
	iter = x.begin();
	for(;iter != x.end(); ++iter)
		t.append(iter->second);
	return t;
}

/**
 * Helper method for getting list of all key-value pairs existing in collection
 * @returns boost::python::list of tuples of key-value pairs
 */
template<typename Key, typename V>
boost::python::list MapWrapper<Key,V>::items(const Map& x) {
	boost::python::list t;
	typename Map::const_iterator iter;
	iter = x.begin();
	for(; iter != x.end(); ++iter)
		t.append(boost::python::make_tuple(iter->first, iter->second));
	return t;
}         

/**
 * Helper method for getting dict made of all elements in collection
 * @returns boost::python::dict made of all key-value pairs
 */
template<typename Key, typename V>
boost::python::dict MapWrapper<Key,V>::getPyDict(const Map& x) {
    return boost::python::dict(items(x));
}

/**
 * Helper method for printing all elements of collection in Python style
 */
template<typename Key, typename V>
void MapWrapper<Key,V>::print(const Map& x) {
    int size = x.size();
    if(size == 0)
    {
        std::cout << "{}" << std::endl;
        return;
    }
    typename std::map<Key, V>::const_iterator it = x.begin();
	std::cout << "{";
	for(int i = 0; i < x.size() - 1; i++)
	{
        std::cout << it->first << ": " << it->second << ", ";
        ++it;
    }
	std::cout << it->first << ": " << it->second << "}" << std::endl;
}

/**
 * Method for actual container wrapping into Python-recognizable names and methods
 */
template<typename Key, typename V>
void MapWrapper<Key,V>::wrap(const std::string& python_name) {
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

