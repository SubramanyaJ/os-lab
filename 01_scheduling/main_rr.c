#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void calculate_params_rr(int **arr, int pnums, int time_quantum) {
    int *remaining_time = malloc(pnums * sizeof(int));
    int *is_started = calloc(pnums, sizeof(int));
    for (int i = 0; i < pnums; i++) {
        remaining_time[i] = arr[i][2];
    }

    int time = 0;
    int completed = 0;

    while (completed < pnums) {
        int done = 1;

        for (int i = 0; i < pnums; i++) {
            if (remaining_time[i] > 0 && arr[i][1] <= time) {
                done = 0;

                if (!is_started[i]) {
                    arr[i][6] = time - arr[i][1]; // RT = Start Time - AT
                    is_started[i] = 1;
                }

                if (remaining_time[i] > time_quantum) {
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    time += remaining_time[i];
                    arr[i][3] = time; // CT
                    arr[i][4] = arr[i][3] - arr[i][1]; // TAT
                    arr[i][5] = arr[i][4] - arr[i][2]; // WT
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }

        if (done) {
            time++;
        }
    }

    free(remaining_time);
    free(is_started);
}

int main() {
	int pnums, time_q, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	printf("Enter the time quantum : ");
	scanf("%d", &time_q);
	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	sort_index(arr, pnums, 1);
	calculate_params_rr(arr, pnums, time_q);
	display_process_table(arr, pnums);
	free_table(arr, pnums);

	return 0;
}
