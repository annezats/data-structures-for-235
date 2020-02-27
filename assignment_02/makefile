CXXFLAGS=-g
FLAGS = -std=c++14

main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o $(FLAGS) 
ListTest.o: main.cpp List.h Node.h
List.o: List.cpp List.h Node.h
Node.o: Node.cpp Node.h

test: test.cpp main.o List.o Node.o
	g++ -o test test.cpp List.o Node.o $(FLAGS) 
clean:
	rm main.o .DS_Store main Node.o List.o tests tests.o

