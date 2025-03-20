#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void calculate_params_srtf(int **arr, int pnums) {
    int *remaining_time = malloc(pnums * sizeof(int));
    int *is_started = calloc(pnums, sizeof(int));
    for (int i = 0; i < pnums; i++) {
        remaining_time[i] = arr[i][2];
    }

    int time = 0;
    int completed = 0;

    while (completed < pnums) {
        int shortest_remaining = -1;
        int next_process = -1;

        for (int i = 0; i < pnums; i++) {
            if (remaining_time[i] > 0 && arr[i][1] <= time) {
                if (shortest_remaining == -1 || remaining_time[i] < shortest_remaining) {
                    shortest_remaining = remaining_time[i];
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
            arr[next_process][3] = time;
            arr[next_process][4] = arr[next_process][3] - arr[next_process][1];
            arr[next_process][5] = arr[next_process][4] - arr[next_process][2];
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
    calculate_params_srtf(arr, pnums);
    display_process_table(arr, pnums);
    free_table(arr, pnums);

    return 0;
}
