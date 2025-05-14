#define COMMON_MAIN() \
	int m, n; \
	printf("Enter the number of blocks: "); \
	scanf("%d", &m); \
	printf("Enter the number of processes: "); \
	scanf("%d", &n); \
	int blockSize[m], processSize[n]; \
	printf("\nEnter the sizes of the blocks:\n"); \
	for (int i = 0; i < m; i++) { \
		printf("Block %d size: ", i + 1); \
		scanf("%d", &blockSize[i]); \
	} \
	printf("\nEnter the sizes of the processes:\n"); \
	for (int i = 0; i < n; i++) { \
		printf("Process %d size: ", i + 1); \
		scanf("%d", &processSize[i]); \
	}
