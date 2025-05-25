#include <stdio.h>
#include <stdlib.h>

#define TOTAL_BLOCKS 100

int main() {
    int memory[TOTAL_BLOCKS] = {0}; // 0 = free, 1 = occupied
    int start, length, i, choice;

    printf("Sequential File Allocation Simulation\n");

    while (1) {
        printf("\nEnter starting block (0 to %d): ", TOTAL_BLOCKS - 1);
        scanf("%d", &start);

        printf("Enter length (number of blocks required): ");
        scanf("%d", &length);

        if (start < 0 || start >= TOTAL_BLOCKS || length <= 0 || start + length > TOTAL_BLOCKS) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Check if the blocks are free
        int allocated = 1;
        for (i = start; i < start + length; i++) {
            if (memory[i] == 1) {
                allocated = 0;
                break;
            }
        }

        if (allocated) {
            // Allocate memory
            for (i = start; i < start + length; i++) {
                memory[i] = 1;
            }
            printf("File allocated from block %d to %d.\n", start, start + length - 1);
        } else {
            printf("Cannot allocate file: Blocks from %d to %d are not free.\n", start, start + length - 1);
        }

        printf("\nDo you want to allocate another file? (1=Yes, 0=No): ");
        scanf("%d", &choice);
        if (choice == 0) break;
    }

    // Show memory block status
    printf("\nMemory Block Allocation Status:\n");
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        printf("Block %3d: %s\n", i, memory[i] ? "Occupied" : "Free");
    }

    return 0;
}
