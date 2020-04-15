OBJECTS=main.o Node.o tree.o 
LDFLAGS=
CXXFLAGS= -std=c++14

main: $(OBJECTS)
	g++ -o main $(OBJECTS)  $(CXXFLAGS) 


main.o: main.cpp Node.h 
Node.o: Node.cpp Node.h
tree.o: tree.cpp tree.h

clean:
	rm -f $(OBJECTS) main