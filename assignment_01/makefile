FLAGS = -std=c++14

main: main.o myvector.o
	g++ -o main main.o myvector.o $(FLAGS) 

tests: tests.o myvector.o
	g++ -o tests tests.o myvector.o $(FLAGS)

main.o: main.cpp myvector.h

myvector.o: myvector.cpp myvector.h

tests.o: tests.cpp myvector.h
	g++ -c tests.cpp $(FLAGS)

clean:
	rm main.o .DS_Store main myvector.o tests tests.o

