/*
 * A program to implement
 * earliest deadline
 * first scheduling
 * */


/* Algorithm :
* Input: Task set T = {T1, T2, ..., Tn}
Each task Ti has (Deadline Di, Execution Time Ci)

1. At each time unit t:
   a. For all ready tasks, calculate the absolute deadline
   b. Select the task with the earliest deadline
   c. If a task is running, preempt it if another task has an earlier deadline
   d. Run the selected task for 1 time unit
   e. Update execution time and check for completion
   f. Repeat
*/

#include <stdio.h>
#include <stdlib.h>
#include "rtos.h"

#define PCAST (struct Process *)

int
proccmp(const void *x, const void *y) {
	return (PCAST x)->ival - (PCAST y)->ival;
}

void earliest_deadline_scheduler(struct Process *arr, int n) {
	int max_time = arr[n-1].ival * 2;
	int time = 0;
	struct Process *curr = NULL, *prev = NULL;

	while(time < max_time) {

		for(int i = 0; i < n; i++) {
			if(arr[i].next_release == time) {
				arr[i].rtr = true;
				arr[i].rem_bt = arr[i].bt;
				arr[i].deadline = time + arr[i].ival;
				arr[i].next_release += arr[i].ival;
			}
		}

		curr = NULL;
		for(int i = 0; i < n; i++) {
			if(arr[i].rtr && arr[i].rem_bt > 0) {
				if(!curr || arr[i].deadline < curr->deadline) {
					curr = &arr[i];
				}
			}
		}

		if(prev != curr) {
			if (prev != NULL && prev->rem_bt > 0)
				printf("PID %d till %d\n", prev->PID, time);
			if (curr != NULL && curr->PID)
				printf("PID %d starts at %d\n", curr->PID, time);
			prev = curr;
		}

		if(!curr) {time++; continue;}

		curr->rem_bt--;
		if(curr->rem_bt == 0) {
			curr->rtr = false;
		}
		
		time++;
	}
	return;
}

int main() {
	int n;
	struct Process *arr = get_processes(&n);
	putchar('\n');
	earliest_deadline_scheduler(arr, n);

	free(arr);
	return 0;
}
