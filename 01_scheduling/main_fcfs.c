#include <stdio.h>
#include "process.h"

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	sort_index(arr, pnums, 1);
	calculate_params(arr, pnums, 0);
	display_process_table(arr, pnums);
	free_table(arr, pnums);

	return 0;
}
