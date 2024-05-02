#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    // Initialize allocation to -1 to indicate not allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find the best fit block
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;  // Index of best fit block
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }

        // If we found a fit block, allocate it and update
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No. \t Process Size \t Block No.\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d \t\t %d \t\t %d\n", i + 1, processSize[i], allocation[i] + 1);
        } else {
            printf("%d \t\t %d \t\t Not Allocated\n", i + 1, processSize[i]);
        }
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    // Initialize allocation to -1 to indicate not allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find the worst fit block
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;  // Index of worst fit block
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]) {
                    worstIdx = j;
                }
            }
        }

        // If we found a fit block, allocate it and update
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[j] -= processSize[i];
        }
    }

    printf("\nProcess No. \t Process Size \t Block No.\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d \t\t %d \t\t %d\n", i + 1, processSize[i], allocation[i] + 1);
        } else {
            printf("%d \t\t %d \t\t Not Allocated\n", i + 1, processSize[i]);
        }
    }
}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    // Initialize allocation to -1 to indicate not allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find the first fit block
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;  // Break after finding the first fit
            }
        }
    }

    printf("\nProcess No. \t Process Size \t Block No.\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d \t\t %d \t\t %d\n", i
