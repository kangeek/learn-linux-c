OBJS=main09.o dllist_lib.o linked_queue.o
CC=gcc
CFLAGS+=-c -Wall -g

run: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) -r *.o run