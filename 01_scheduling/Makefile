CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -O2 -Werror

all:
	$(CC) main_fcfs.c process.c -o fcfs $(CFLAGS)
	$(CC) main_sjf.c process.c -o sjf $(CFLAGS)
	$(CC) main_pr.c process.c -o pr $(CFLAGS)
	$(CC) main_pr_preempt.c process.c -o pr_preempt $(CFLAGS)
	$(CC) main_rr.c process.c -o rr $(CFLAGS)

	echo "\nFirst Come First Served :"
	cat ./data_fcfs.txt | ./fcfs
	echo "\nShortest Job First :"
	cat ./data_sjf.txt | ./sjf
	echo "\nPriority Scheduling :"
	cat ./data_pr.txt | ./pr
	echo "\nPreemptive Priority Scheduling : "
	cat ./data_pr_preempt.txt | ./pr_preempt
	echo "\nRound Robin :"
	cat ./data_rr.txt | ./rr


clean:
	rm fcfs sjf pr pr_preempt rr
