CFLAGS= -Wall -O3 -fsanitize=address

all:
	@echo "\nRate Monotonic Scheduler :\n"
	@clang main_rate_monotonic.c rtos.c -o main_rate_monotonic.out
	@cat ./data.txt | ./main_rate_monotonic.out

	@echo "\nEarliest Deadline First Scheduler:\n"
	@clang main_earlier_df.c rtos.c -o main_earlier_df.out
	@cat ./data.txt | ./main_earlier_df.out

	@echo "\Proportional Scheduler:\n"
	@clang main_proportional.c rtos.c -o main_proportional.out
	@cat ./data_proportional.txt | ./main_proportional.out
