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

struct process {
	int PID, AT, BT;
	int CT, TAT, WT;
	int PRI, RT;
};

struct process *get_processes() {
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);

	struct process *parr = calloc(n, sizeof(struct process));
	for (int i = 0; i < n; i++) {
		parr[i].PID = i + 1;
		printf("Enter Arrival Time, Burst Time, and Priority (0 for System, 1 for User) for Process %d: ", i + 1);
		scanf("%d %d %d", &parr[i].AT, &parr[i].BT, &parr[i].PRI);
	}
	return parr;
}



int main() {

}
