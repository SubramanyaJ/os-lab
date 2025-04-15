CFLAGS= -Wall -O3 -fsanitize=address

all:
	@clang main_rate_monotonic.c rtos.c -o main_rate_monotonic.out -lm
	@./main_rate_monotonic.out
