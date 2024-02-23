CC = gcc
CFLAGS = -Wall

test_basic: test_basic.o linkedlist.o
	$(CC) -o test_basic test_basic.o linkedlist.o $(CFLAGS)

test_threaded: test_threaded.o linkedlist.o
	$(CC) -o test_threaded test_linkedList_threaded.o linkedlist.o $(CFLAGS) -lpthread

test_basic.o: test_basic.c
	$(CC) -c test_basic.c

linkedlist.o: linkedlist.c
	$(CC) -c linkedlist.c

test_threaded.o: test_linkedList_threaded.c
	$(CC) -c test_linkedList_threaded.c

clean:
	rm -f test_basic test_basic.o linkedlist.o test_threaded.o test_threaded
