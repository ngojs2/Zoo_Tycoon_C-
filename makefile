

output: main.o animal.o penguin.o tiger.o turtle.o zoo.o
	g++ main.o animal.o penguin.o tiger.o turtle.o zoo.o -o zoo

main.o: main.cpp
	g++ -c main.cpp

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -c zoo.cpp

clean:
	rm *.ro zoo

