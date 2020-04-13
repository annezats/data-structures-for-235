OBJECTS=main.o Node.o
LDFLAGS=
CXXFLAGS=
FLAGS = -std=c++14

main: $(OBJECTS)
	g++ -o main $(OBJECTS)  $(FLAGS) 


main.o: main.cpp Node.h 
Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)