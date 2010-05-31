# Author: Michal Andrzejewski
#
import StlContainers

print 'Now running unit tests from Python_test_vectors.py for types int, double, string..'

errors = 0
tests = 0

def equals(a, b):
	global errors
	if(not (a == b)):
		print "Error in "
		print "Left operand value: " + str(a)
		print "Right operand value: " + str(b)
		errors += 1


def container_creation_successful_int():
	global tests
	vector_int = StlContainers.vector_int()
	equals(vector_int.__len__(), 0)
	tests += 1

def container_creation_successful_double():
	global tests
	vector_double = StlContainers.vector_double()
	equals(vector_double.__len__(), 0)
	tests += 1

def container_creation_successful_string():
	global tests
	vector_string = StlContainers.vector_string()
	equals(vector_string.__len__(), 0)
	tests += 1

def container_append_successful_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.__len__(), 1)
	tests += 1

def container_append_successful_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.93)
	equals(vector_double.__len__(), 1)
	tests += 1

def container_append_successful_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("YAWN")
	equals(vector_string.__len__(), 1)
	tests += 1

def container_deletion_successful_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.__delitem__(0)
	equals(vector_int.__len__(), 0)
	tests += 1

def container_deletion_successful_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.93)
	vector_double.__delitem__(0)
	equals(vector_double.__len__(), 0)
	tests += 1

def container_deletion_successful_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("YAWN")
	vector_string.__delitem__(0)
	equals(vector_string.__len__(), 0)
	tests += 1

def container_index_operator_works_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int[0], 1)
	tests += 1

def container_index_operator_works_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.93)
	equals(vector_double[0], 1.93)
	tests += 1

def container_index_operator_works_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("YAWN")
	equals(vector_string[0], "YAWN")
	tests += 1

def container_deletion2_successful_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.append(2)
	vector_int.append(3)
	vector_int.__delitem__(1)
	equals(vector_int[0], 1)
	equals(vector_int[1], 3)
	tests += 1

def container_deletion2_successful_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	vector_double.append(2.2)
	vector_double.append(3.3)
	vector_double.__delitem__(1)
	equals(vector_double[0], 1.1)
	equals(vector_double[1], 3.3)
	tests += 1

def container_deletion2_successful_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	vector_string.append("B")
	vector_string.append("C")
	vector_string.__delitem__(1)
	equals(vector_string[0], "A")
	equals(vector_string[1], "C")
	tests += 1

def container_clear_successful_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	vector_int.append(2)
	vector_int.append(3)
	vector_int.clear()
	equals(vector_int.__len__(), 0)
	tests += 1

def container_clear_successful_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	vector_double.append(2.2)
	vector_double.append(3.3)
	vector_double.clear()
	equals(vector_double.__len__(), 0)
	tests += 1

def container_clear_successful_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	vector_string.append("B")
	vector_string.append("C")
	vector_string.clear()
	equals(vector_string.__len__(), 0)
	tests += 1

def container_contains_correct_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.__contains__(1), True)
	tests += 1

def container_contains_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	equals(vector_double.__contains__(1.1), True)
	tests += 1

def container_contains_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	equals(vector_string.__contains__("A"), True)
	tests += 1

def container_indexing_correct_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.index(1), 0)
	tests += 1

def container_indexing_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	equals(vector_double.index(1.1), 0)
	tests += 1

def container_indexing_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	equals(vector_string.index("A"), 0)
	tests += 1

def container_count_correct_int():
	global tests
	vector_int = StlContainers.vector_int()
	vector_int.append(1)
	equals(vector_int.count(1), 1)
	tests += 1

def container_count_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	equals(vector_double.count(1.1), 1)
	tests += 1

def container_count_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	equals(vector_string.count("A"), 1)
	tests += 1

def container_reverse_correct_int():
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

def container_reverse_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(1.1)
	vector_double.append(2.2)
	vector_double.append(3.3)
	vector_double.reverse()
	equals(vector_double[0], 3.3)
	equals(vector_double[1], 2.2)
	equals(vector_double[2], 1.1)
	tests += 1

def container_reverse_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("A")
	vector_string.append("B")
	vector_string.append("C")
	vector_string.reverse()
	equals(vector_string[0], "C")
	equals(vector_string[1], "B")
	equals(vector_string[2], "A")
	tests += 1

def container_sort_correct_int():
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

def container_sort_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	vector_double.append(3.3)
	vector_double.append(1.1)
	vector_double.append(2.2)
	vector_double.sort()
	equals(vector_double[0], 1.1)
	equals(vector_double[1], 2.2)
	equals(vector_double[2], 3.3)
	tests += 1

def container_sort_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	vector_string.append("C")
	vector_string.append("A")
	vector_string.append("B")
	vector_string.sort()
	equals(vector_string[0], "A")
	equals(vector_string[1], "B")
	equals(vector_string[2], "C")
	tests += 1

def container_stress_append_and_delete_correct_int():
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

def container_stress_append_and_delete_correct_double():
	global tests
	vector_double = StlContainers.vector_double()
	i = 0
	while i < 10000:
		vector_double.append(i + 1.1)
		i += 1
	
	equals(vector_double.__len__(), 10000)

	i = 5000
	while i > 0:
		vector_double.__delitem__(i)
		i -= 1
	
	equals(vector_double.__len__(), 5000)

	vector_double.clear()
	
	equals(vector_double.__len__(), 0)
	tests += 1

def container_stress_append_and_delete_correct_string():
	global tests
	vector_string = StlContainers.vector_string()
	i = 0
	while i < 10000:
		vector_string.append("A")
		i += 1
	
	equals(vector_string.__len__(), 10000)

	i = 5000
	while i > 0:
		vector_string.__delitem__(i)
		i -= 1
	
	equals(vector_string.__len__(), 5000)

	vector_string.clear()
	
	equals(vector_string.__len__(), 0)
	tests += 1

def container_get_list_correct_int():
	global tests
	vector = StlContainers.vector_int()
	vector.append(1)
	a = [1]
	equals(vector.get_list(), a)
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
container_index_operator_works_int()
container_index_operator_works_double()
container_index_operator_works_string()
container_deletion2_successful_int()
container_deletion2_successful_double()
container_deletion2_successful_string()
container_clear_successful_int()
container_clear_successful_double()
container_clear_successful_string()
container_contains_correct_int()
container_contains_correct_double()
container_contains_correct_string()
container_indexing_correct_int()
container_indexing_correct_double()
container_indexing_correct_string()
container_count_correct_int()
container_count_correct_double()
container_count_correct_string()
container_reverse_correct_int()
container_reverse_correct_double()
container_reverse_correct_string()
container_sort_correct_int()
container_sort_correct_double()
container_sort_correct_string()
container_stress_append_and_delete_correct_int()
container_stress_append_and_delete_correct_double()
container_stress_append_and_delete_correct_string()
container_get_list_correct_int()

print str(tests) + " tests run."
print str(errors) + " errors found."

