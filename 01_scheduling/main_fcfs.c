#include <stdio.h>
#include <stdlib.h>

/* When there are pnum processes,
 * Return a 2-D array of dimension
 * pnum x 7 
 * */

int **create_process_table(int pnum) {
	int **arr = calloc(pnum, sizeof(int *));
	for(int i = 0; i < pnum; i++) {
		arr[i] = calloc(7, sizeof(int));
	}
	return arr;
}

/* The index to column mapping is :
 * 0 : Process ID
 * 1 : Arrival Time
 * 2 : Burst Time
 * 3 : Completion Time
 * 4 : Turnaround Time
 * 5 : Waiting Time
 * 6 : Response Time 
 * */

void get_pid_data(int **arr, int pnums) {
	int pids = 0;
	for(int i = 0; i < pnums; i++) {
		printf("\nEnter the data for process %d", ++pids);
		arr[i][0] = pids;
		printf("\nArrival Time : ");
		scanf("%d", &arr[i][1]);
		printf("\nBurst Time : ");
		scanf("%d", &arr[i][2]);
	}
}

void sort_arrival_time(int **arr, int pnums) {
	int *ptr;
	for(int i = 0; i < pnums; i++) {
		for(int j = i + 1; j < pnums; j++) {
			if(arr[i][1] > arr[j][1]) {
				ptr = arr[i];
				arr[i] = arr[j];
				arr[j] = ptr;
			}
		}
	}
}

void display_process_table(int **arr, int pnums) {
	printf("\n|PID\t|AT\t|BT\t|CT\t|TAT\t|WT\t|RT\n");
	for(int i = 0; i < pnums; i++) {
		for(int j = 0; j < 7; j++) {
			printf("|%d\t", arr[i][j]);
		}	putchar('\n');
	}	putchar('\n');
}

void calculate_params(int **arr, int pnums) {
	int time = 0;
	for(int i = 0; i < pnums; i++) {
		time = arr[i][1] > time ? arr[i][1] : time;

		/* CT = Time + BT */
		arr[i][3] = time + arr[i][2];

		/* TAT = CT - AT */
		arr[i][4] = arr[i][3] - arr[i][1];

		/* WT = TAT - BT */
		/* FCFS, so RT = WT */
		arr[i][6] = arr[i][5] = arr[i][4] - arr[i][2];

		time = arr[i][3];
	}
}

void free_table(int **arr, int pnums) {
	for(int i = 0; i < pnums; i++) {
		free(arr[i]);
	}	free(arr);
}

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	sort_arrival_time(arr, pnums);
	calculate_params(arr, pnums);
	display_process_table(arr, pnums);
	free_table(arr, pnums);

	return 0;
}
