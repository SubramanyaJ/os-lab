CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -O2 -Werror

all:
	@$(CC) main_fcfs.c process.c -o fcfs.out $(CFLAGS)
	@$(CC) main_sjf.c process.c -o sjf.out $(CFLAGS)
	@$(CC) main_sjf_preempt.c process.c -o sjf_preempt.out $(CFLAGS)
	@$(CC) main_pr.c process.c -o pr.out $(CFLAGS)
	@$(CC) main_pr_preempt.c process.c -o pr_preempt.out $(CFLAGS)
	@$(CC) main_rr.c process.c -o rr.out $(CFLAGS)

	@echo "\nFirst Come First Served :"
	@cat ./data_fcfs.txt | ./fcfs.out
	@echo "\nShortest Job First :"
	@cat ./data_sjf.txt | ./sjf.out
	@echo "\nPreemptive Shortest Job First :"
	@cat ./data_sjf.txt | ./sjf_preempt.out
	@echo "\nPriority Scheduling :"
	@cat ./data_pr.txt | ./pr.out
	@echo "\nPreemptive Priority Scheduling : "
	@cat ./data_pr_preempt.txt | ./pr_preempt.out
	@echo "\nRound Robin :"
	@cat ./data_rr.txt | ./rr.out


clean:
	@rm *.out
