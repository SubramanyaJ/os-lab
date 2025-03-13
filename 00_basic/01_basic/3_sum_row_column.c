#include <stdio.h>
#include <stdlib.h>

void sums(int **arr, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum += arr[i][j];			
		}
		printf("Sum of row %d : %d\n", i, sum);
		sum = 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum += arr[j][i];	
		}
		printf("\nSum of column %d : %d\n", i, sum);
		sum = 0;
	}
}

int main() {
	int n;
	printf("Enter the dimension of the square matrix : ");
	scanf("%d", &n);
	int **arr = malloc(sizeof(int *)*n);
	for(int i = 0; i < n; i++) {
		arr[i] = malloc(sizeof(int)*n);
	}
	printf("Enter the values : ");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("[%d][%d] : ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	sums(arr, n);
	return 0;
}
