# Author: Aleksy Barcz
#
from StlContainers import *
from TestModule import *

print 'Now running tests from Python_test_pyDictToMap.py..'

d = {'try' : 'tyu', 67 : 'ddd', 2.7 : 5.65, 33 : 0.897, 54 : 'dasda'}

print 'Source dict from Python: '
print d

print 'Resulting map<int, string> from Python: '
py_dict_to_map_int_string(d).print_()

print 'Resulting map<string, string> from Python: '
py_dict_to_map_string_string(d).print_()

print 'Resulting map<int, double> from Python: '
py_dict_to_map_int_double(d).print_()

print 'Finished running tests from Python_test_pyDictToMap.py'
print 
