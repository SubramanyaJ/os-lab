CC=gcc
CFLAGS=-Wall -Werror -Wextra

all:
	$(CC) main_fcfs.c process.c -o fcfs $(CFLAGS)
	$(CC) main_sjf.c process.c queue.c -o sjf $(CFLAGS)

clean:
	rm fcfs sjf
