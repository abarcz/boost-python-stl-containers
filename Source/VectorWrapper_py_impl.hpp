using namespace StlContainersWrappers;

template<typename V>
const V VectorWrapper<V>::get(Vec const& x, int i) {
    if(i < 0) 
        i += x.size();
    if(i >= 0 && i < (int)x.size()) 
        return x[i];
}

template<typename V>
void VectorWrapper<V>::set(Vec& x, int i, V const& v) {
    if(i < 0) 
        i += x.size();
    if(i >= 0 && i < (int)x.size())
        x[i] = v;
}

template<typename V>
void VectorWrapper<V>::del(Vec& x, int i) {
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
void VectorWrapper<V>::add(Vec& x, V const& v) {
    x.push_back(v);
}                                                                         

template<typename V>
bool VectorWrapper<V>::in(Vec const& x, V const& v) {
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
int VectorWrapper<V>::index(Vec const& x, V const& v ) {
 	int i = 0;
	typename Vec::const_iterator iter = x.begin();
	for(; iter != x.end(); ++iter, ++i)
		if(*iter == v) return i;
	return -1;
}

template<typename V>
int VectorWrapper<V>::count(Vec const& x, V const& v ) {
 	int i = 0;
	typename Vec::const_iterator iter = x.begin();
	for(; iter != x.end(); ++iter)
		if(*iter == v) ++i;
	return i;
}

template<typename V>
void VectorWrapper<V>::sort(Vec& x) {
 	std::sort(x.begin(), x.end());
}

template<typename V>
void VectorWrapper<V>::reverse(Vec& x) {
 	std::reverse(x.begin(), x.end());
}

template<typename V>
boost::python::list VectorWrapper<V>::getPyList(Vec& x) {
    boost::python::list pyList;
    for(typename Vec::iterator it = x.begin(); it != x.end(); ++it)
        pyList.append(*it);
    return pyList;
}

template<typename V>
void VectorWrapper<V>::print(Vec& x) {
    if(x.size() == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
	for(int i = 0; i < x.size() - 1; i++)
		std::cout << x[i] << ", ";
	std::cout << x[x.size() - 1] << "]" << std::endl;
}

template<typename V>
void VectorWrapper<V>::wrap(std::string const& python_name) {
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
