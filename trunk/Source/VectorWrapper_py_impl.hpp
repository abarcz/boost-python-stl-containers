using namespace StlContainersWrappers;

/**
 * Helper method for getting element by its index
 * @returns value of element under given index
 */
template<typename V>
const V VectorWrapper<V>::get(const Vec& x, int i) {
    if(i < 0) 
        i += (int)x.size();
    if(i >= 0 && i < (int)x.size()) 
        return x[i];
}

/**
 * Helper method for setting value of index-specified element
 */
template<typename V>
void VectorWrapper<V>::set(Vec& x, int i, const V& v) {
    if(i < 0) 
        i += (int)x.size();
    if(i >= 0 && i < (int)x.size())
        x[i] = v;
}

/**
 * Helper method for deleting element specified by given index
 */
template<typename V>
void VectorWrapper<V>::del(Vec& x, int i) {
    if(i < 0) 
        i += (int)x.size();
    if(i >= 0 && i < (int)x.size()) {
        typename Vec::iterator iter;
        iter = x.begin();
        for(int j = 0; j < i; ++j, ++iter);
        x.erase(iter);
    }
}

/**
 * Helper method for adding new element to collection
 */
template<typename V>
void VectorWrapper<V>::add(Vec& x, const V& v) {
    x.push_back(v);
}                                                                         

/**
 * Helper method for checking if specified element exists in collecion
 * @returns true if element exists, false otherwise
 */
template<typename V>
bool VectorWrapper<V>::in(const Vec& x, const V& v) {
    typename Vec::const_iterator iter;
    iter = x.begin();

	for(; iter != x.end(); ++iter)
		if(*iter == v)
			return true;
	return false;
}

/**
 * Helper method for finding element's index
 * @returns index associated with given element
 */
template<typename V>
int VectorWrapper<V>::index(const Vec& x, const V& v ) {
 	int i = 0;
	typename Vec::const_iterator iter = x.begin();
	for(; iter != x.end(); ++iter, ++i)
		if(*iter == v) return i;
	return -1;
}

/**
 * Helper method for counting number of identical elements
 * @returns number of elements matching given value
 */
template<typename V>
int VectorWrapper<V>::count(const Vec& x, const V& v ) {
 	int i = 0;
	typename Vec::const_iterator iter = x.begin();
	for(; iter != x.end(); ++iter)
		if(*iter == v) ++i;
	return i;
}

/**
 * Helper method for sorting collection lexicographically
 */
template<typename V>
void VectorWrapper<V>::sort(Vec& x) {
 	std::sort(x.begin(), x.end());
}

/**
 * Helper method for reversing elements order in collection
 */
template<typename V>
void VectorWrapper<V>::reverse(Vec& x) {
 	std::reverse(x.begin(), x.end());
}

/**
 * Helper method for getting list of all elements 
 * @returns boost::python::list of elements existing in collection
 */
template<typename V>
boost::python::list VectorWrapper<V>::getPyList(const Vec& x) {
    boost::python::list pyList;
    for(typename Vec::const_iterator it = x.begin(); it != x.end(); ++it)
        pyList.append(*it);
    return pyList;
}

/**
 * Helper method for printing all elements in collection in Python style 
 */
template<typename V>
void VectorWrapper<V>::print(const Vec& x) {
    if(x.size() == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
	for(int i = 0; i < (int)x.size() - 1; i++)
		std::cout << x[i] << ", ";
	std::cout << x[x.size() - 1] << "]" << std::endl;
}

/**
 * Method for actual container wrapping into Python-recognizable names and methods
 */
template<typename V>
void VectorWrapper<V>::wrap(const std::string& python_name) {
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
	  .def("reverse", &reverse)
      .def("get_list", &getPyList)
    ;
    #ifdef STL_TO_PYTHON_CONTAINERS_COMPARABLE
        wrapped.def("__contains__", &in);
        wrapped.def("index", &index);
        wrapped.def("count", &count);
        wrapped.def("sort", &sort);
    #endif
    #ifdef STL_TO_PYTHON_CONTAINERS_PRINTABLE
        wrapped.def("print_", &print);
    #endif
    //return wrapped;
}
