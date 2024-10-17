Polynomial Calculator: main.o polycalculator.o LinkedList.o
	g++ main.o polycalculator.o LinkedList.o -o polycalc

main.o: main.cpp
	@echo "Compiling main"
	g++ -c main.cpp

polycalculator.o: polycalculator.cpp polycalculator.h
	g++ -c polycalculator.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm polycalculator.o main.o LinkedList.o polycalc
