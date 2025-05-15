#include "page_replacement.h"

int main() {
	int frames, pages, pageFaults = 0;
	int referenceString[100], frame[100];

	GET_INPUT(frames, pages, referenceString);

	for (int i = 0; i < frames; i++) {
		frame[i] = -1;
	}

	for (int i = 0; i < pages; i++) {
		int found = 0;
		for (int j = 0; j < frames; j++) {
			if (frame[j] == referenceString[i]) {
				found = 1;
				break;
			}
		}

		if (!found) {
			int max = -1, index = -1;
			for (int j = 0; j < frames; j++) {
				if (frame[j] == -1) { index = j; break; }

				int next = 0;
				for (int k = i + 1; k < pages; k++) {
					if (frame[j] == referenceString[k]) { next = k; break; }
				}

				if (next == 0) { index = j; break; }
				if (next > max) { max = next; index = j; }
			}

			frame[index] = referenceString[i];
			pageFaults++;
		}

		DISPLAY_FRAMES(referenceString[i], frames, frame);
	}

		PRINT_PAGE_FAULTS(pageFaults);
		return 0;
	}
