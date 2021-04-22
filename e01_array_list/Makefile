OBJS=main01.o array_list.o
CC=gcc
CFLAGS+=-c -Wall -g

run: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) -r *.o run