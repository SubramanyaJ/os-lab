#include <stdio.h>

int main() {
	int frames, pages, i, j, k, pageFaults = 0, min;
	printf("Enter number of frames: ");
	scanf("%d", &frames);
	printf("Enter number of pages: ");
	scanf("%d", &pages);
	int referenceString[pages], frame[frames], counter[frames];
	printf("Enter reference string: ");
	for (i = 0; i < pages; i++) {
		scanf("%d", &referenceString[i]);
	}
	for (i = 0; i < frames; i++) {
		frame[i] = -1;
		counter[i] = 0;
	}
	for (i = 0; i < pages; i++) {
		int found = 0;
		for (j = 0; j < frames; j++) {
			if (frame[j] == referenceString[i]) {
				found = 1;
				counter[j] = i + 1;
				break;
			}
		}
		if (!found) {
			min = 0;
			for (j = 1; j < frames; j++) {
				if (counter[j] < counter[min]) {
					min = j;
				}
			}
			frame[min] = referenceString[i];
			counter[min] = i + 1;
			pageFaults++;
		}
		printf("%d: ", referenceString[i]);
		for (k = 0; k < frames; k++) {
			printf("%d ", frame[k]);
		}
		printf("\n");
	}
	printf("Total Page Faults: %d\n", pageFaults);
	return 0;
}
