# Author: Michal Andrzejewski
#
import libStlContainers

print 'Now running unit tests from Python_test_sets.py for types int, double, string..'

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
	set_int = libStlContainers.set_int()
	equals(set_int.__len__(), 0)
	tests += 1

def container_creation_successful_double():
	global tests
	set_double = libStlContainers.set_double()
	equals(set_double.__len__(), 0)
	tests += 1

def container_creation_successful_string():
	global tests
	set_string = libStlContainers.set_string()
	equals(set_string.__len__(), 0)
	tests += 1

def container_append_successful_int():
	global tests
	set_int = libStlContainers.set_int()
	set_int.append(1)
	equals(set_int.__len__(), 1)
	tests += 1

def container_append_successful_double():
	global tests
	set_double = libStlContainers.set_double()
	set_double.append(1.1)
	equals(set_double.__len__(), 1)
	tests += 1

def container_append_successful_string():
	global tests
	set_string = libStlContainers.set_string()
	set_string.append("A")
	equals(set_string.__len__(), 1)
	tests += 1

def container_deletion_successful_int():
	global tests
	set_int = libStlContainers.set_int()
	set_int.append(1)
	set_int.__delitem__(1)
	equals(set_int.__len__(), 0)
	tests += 1

def container_deletion_successful_double():
	global tests
	set_double = libStlContainers.set_double()
	set_double.append(1.1)
	set_double.__delitem__(1.1)
	equals(set_double.__len__(), 0)
	tests += 1

def container_deletion_successful_string():
	global tests
	set_string = libStlContainers.set_string()
	set_string.append("A")
	set_string.__delitem__("A")
	equals(set_string.__len__(), 0)
	tests += 1

def container_clear_successful_int():
	global tests
	set_int = libStlContainers.set_int()
	set_int.append(1)
	set_int.append(2)
	set_int.append(3)
	set_int.clear()
	equals(set_int.__len__(), 0)
	tests += 1

def container_clear_successful_double():
	global tests
	set_double = libStlContainers.set_double()
	set_double.append(1.1)
	set_double.append(2.2)
	set_double.append(3.3)
	set_double.clear()
	equals(set_double.__len__(), 0)
	tests += 1

def container_clear_successful_string():
	global tests
	set_string = libStlContainers.set_string()
	set_string.append("A")
	set_string.append("B")
	set_string.append("C")
	set_string.clear()
	equals(set_string.__len__(), 0)
	tests += 1

def container_contains_correct_int():
	global tests
	set_int = libStlContainers.set_int()
	set_int.append(1)
	equals(set_int.__contains__(1), True)
	tests += 1

def container_contains_correct_double():
	global tests
	set_double = libStlContainers.set_double()
	set_double.append(1.1)
	equals(set_double.__contains__(1.1), True)
	tests += 1

def container_contains_correct_string():
	global tests
	set_string = libStlContainers.set_string()
	set_string.append("A")
	equals(set_string.__contains__("A"), True)
	tests += 1


def container_stress_append_and_delete_correct_int():
	global tests
	set_int = libStlContainers.set_int()
	i = 0
	while i < 10000:
		set_int.append(i)
		i += 1
	
	equals(set_int.__len__(), 10000)

	i = 10000
	while i >= 0:
		set_int.__delitem__(i)
		i -= 1
	
	equals(set_int.__len__(), 0)
	tests += 1

def container_stress_append_and_delete_correct_double():
	global tests
	set_double = libStlContainers.set_double()
	i = 0
	while i < 10000:
		set_double.append(i + 1.1)
		i += 1
	
	equals(set_double.__len__(), 10000)

	i = 10000
	while i >= 0:
		set_double.__delitem__(i + 1.1)
		i -= 1
	
	equals(set_double.__len__(), 0)
	tests += 1

def container_stress_append_and_delete_correct_string():
	global tests
	set_string = libStlContainers.set_string()
	i = 0
	while i < 10000:
		set_string.append("A")
		i += 1
	
	equals(set_string.__len__(), 1)

	i = 10000
	while i > 0:
		set_string.__delitem__("A")
		i -= 1
	
	equals(set_string.__len__(), 0)
	tests += 1

container_creation_successful_int()
container_creation_successful_double()
container_creation_successful_string()
container_append_successful_int()
container_append_successful_double()
container_append_successful_string()
container_deletion_successful_int()
container_deletion_successful_double()
container_deletion_successful_string()
container_clear_successful_int()
container_clear_successful_double()
container_clear_successful_string()
container_contains_correct_int()
container_contains_correct_double()
container_contains_correct_string()
container_stress_append_and_delete_correct_int()
container_stress_append_and_delete_correct_double()
container_stress_append_and_delete_correct_string()

print str(tests) + " tests run."
print str(errors) + " errors found."

