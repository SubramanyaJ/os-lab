#include <stdio.h>
#include <stdlib.h>
#include "rtos.h"

#define PCAST (struct Process *)

int
proccmp(const void *x, const void *y) {
	return (PCAST x)->ival - (PCAST y)->ival;
}

void
monotonic_scheduler(struct Process *arr, int n) {
	int max_time = arr[n-1].ival * 2;
	int time = 0;
	struct Process *curr = NULL, *prev = NULL;

	while(time < max_time) {

		for(int i = 0; i < n; i++) {
			if(arr[i].next_release == time) {
				arr[i].rtr = true;
				arr[i].next_release += arr[i].ival;
				arr[i].rem_bt = arr[i].bt;
			}
		}

		curr = NULL;
		for(int i = 0; i < n; i++) {
			if(arr[i].rtr == true && arr[i].rem_bt > 0) {
				curr = &arr[i];
				break;
			}
		}

		if(prev != curr) {
			if (prev != NULL && prev->rem_bt > 0)
				printf("PID %d till %d\n", prev->PID, time);
			if (curr != NULL)
				printf("PID %d starts at %d\n", curr->PID, time);
			prev = curr;
		}

		if(!curr) {time++; continue;}
		curr->rem_bt--;
		if(curr->rem_bt == 0) { curr->rtr = false; }
		time++;

	}
	return;
}

int
main() {
	int n;
	struct Process *arr = get_processes(&n);
	qsort(arr, n, sizeof(struct Process), proccmp);
	putchar('\n');

	monotonic_scheduler(arr, n);

	return 0;
}
