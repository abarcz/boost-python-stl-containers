all:
	g++ StlContainers.cpp -lboost_python -lpython2.6 -I /usr/include/python2.6 -o StlContainers.so -shared
test:
	g++ Embedded.cpp -lboost_python -lpython2.6 -I /usr/include/python2.6 -o Embedded_tests
	g++ External.cpp -lboost_python -lpython2.6 -I /usr/include/python2.6 -o External_tests
	g++ TestModule.cpp -lboost_python -lpython2.6 -I /usr/include/python2.6 -o TestModule.so -shared
	g++ TestModule2.cpp -lboost_python -lpython2.6 -I /usr/include/python2.6 -o TestModule2.so -shared
