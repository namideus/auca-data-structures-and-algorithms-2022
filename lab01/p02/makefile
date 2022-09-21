main: main.o hello.o
	g++ -o main main.o hello.o
main.o: main.cpp hello.hpp
	g++ -c main.cpp
hello.o: hello.cpp hello.hpp
	g++ -c hello.cpp