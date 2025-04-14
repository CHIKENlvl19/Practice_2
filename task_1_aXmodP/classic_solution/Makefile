all: classic

classic: main.o functions.o
	g++ main.o functions.o -o classic

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

run:
	./classic

clean:
	rm -rf *.o classic

.PHONY: run clean