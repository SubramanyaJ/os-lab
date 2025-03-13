/* Write a program in C to count the total number of duplicate elements in an array.*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int nums) {
	int temp;
	for(int i = 0; i < nums; i++) {
		for(int j = i + 1; j < nums; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}
int duplicates_num(int *arr, int nums) {
	bubble_sort(arr, nums);
	int count = 0, temp;
	for(int i = 0; i < nums; i++) {
		if(arr[i] == arr[i+1]) {
			temp = arr[i];
			count++;
			while(arr[i] == temp && i < nums) {
				i++;
			}

		}
	}
	return count;
}

int main() {
	int arr[] = {12, 434, 12, 434, 78, 89, 12};
	printf("Duplicates : %d\n", duplicates_num(arr, sizeof(arr)/sizeof(int)));
	return 0;
}
