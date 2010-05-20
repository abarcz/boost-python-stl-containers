# Author: Michal Andrzejewski
#
import StlContainers

print 'Now running tests from Python_test_vectors.py for type int..'

vector_int = StlContainers.vector_int()
passed = 1

if vector_int.__len__() != 0:
	print "Error: newly created container isn't empty\n"
	passed = 0

vector_int.append(1);

if vector_int.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_int.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_int.__delitem__(0)

if vector_int.__len__() != 0:
	print "Error: container contains element(s) while it shouldn't\n"
	passed = 0

vector_int.append(1);

if vector_int.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_int.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_int.append(2);
vector_int.append(3);

if vector_int.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_int.__len__() != 3:
	print "Error: container size is incorrect\n"
	passed = 0

if vector_int[0] != 1:
	print "Error: different element was expected\n"
	passed = 0

if vector_int[1] != 2:
	print "Error: different element was expected\n"
	passed = 0

if vector_int[2] != 3:
	print "Error: different element was expected\n"
	passed = 0

vector_int[2] = -1                                               

if vector_int.__contains__(-1) == False:
	print "Error: element is not present"
	passed = 0

if vector_int[2] != -1:
	print "Error: different element was expected\n"
	passed = 0

vector_int.clear()

if vector_int.__len__() != 0:
	print "Error: after clear() container isn't empty\n"
	passed = 0

if passed:
	print "All tests for vector (int) passed!"
else:
	print "Error found!"

#
# Doubles
#

print 'Now running tests from Python_test_vectors.py for type double..'

vector_double = StlContainers.vector_double()
passed = 1

if vector_double.__len__() != 0:
	print "Error: newly created container isn't empty\n"
	passed = 0

vector_double.append(1.5);

if vector_double.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_double.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_double.__delitem__(0)

if vector_double.__len__() != 0:
	print "Error: container contains element(s) while it shouldn't\n"
	passed = 0

vector_double.append(1.9);

if vector_double.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_double.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_double.append(2.2);
vector_double.append(3.3);

if vector_double.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_double.__len__() != 3:
	print "Error: container size is incorrect\n"
	passed = 0

if vector_double[0] != 1.9:
	print "Error: different element was expected\n"
	passed = 0

if vector_double[1] != 2.2:
	print "Error: different element was expected\n"
	passed = 0

if vector_double[2] != 3.3:
	print "Error: different element was expected\n"
	passed = 0

vector_double[2] = -1.7                                               

if vector_double.__contains__(-1.7) == False:
	print "Error: element is not present"
	passed = 0

if vector_double[2] != -1.7:
	print "Error: different element was expected\n"
	passed = 0

vector_double.clear()

if vector_double.__len__() != 0:
	print "Error: after clear() container isn't empty\n"
	passed = 0

if passed:
	print "All tests for vector (double) passed!"
else:
	print "Error found!"

#
# Strings
#

print 'Now running tests from Python_test_vectors.py for type string..'

vector_string = StlContainers.vector_string()
passed = 1

if vector_string.__len__() != 0:
	print "Error: newly created container isn't empty\n"
	passed = 0

vector_string.append("AAA");

if vector_string.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_string.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_string.__delitem__(0)

if vector_string.__len__() != 0:
	print "Error: container contains element(s) while it shouldn't\n"
	passed = 0

vector_string.append("AAB");

if vector_string.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_string.__len__() != 1:
	print "Error: container size is incorrect\n"
	passed = 0

vector_string.append("BBB");
vector_string.append("CCC");

if vector_string.__len__() == 0:
	print "Error: container is empty while it shouldn't be\n"
	passed = 0

if vector_string.__len__() != 3:
	print "Error: container size is incorrect\n"
	passed = 0

if vector_string[0] != "AAB":
	print "Error: different element was expected\n"
	passed = 0

if vector_string[1] != "BBB":
	print "Error: different element was expected\n"
	passed = 0

if vector_string[2] != "CCC":
	print "Error: different element was expected\n"
	passed = 0

vector_string[2] = "UPS"                                               

if vector_string.__contains__("UPS") == False:
	print "Error: element is not present"
	passed = 0

if vector_string[2] != "UPS":
	print "Error: different element was expected\n"
	passed = 0

vector_string.clear()

if vector_string.__len__() != 0:
	print "Error: after clear() container isn't empty\n"
	passed = 0

if passed:
	print "All tests for vector (string) passed!"
else:
	print "Error found!"
