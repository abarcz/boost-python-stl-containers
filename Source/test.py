print 'Now running tests from test.py..'

import stl_containers

mapa = stl_containers.map_int_string()
wektor = stl_containers.vector_int()
set1 = stl_containers.set_int()

mapa[0] = "a"
mapa[1] = "b"
mapa[6] = "c"

if mapa[6] != "c" :
    print "Error"

wektor.append(0)
wektor.append(0)
wektor.append(1)
wektor.append(2)
wektor.append(3)
wektor.__len__()

if wektor.__len__() != 5 :
	print "Error"

wektor.__delitem__(2)

if wektor.__len__() != 4 :
	print "Error"

wektor[2] = 8

if wektor[2] != 8 :
	print "Error"

wektor.clear()

if wektor.__len__() != 0 :
	print "Error"

set1.append(0)
set1.append(0)
set1.append(0)
set1.append(1)
set1.__len__()

if set1.__len__() != 2 :
	print "Error"

set1.clear()

if set1.__len__() != 0 :
	print "Error"

print 'Tests from test.py finished'

