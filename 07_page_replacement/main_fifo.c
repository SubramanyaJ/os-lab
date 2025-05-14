#include <stdio.h>

int main() {
	int frames, pages, i, j, k, pageFaults = 0, current = 0;
	printf("Enter number of frames: ");
	scanf("%d", &frames);
	printf("Enter number of pages: ");
	scanf("%d", &pages);
	int referenceString[pages], frame[frames];
	printf("Enter reference string: ");
	for (i = 0; i < pages; i++) {
		scanf("%d", &referenceString[i]);
	}
	for (i = 0; i < frames; i++) {
		frame[i] = -1;
	}
	for (i = 0; i < pages; i++) {
		int found = 0;
		for (j = 0; j < frames; j++) {
			if (frame[j] == referenceString[i]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			frame[current] = referenceString[i];
			current = (current + 1) % frames;
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
