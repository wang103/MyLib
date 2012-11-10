CC=g++

CFLAGS=-c -Wall

all: PriorityQueue.o

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	$(CC) $(CFLAGS) PriorityQueue.h -o PriorityQueue.o

clean:
	rm -rf *.o
