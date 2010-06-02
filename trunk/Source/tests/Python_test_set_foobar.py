# Author: Michal Andrzejewski, Aleksy
#
from libFoobar import *

print 'Now running unit tests from Python_test_set_foobar.py'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1


def container_creation_successful_foobar():
	global tests
	set_fb = set_foobar()
	equals(set_fb.__len__(), 0)
	tests += 1

def container_append_successful_foobar():
	global tests
	set_fb = set_foobar()
	set_fb.append(Foobar(1))
	equals(set_fb.__len__(), 1)
	tests += 1

def container_deletion_successful_foobar():
	global tests
	set_fb = set_foobar()
	set_fb.append(Foobar(1))
	set_fb.__delitem__(Foobar(1))
	equals(set_fb.__len__(), 0)
	tests += 1

def container_clear_successful_foobar():
	global tests
	set_fb = set_foobar()
	set_fb.append(Foobar(1))
	set_fb.append(Foobar(2))
	set_fb.append(Foobar(3))
	set_fb.clear()
	equals(set_fb.__len__(), 0)
	tests += 1

def container_contains_correct_foobar():
	global tests
	set_fb = set_foobar()
	set_fb.append(Foobar(1))
	equals(set_fb.__contains__(Foobar(1)), True)
	tests += 1

def container_stress_append_and_delete_correct_foobar():
	global tests
	set_fb = set_foobar()
	i = 0
	while i < 10000:
		set_fb.append(Foobar(i))
		i += 1
	
	equals(set_fb.__len__(), 10000)

	i = 10000
	while i >= 0:
		set_fb.__delitem__(Foobar(i))
		i -= 1
	
	equals(set_fb.__len__(), 0)
	tests += 1

container_creation_successful_foobar()
container_append_successful_foobar()
container_deletion_successful_foobar()
container_clear_successful_foobar()
container_contains_correct_foobar()
container_stress_append_and_delete_correct_foobar()

print str(tests) + " tests run."
print str(errors) + " errors found."

