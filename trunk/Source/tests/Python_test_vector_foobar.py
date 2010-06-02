# Author: Michal Andrzejewski, Aleksy Barcz
#
from libFoobar import *

print 'Now running unit tests from Python_test_vector_foobar.py..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error"
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1


def container_creation_successful():
	global tests
	vector = vector_foobar()
	equals(vector.__len__(), 0)
	tests += 1

def container_append_successful():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	equals(vector.__len__(), 1)
	tests += 1

def container_deletion_successful():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	vector.__delitem__(0)
	equals(vector.__len__(), 0)
	tests += 1

def container_index_operator_works():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	equals(vector[0], Foobar(1))
	tests += 1

def container_deletion2_successful():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	vector.append(Foobar(2))
	vector.append(Foobar(3))
	vector.__delitem__(1)
	equals(vector[0], Foobar(1))
	equals(vector[1], Foobar(3))
	tests += 1

def container_clear_successful():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	vector.append(Foobar(2))
	vector.append(Foobar(3))
	vector.clear()
	equals(vector.__len__(), 0)
	tests += 1

def container_contains_correct():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	equals(vector.__contains__(Foobar(1)), 1)
	tests += 1

def container_indexing_correct():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	equals(vector.index(Foobar(1)), 0)
	tests += 1

def container_count_correct():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	equals(vector.count(Foobar(1)), 1)
	tests += 1

def container_reverse_correct():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(1))
	vector.append(Foobar(2))
	vector.append(Foobar(3))
	vector.reverse()
	equals(vector[0], Foobar(3))
	equals(vector[1], Foobar(2))
	equals(vector[2], Foobar(1))
	tests += 1

def container_sort_correct():
	global tests
	vector = vector_foobar()
	vector.append(Foobar(3))
	vector.append(Foobar(1))
	vector.append(Foobar(2))
	vector.sort()
	equals(vector[0], Foobar(1))
	equals(vector[1], Foobar(2))
	equals(vector[2], Foobar(3))
	tests += 1

def container_stress_append_and_delete_correct():
	global tests
	vector = vector_foobar()
	i = 0
	while i < 10000:
		vector.append(Foobar(i))
		i += 1
	
	equals(vector.__len__(), 10000)

	i = 5000
	while i > 0:
		vector.__delitem__(i)
		i -= 1
	
	equals(vector.__len__(), 5000)

	vector.clear()
	
	equals(vector.__len__(), 0)
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

