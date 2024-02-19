CC = gcc
CFLAGS = -Wall

test_basic: test_basic.o linkedlist.o
	$(CC) -o test_basic test_basic.o linkedlist.o $(CFLAGS)

test_basic.o: test_basic.c
	$(CC) -c test_basic.c

linkedlist.o: linkedlist.c
	$(CC) -c linkedlist.c

clean:
	rm -f test_basic test_basic.o linkedlist.o
