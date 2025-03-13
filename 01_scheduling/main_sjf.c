#include <stdio.h>
#include "process.h"

int main() {
	int pnums, **arr;
	printf("Enter the number of processes : ");
	scanf("%d", &pnums);

	arr = create_process_table(pnums);
	get_pid_data(arr, pnums);

	return 0;
}
