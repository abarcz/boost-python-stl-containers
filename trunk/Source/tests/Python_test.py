# Autor: Michal Andrzejewski
#
#
#
print 'Now running tests from Python_test.py..'

import libStlContainers

map_int_string = libStlContainers.map_int_string()
vector_int = libStlContainers.vector_int()
set_int = libStlContainers.set_int()

vector_double = libStlContainers.vector_double()
vector_string = libStlContainers.vector_string()
set_double = libStlContainers.set_double()
set_string = libStlContainers.set_string()

map_int_string[0] = "a"
map_int_string[1] = "b"
map_int_string[6] = "c"

if map_int_string[6] != "c" :
    print "Error"

vector_int.append(0)
vector_int.append(0)
vector_int.append(1)
vector_int.append(2)
vector_int.append(3)

if vector_int.__len__() != 5 :
	print "Error"

vector_int.__delitem__(2)

if vector_int.__len__() != 4 :
	print "Error"

vector_int[2] = 8

if vector_int[2] != 8 :
	print "Error"

vector_int.clear()

if vector_int.__len__() != 0 :
	print "Error"

vector_string.append("A")
vector_string.append("B")
vector_string.append("C")
vector_string.append("D")
vector_string.append("D")

if vector_string.__len__() != 5 :
	print "Error"

vector_string.__delitem__(2)

if vector_string.__len__() != 4 :
	print "Error"

vector_string[2] = "Z"

if vector_string[2] != "Z" :
	print "Error"

vector_string.clear()

if vector_string.__len__() != 0 :
	print "Error"

vector_double.append(0.0)
vector_double.append(1.0)
vector_double.append(2.0)
vector_double.append(3.0)
vector_double.append(4.0)

if vector_double.__len__() != 5 :
	print "Error"

vector_double.__delitem__(2)

if vector_double.__len__() != 4 :
	print "Error"

vector_double.clear()

if vector_double.__len__() != 0 :
	print "Error"

set_int.append(0)
set_int.append(0)
set_int.append(0)
set_int.append(1)
set_int.__len__()

if set_int.__len__() != 2 :
	print "Error"

set_int.clear()

if set_int.__len__() != 0 :
	print "Error"

set_double.append(0.0)
set_double.append(0.0)
set_double.append(0.0)
set_double.append(1.5)
set_double.__len__()

if set_double.__len__() != 2 :
	print "Error"

set_double.clear()

if set_double.__len__() != 0 :
	print "Error"

set_string.append("A")
set_string.append("A")
set_string.append("A")
set_string.append("B")
set_string.__len__()

if set_string.__len__() != 2 :
	print "Error"

set_string.clear()

if set_string.__len__() != 0 :
	print "Error"

print 'Tests from Python_test.py finished'

