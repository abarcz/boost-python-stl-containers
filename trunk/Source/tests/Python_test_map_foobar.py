# Author: Michal Andrzejewski, Aleksy Barcz
#
from libFoobar import *

print 'Now running unit tests from Python_test_map_foobar.py for types <int, foobar>..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error"
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1


def container_creation_successful_int():
	global tests
	map_ = map_int_foobar()
	equals(map_.__len__(), 0)
	tests += 1

def container_indexing_correct_int():
	global tests
	map_ = map_int_foobar()
	map_[0] = Foobar(1)
	map_[3] = Foobar(1000)
	equals(map_[0].getId(), 1)
	equals(map_[3].getId(), 1000)
	tests += 1

def container_deletion_successful_int():
	global tests
	map_ = map_int_foobar()
	map_[1] = Foobar(2)
	map_.__delitem__(1)
	equals(map_.__len__(), 0)
	tests += 1
    
def container_clear_successful_int():
	global tests
	map_ = map_int_foobar()
	map_[1] = Foobar(54)
	map_[10] = Foobar(65)
	map_.clear()
	equals(map_.__len__(), 0)
	tests += 1

def container_contains_correct_int():
	global tests
	map_ = map_int_foobar()
	map_[1] = Foobar(2)
	equals(map_.__contains__(1), True)
	tests += 1

def container_stress_append_and_delete_correct_int():
	global tests
	map_ = map_int_foobar()
	i = 0
	while i < 10000:
		map_[i] = Foobar(i)
		i += 1
	
	equals(map_.__len__(), 10000)

	i = 10000
	while i >= 0:
		map_.__delitem__(i)
		i -= 1
	
	equals(map_.__len__(), 0)
	tests += 1

container_creation_successful_int()
container_indexing_correct_int()
container_deletion_successful_int()
container_clear_successful_int()
container_contains_correct_int()
container_stress_append_and_delete_correct_int()

print str(tests) + " tests run."
print str(errors) + " errors found."

