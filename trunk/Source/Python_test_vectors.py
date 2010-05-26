# Author: Michal Andrzejewski
#
import StlContainers

print 'Now running unit tests from Python_test_vectors.py for type int..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1


def container_creation_successful():
	global tests
	vector_int = StlContainers.vector_int()
	equals(vector_int.__len__(), 0)
	tests += 1

def container_append_successful():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.__len__(), 1)
	tests += 1

def container_deletion_successful():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.__delitem__(0)
	equals(vector_int.__len__(), 0)
	tests += 1

def container_index_operator_works():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int[0], 1)
	tests += 1

def container_deletion2_successful():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.append(2)
	vector_int.append(3)
	vector_int.__delitem__(1)
	equals(vector_int[0], 1)
	equals(vector_int[1], 3)
	tests += 1

def container_clear_successful():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.append(2)
	vector_int.append(3)
	vector_int.clear()
	equals(vector_int.__len__(), 0)
	tests += 1

def container_contains_correct():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.__contains__(1), 1)
	tests += 1

def container_indexing_correct():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.index(1), 0)
	tests += 1

def container_count_correct():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.count(1), 1)
	tests += 1

def container_reverse_correct():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.append(2)
	vector_int.append(3)
	vector_int.reverse()
	equals(vector_int[0], 3)
	equals(vector_int[1], 2)
	equals(vector_int[2], 1)
	tests += 1

def container_sort_correct():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(3)
	vector_int.append(1)
	vector_int.append(2)
	vector_int.sort()
	equals(vector_int[0], 1)
	equals(vector_int[1], 2)
	equals(vector_int[2], 3)
	tests += 1

def container_stress_append_and_delete_correct():
	global tests
	vector_int = StlContainers.vector_int()
	i = 0
	while i < 10000:
		vector_int.append(i)
		i += 1
	
	equals(vector_int.__len__(), 10000)

	i = 5000
	while i > 0:
		vector_int.__delitem__(i)
		i -= 1
	
	equals(vector_int.__len__(), 5000)

	vector_int.clear()
	
	equals(vector_int.__len__(), 0)
	tests += 1


container_creation_successful()
container_append_successful()
container_deletion_successful()
container_index_operator_works()
container_deletion2_successful()
container_clear_successful()
container_contains_correct()
container_indexing_correct()
container_count_correct()
container_reverse_correct()
container_sort_correct()
container_stress_append_and_delete_correct()

print str(tests) + " tests run."
print str(errors) + " errors found."

