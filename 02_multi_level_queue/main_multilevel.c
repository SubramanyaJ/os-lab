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

// #define frontof_queue(sys) ((struct Process *)) frontof_queue(sys))

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
	/* This classifies the porcesses */
	for(int i = 0; i < *n; i++) {
		enqueue_queue( (parr[i].PRI == 0 ? sys : usr), &parr[i]);
	}
	/* This sorts the queues */
	qsort(sys, itemsin_queue(sys), sizeof(struct Process), ar_sort);
	qsort(usr, itemsin_queue(usr), sizeof(struct Process), ar_sort);
}

void fill_data(struct Process *p_cu, int *time) {
	p_cu->RT = *time;
	*time += p_cu->BT;
	p_cu->CT = *time;
	p_cu->TAT = *time - p_cu->AT;
	p_cu->WT = p_cu->TAT = p_cu->BT;
}

void scheduler_fcfs(struct Queue *sys, struct Queue *usr) {
	int time = 0;
	struct Process *c, *sh, *uh;

	while(!isempty_queue(sys) || !isempty_queue(usr)) {
		sh = (struct Process *) frontof_queue(sys);
		uh = (struct Process *) frontof_queue(usr);

		if(sh->AT > uh->AT) {
			c = dequeue_queue(sys);
			fill_data(c, &time);
		}

	}

}

void display_process_table(struct Process *p_list, int n) {
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tPRI\tRT\n");
	struct Process p;
	for(int i = 0; i < n; i++) {
		p = p_list[i];
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			p.PID, p.AT, p.BT, p.CT, p.TAT, p.WT, p.PRI, p.RT);
	}
}

int
main() {
	int n;
	struct Process *p_list = get_processes(&n);
	struct Queue *sys, *usr;
	classify_processes(p_list, &n, sys, usr);
	scheduler_fcfs(sys, usr);
	display_process_table(p_list, n);
}
