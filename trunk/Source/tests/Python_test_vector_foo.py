# Author: Michal Andrzejewski, Aleksy Barcz
#
from libFoo import *

print 'Now running unit tests from Python_test_vector_foo.py...'

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
	vector = vector_foo()
	equals(vector.__len__(), 0)
	tests += 1

def container_append_successful():
	global tests
	vector = vector_foo()
	vector.append(Foo(1))
	equals(vector.__len__(), 1)
	tests += 1

def container_deletion_successful():
	global tests
	vector = vector_foo()
	vector.append(Foo(1))
	vector.__delitem__(0)
	equals(vector.__len__(), 0)
	tests += 1

def container_clear_successful():
	global tests
	vector = vector_foo()
	vector.append(Foo(1))
	vector.append(Foo(2))
	vector.append(Foo(3))
	vector.clear()
	equals(vector.__len__(), 0)
	tests += 1

def container_stress_append_and_delete_correct():
	global tests
	vector = vector_foo()
	i = 0
	while i < 10000:
		vector.append(Foo(i))
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
container_clear_successful()
container_stress_append_and_delete_correct()

print str(tests) + " tests run."
print str(errors) + " errors found."

