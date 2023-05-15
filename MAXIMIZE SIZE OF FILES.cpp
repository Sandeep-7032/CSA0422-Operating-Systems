#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)

#define MAX_FILE_SIZE \
    (DIRECT_BLOCKS + \
    SINGLE_INDIRECT_BLOCKS + \
    DOUBLE_INDIRECT_BLOCKS + \
    TRIPLE_INDIRECT_BLOCKS)

int main() {
    int maxFileSize = 0;
    
    // Calculate the maximum file size in bytes
    maxFileSize = DIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += SINGLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += TRIPLE_INDIRECT_BLOCKS * BLOCK_SIZE; 
    printf("Maximum file size: %d bytes\n", maxFileSize);
    
    return 0;
}
