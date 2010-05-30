# Author: Michal Andrzejewski
#
import StlContainers

print 'Now running unit tests from Python_test_maps.py for types <int, string> and <string, double>..'

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
	map_ = StlContainers.map_int_string()
	equals(map_.__len__(), 0)
	tests += 1

def container_creation_successful_string():
	global tests
	map_ = StlContainers.map_string_double()
	equals(map_.__len__(), 0)
	tests += 1

def container_indexing_correct_int():
	global tests
	map_ = StlContainers.map_int_string()
	map_[0] = "ABC"
	map_[3] = "CDE"
	equals(map_[0], "ABC")
	equals(map_[3], "CDE")
	tests += 1

def container_indexing_correct_string():
	global tests
	map_ = StlContainers.map_string_double()
	map_["A"] = 1.1
	map_["C"] = 3.3
	equals(map_["A"], 1.1)
	equals(map_["C"], 3.3)
	tests += 1

def container_deletion_successful_int():
	global tests
	map_ = StlContainers.map_int_string()
	map_[1] = "A"
	map_.__delitem__(1)
	equals(map_.__len__(), 0)
	tests += 1

def container_deletion_successful_string():
	global tests
	map_ = StlContainers.map_string_double()
	map_["A"] = 1.1
	map_.__delitem__("A")
	equals(map_.__len__(), 0)
	tests += 1

def container_clear_successful_int():
	global tests
	map_ = StlContainers.map_int_string()
	map_[1] = "A"
	map_[10] = "B"
	map_.clear()
	equals(map_.__len__(), 0)
	tests += 1

def container_clear_successful_string():
	global tests
	map_ = StlContainers.map_string_double()
	map_["A"] = 1.1
	map_["B"] = 2.2
	map_.clear()
	equals(map_.__len__(), 0)
	tests += 1

def container_contains_correct_int():
	global tests
	map_ = StlContainers.map_int_string()
	map_[1] = "A"
	equals(map_.__contains__(1), True)
	tests += 1

def container_contains_correct_string():
	global tests
	map_ = StlContainers.map_string_double()
	map_["A"] = 1.1
	equals(map_.__contains__("A"), True)
	tests += 1

def container_stress_append_and_delete_correct_int():
	global tests
	map_ = StlContainers.map_int_string()
	i = 0
	while i < 10000:
		map_[i] = "A"
		i += 1
	
	equals(map_.__len__(), 10000)

	i = 10000
	while i >= 0:
		map_.__delitem__(i)
		i -= 1
	
	equals(map_.__len__(), 0)
	tests += 1

container_creation_successful_int()
container_creation_successful_string()
container_append_successful_int()
container_append_successful_string()
container_deletion_successful_int()
container_deletion_successful_string()
container_clear_successful_int()
container_clear_successful_string()
container_contains_correct_int()
container_contains_correct_string()
container_stress_append_and_delete_correct_int()

print str(tests) + " tests run."
print str(errors) + " errors found."

