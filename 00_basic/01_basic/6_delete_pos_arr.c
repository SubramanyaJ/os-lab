#include <stdio.h>
#include <stdlib.h>

void delete_pos(int **arr, int *nums, int pos) {
	int *arrptr = *arr;
	for(int i = pos - 1; i < *nums - 1; i++) {
		arrptr[i] = arrptr[i + 1]; 
	}
	*arr = realloc(*arr, ((*nums)-1)*sizeof(int));
	(*nums)--;
	return;
}

void display(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int n;	printf("Enter n : \n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);
	printf("Enter the values : ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	display(arr, n);
	int p; printf("Enter the position : ");
	scanf("%d", &p);
	delete_pos(&arr, &n, p);
	display(arr, n);
	return 0;
}
