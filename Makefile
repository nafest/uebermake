all: uebermake

uebermake.o: uebermake.cpp
	g++ -g -c uebermake.cpp
	
parser.o: parser.cpp parser.h
	g++ -g -c parser.cpp

uebermake: uebermake.o parser.o
	g++ -o uebermake uebermake.o parser.o

tests.o: tests.cpp
	g++ -g -c tests.cpp -I../gtest-1.7.0/include

umtests: tests.o parser.o
	g++ -o umtests tests.o parser.o ../gtest-1.7.0/lib/.libs/libgtest_main.a ../gtest-1.7.0/lib/.libs/libgtest.a

clean:
	rm uebermake.o parser.o uebermake
	rm tests.o umtests
