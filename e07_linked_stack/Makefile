OBJS=main07.o dllist_lib.o linked_stack.o
CC=gcc
CFLAGS+=-c -Wall -g

run: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) -r *.o run