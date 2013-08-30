CC=g++

CFLAGS=-c -Wall -g

all: test

test: test.o
	$(CC) test.o -o test

test.o: test.cpp InsersionSort.h
	$(CC) $(CFLAGS) test.cpp -o test.o

clean:
	rm -rf *.o test
