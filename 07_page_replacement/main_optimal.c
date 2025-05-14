#include <stdio.h>

int main() {
	int frames, pages, i, j, k, pageFaults = 0, max, index;
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
			int empty = -1;
			for (j = 0; j < frames; j++) {
				if (frame[j] == -1) {
					empty = j;
					break;
				}
			}
			if (empty != -1) {
				frame[empty] = referenceString[i];
			} else {
				max = -1;
				for (j = 0; j < frames; j++) {
					int next = 0;
					for (k = i + 1; k < pages; k++) {
						if (frame[j] == referenceString[k]) {
							next = k;
							break;
						}
					}
					if (next == 0) {
						index = j;
						break;
					} else {
						if (next > max) {
							max = next;
							index = j;
						}
					}
				}
				frame[index] = referenceString[i];
			}
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
