/*	Write a C program to simulate multi-level queue scheduling
 *	algorithm considering the following scenario. All the processes in
 *	the system are divided into two categories – system processes
 *	and user processes. System processes are to be given higher
 *	priority than user processes. Use FCFS scheduling for the
 *	processes in each queue.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Process {
	int PID, AT, BT;
	int CT, TAT, WT;
	int PRI, RT;
};

struct Process 
*get_processes(int *n) {
	printf("Enter number of processes: ");
	scanf("%d", n);

	struct Process *parr = calloc(*n, sizeof(struct Process));
	for (int i = 0; i < *n; i++) {
		parr[i].PID = i + 1;
		printf("Enter Arrival Time, Burst Time, and Priority (0 for System, 1 for User) for Process %d: ", i + 1);
		scanf("%d %d %d", &parr[i].AT, &parr[i].BT, &parr[i].PRI);
	}
	return parr;
}

int ar_sort(const void *x, const void *y) {
	return ((struct Process *) x)->AT - ((struct Process *) y)->AT;
}

void 
classify_processes(struct Process *parr, int *n, struct Queue *sys, struct Queue *usr) {
	/*
	for(int i = 0; i < *n; i++) {
		if(parr[i].PRI == 0) {
			enqueue_queue(sys, (void *) &parr[i]);
		}
		else {
			enqueue_queue(usr, (void *) &parr[i]);
		}
	}
	*/

	/* Can be written as : */
	for(int i = 0; i < *n; i++) {
		enqueue_queue( (parr[i].PRI == 0 ? sys : usr), &parr[i]);
	}
	qsort(sys)
}

int 
main() {

}
