all: logarithm

logarithm: main.o functions.o
	g++ main.o functions.o -o logarithm

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

run:
	./logarithm

clean:
	rm -rf *.o logarithm

.PHONY: run clean