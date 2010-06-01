# Author: Aleksy Barcz
#
from libStlContainers import *

print 'Now running tests from Python_test_py_list_set_conversions.py..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1
    
def list_conversion_int():
    global tests
    result_list = [1, 2321, 124523]
    source_list = [1, 'c', 2321, 'text', 0.56, 124523, 2321]
    equals(py_list_to_set_int(source_list).get_list(), result_list)
    tests += 1
    
def list_conversion_double():
    global tests
    result_list = [0.56, 1.0, 1.54, 124.587, 2321.0, 124523.0]
    source_list = [1, 'c', 1.54, 2321, 'text', 0.56, 124523, 124.587, 1.54]
    equals(py_list_to_set_double(source_list).get_list(), result_list)
    tests += 1
    
def list_conversion_string():
    global tests
    result_list = ['c', 'text']
    source_list = [1, 'c', 1.54, 2321, 'text', 0.56, 124523, 124.587, 'c']
    equals(py_list_to_set_string(source_list).get_list(), result_list)
    tests += 1

list_conversion_int()
list_conversion_double()
list_conversion_string()

print str(tests) + " tests run."
print str(errors) + " errors found."
