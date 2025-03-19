#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void calculate_params_preemptive_priority(int **arr, int pnums) {
    sort_index(arr, pnums, 1);

    int *remaining_time = malloc(pnums * sizeof(int));
    int *is_started = calloc(pnums, sizeof(int));
    for (int i = 0; i < pnums; i++) {
        remaining_time[i] = arr[i][2];
    }

    int time = 0;
    int completed = 0;

    while (completed < pnums) {
        int highest_priority = -1;
        int next_process = -1;

        for (int i = 0; i < pnums; i++) {
            if (remaining_time[i] > 0 && arr[i][1] <= time) {
                if (highest_priority == -1 || arr[i][7] < highest_priority) {
                    highest_priority = arr[i][7];
                    next_process = i;
                }
            }
        }

        if (next_process == -1) {
            time++;
            continue;
        }

        if (!is_started[next_process]) {
            arr[next_process][6] = time - arr[next_process][1];
            is_started[next_process] = 1;
        }

        remaining_time[next_process]--;
        time++;

        if (remaining_time[next_process] == 0) {
            completed++;
            arr[next_process][3] = time; // CT = Current Time
            arr[next_process][4] = arr[next_process][3] - arr[next_process][1]; // TAT = CT - AT
            arr[next_process][5] = arr[next_process][4] - arr[next_process][2]; // WT = TAT - BT
        }
    }

    free(remaining_time);
    free(is_started);
}

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	sort_index(arr, pnums, 1);
	calculate_params_preemptive_priority(arr, pnums);
	display_process_table(arr, pnums);
	free_table(arr, pnums);

	return 0;
}
