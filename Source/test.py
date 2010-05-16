print 'Hello World from test.py!'

import zpr

mapa = zpr.Map()
wektor = zpr.Vec()
set1 = zpr.Set()

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


