#include <stdio.h>
#include "process.h"
#include "queue.h"

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);
	/* Sort by arrival time */
	sort_index(arr, pnums, 1);
	/* The first process always get the CPU */



	return 0;
}
