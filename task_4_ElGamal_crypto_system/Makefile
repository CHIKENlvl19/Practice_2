all: ElGamal

ElGamal: main.o functions.o
	g++ main.o functions.o -o ElGamal

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

run:
	./ElGamal

clean:
	rm -rf *.o ElGamal

.PHONY: run clean