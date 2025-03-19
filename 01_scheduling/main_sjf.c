#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void calculate_params_sjf(int **arr, int pnums) {
    sort_index(arr, pnums, 1);

    int time = 0;
    int completed = 0;
    int *completed_processes = calloc(pnums, sizeof(int));

    while (completed < pnums) {
	int shortest_burst = -1;
	int next_process = -1;

	for (int i = 0; i < pnums; i++) {
	    if (!completed_processes[i] && arr[i][1] <= time) {
		if (shortest_burst == -1 || arr[i][2] < shortest_burst) {
		    shortest_burst = arr[i][2];
		    next_process = i;
		}
	    }
	}

	if (next_process == -1) {
	    time++;
	    continue;
	}

	completed_processes[next_process] = 1;
	completed++;

	time += arr[next_process][2];
	arr[next_process][3] = time;

	arr[next_process][4] = arr[next_process][3] - arr[next_process][1]; // TAT = CT - AT
	arr[next_process][5] = arr[next_process][4] - arr[next_process][2]; // WT = TAT - BT
	arr[next_process][6] = arr[next_process][5]; // RT = WT (for non-preemptive SJF)
    }

    free(completed_processes);
}

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	sort_index(arr, pnums, 1);
	calculate_params_sjf(arr, pnums);
	display_process_table(arr, pnums);
	free_table(arr, pnums);

	return 0;
}
