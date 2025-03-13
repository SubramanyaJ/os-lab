#include <stdio.h>

void bubble_sort(int *arr, int nums) {
	int temp;
	for(int i = 0; i < nums; i++) {
		for(int j = i + 1; j < nums; j++) {
			if(arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}

int main() {
	int arr[] = {1, 5, 5, 342, 524, 325, 234};
	bubble_sort(arr, sizeof(arr)/sizeof(int));
	printf("%d\n", arr[1]);
	return 0;

}
