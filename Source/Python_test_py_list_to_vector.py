# Author: Aleksy Barcz
#
from StlContainers import *
import TestModule

print 'Now running tests from Python_test_pyListToVectorInt.py..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1
        
def elem_sum(list):
    sum = 0
    for e in list:
        sum += e
    return sum    
        
def list_conversion_int():
    global tests
    result_list = [1, 2321, 124523]
    source_list = [1, 'c', 2321, "text", 0.56, 124523]
    test_sum = TestModule.get_vector_sum_int(py_list_to_vector_int(source_list))
    correct_sum = elem_sum(result_list)
    equals(test_sum, correct_sum)
    tests += 1
    
def list_conversion_double():
    global tests
    result_list = [1, 1.54, 2321, 0.56, 124523, 124.587]
    source_list = [1, 'c', 1.54, 2321, "text", 0.56, 124523, 124.587]
    test_sum = TestModule.get_vector_sum_double(py_list_to_vector_double(source_list))
    correct_sum = elem_sum(result_list)
    equals(test_sum, correct_sum)
    tests += 1

list_conversion_int()
list_conversion_double()

print str(tests) + " tests run."
print str(errors) + " errors found."
