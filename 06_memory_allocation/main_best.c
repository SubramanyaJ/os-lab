#include <stdio.h>
#include "main_common.c"

void bestFit(int blockSize[], int m, int processSize[], int n) {
	int allocation[n];

	for (int i = 0; i < n; i++) {
		allocation[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		int bestIdx = -1;

		for (int j = 0; j < m; j++) {
			if (blockSize[j] >= processSize[i]) {
				if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
					bestIdx = j;
				}
			}
		}

		if (bestIdx != -1) {
			allocation[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\n");
	for (int i = 0; i < n; i++) {
		if (allocation[i] != -1) {
			printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, blockSize[allocation[i]]);
		} else {
			printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
		}
	}
}

int main() {
	COMMON_MAIN()
	bestFit(blockSize, m, processSize, n);

	return 0;
}

