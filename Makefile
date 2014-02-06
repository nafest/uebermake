all: uebermake

uebermake.o: uebermake.cpp
	g++ -c uebermake.cpp

uebermake: uebermake.o
	g++ -o uebermake uebermake.o

clean:
	rm uebermake.o uebermake