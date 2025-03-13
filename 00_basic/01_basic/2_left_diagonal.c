#include <stdio.h>
#include <stdlib.h>

void sum_left_diagonal(int **arr, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i][i];
	}
	printf("%d\n", sum);
	return;
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
	sum_left_diagonal(arr, n);
}
