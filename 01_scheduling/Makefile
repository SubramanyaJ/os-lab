CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -O2

all:
	$(CC) main_fcfs.c process.c -o fcfs $(CFLAGS)
	$(CC) main_sjf.c process.c -o sjf $(CFLAGS)

clean:
	rm fcfs sjf
