
#include <stdio.h>
#include <stdlib.h>

#define PRINT_MSG(msg) printf("%s", msg)
#define PRINT_BLOCK(block) printf("Block %d already allocated.\n", block)
#define PRINT_SEQ_ALLOC() printf("Sequential allocation complete.\n")
#define PRINT_IDX_ALLOC() printf("Indexed allocation complete.\n")
#define PRINT_LINK_ALLOC() printf("Linked allocation complete.\n")

#define SEQUENTIAL_ALLOC(files, start, length) \
    for (int i = start; i < start + length; i++) { \
        if (files[i] == 0) files[i] = 1; \
        else { PRINT_BLOCK(i); return 0; } \
    } \
    PRINT_SEQ_ALLOC();

#define INDEXED_ALLOC(files, index, blocks, count) \
    if (files[index] == 1) { PRINT_BLOCK(index); return 0; } \
    files[index] = 1; \
    for (int i = 0; i < count; i++) { \
        if (files[blocks[i]] == 0) files[blocks[i]] = 1; \
        else { PRINT_BLOCK(blocks[i]); return 0; } \
    } \
    PRINT_IDX_ALLOC();

#define LINKED_ALLOC(files, start, chain, length) \
    int current = start; \
    for (int i = 0; i < length; i++) { \
        if (files[current] == 0) files[current] = 1; \
        else { PRINT_BLOCK(current); return 0; } \
        current = chain[i]; \
    } \
    PRINT_LINK_ALLOC();

int main() {
    int size = 100, files[100] = {0};
    
    int start_seq, length_seq, start_idx, length_idx, index_idx, count_idx, start_link, length_link;
    int blocks[100], chain[100];

    // Input for Sequential Allocation
    PRINT_MSG("Enter start and length for Sequential Allocation: ");
    scanf("%d %d", &start_seq, &length_seq);
    SEQUENTIAL_ALLOC(files, start_seq, length_seq);

    // Input for Indexed Allocation
    PRINT_MSG("Enter index and count of blocks for Indexed Allocation: ");
    scanf("%d %d", &index_idx, &count_idx);
    PRINT_MSG("Enter blocks: ");
    for (int i = 0; i < count_idx; i++) scanf("%d", &blocks[i]);
    INDEXED_ALLOC(files, index_idx, blocks, count_idx);

    // Input for Linked Allocation
    PRINT_MSG("Enter start and length of chain for Linked Allocation: ");
    scanf("%d %d", &start_link, &length_link);
    PRINT_MSG("Enter chain blocks: ");
    for (int i = 0; i < length_link; i++) scanf("%d", &chain[i]);
    LINKED_ALLOC(files, start_link, chain, length_link);

    return 0;
}

