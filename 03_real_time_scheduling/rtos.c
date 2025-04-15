#include "rtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process *get_processes(int *n) {
	printf("Enter the number of processes : ");
	scanf("%d", n);

	struct Process *arr = calloc(*n, sizeof(struct Process));
	printf("Enter the burst time and intervals : \n");
	
	for(int i = 0; i < *n; i++) {
		arr[i].PID = i + 1;
		printf("PID %d : ", i + 1);
		scanf("%d %d", &arr[i].bt, &arr[i].ival);
		arr[i].rtr = true;
	}

	return arr;
}
