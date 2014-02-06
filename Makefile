all: uebermake

uebermake.o: uebermake.cpp
	g++ -c uebermake.cpp

uebermake: uebermake.o
	g++ -o uebermake uebermake.o

tests.o: tests.cpp
	g++ -c tests.cpp -I../gtest-1.7.0/include

umtests: tests.o
	g++ -o umtests tests.o ../gtest-1.7.0/lib/.libs/libgtest_main.a ../gtest-1.7.0/lib/.libs/libgtest.a

clean:
	rm uebermake.o uebermake
	rm tests.o umtests