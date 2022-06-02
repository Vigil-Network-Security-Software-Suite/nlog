all: nlog clean
CC=gcc
CFLAGS=-Wall

main.o:
	$(CC) $(CFLAGS) -c main.c


nlog: main.o
	$(CC) $(CFLAGS) -o nlog -l 
clean:
	rm *.o