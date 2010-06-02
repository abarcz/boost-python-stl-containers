# Author: Aleksy Barcz
#
from libStlContainers import *

print 'Now running tests from Python_test_py_list_vector_conversions.py..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error"
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1
    
def list_conversion_int():
    global tests
    result_list = [1, 2321, 124523]
    source_list = [1, 'c', 2321, 'text', 0.56, 124523]
    equals(py_list_to_vector_int(source_list).get_list(), result_list)
    tests += 1
    
def list_conversion_double():
    global tests
    result_list = [1, 1.54, 2321, 0.56, 124523, 124.587]
    source_list = [1, 'c', 1.54, 2321, 'text', 0.56, 124523, 124.587]
    equals(py_list_to_vector_double(source_list).get_list(), result_list)
    tests += 1
    
def list_conversion_string():
    global tests
    result_list = ['c', 'text']
    source_list = [1, 'c', 1.54, 2321, 'text', 0.56, 124523, 124.587]
    equals(py_list_to_vector_string(source_list).get_list(), result_list)
    tests += 1

list_conversion_int()
list_conversion_double()
list_conversion_string()

print str(tests) + " tests run."
print str(errors) + " errors found."
