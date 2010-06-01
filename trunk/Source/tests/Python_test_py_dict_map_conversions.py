# Author: Aleksy Barcz
#
from libStlContainers import *

print 'Now running tests from Python_test_py_dict_map_conversions.py..'

tests = 0
errors = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1

d = {'try' : 'tyu', 67 : 'ddd', 2.7 : 5.65, 33 : 0.897, 54 : 'dasda'}

equals(py_dict_to_map_int_string(d).get_dict(), {54: 'dasda', 67: 'ddd'})
tests += 1

equals(py_dict_to_map_string_string(d).get_dict(), {'try': 'tyu'})
tests += 1

equals(py_dict_to_map_int_double(d).get_dict(), {33: 0.897})
tests += 1

print str(tests) + " tests run."
print str(errors) + " errors found."
