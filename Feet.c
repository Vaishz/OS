#include <stdio.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESS 100

int partitions[MAX_PARTITIONS];
int processes[MAX_PROCESS];
int num_partitions, num_processes;
int allocated[MAX_PROCESS]; // Array to store allocated partition index for each process (-1 if not allocated)

// Function prototypes
void initialize();
void displayPartitions();
void displayProcesses();
void firstFit();
void bestFit();
void worstFit();
void displayAllocation();

int main() {
    initialize();
    printf("Initial partitions:\n");
    displayPartitions();
    printf("Processes:\n");
    displayProcesses();

    // Perform allocation using different algorithms
    printf("\nFirst Fit Allocation:\n");
    firstFit();
    displayPartitions();
    displayAllocation(); // New function to show process allocation

    printf("\nBest Fit Allocation:\n");
    bestFit();
    displayPartitions();
    displayAllocation();

    printf("\nWorst Fit Allocation:\n");
    worstFit();
    displayPartitions();
    displayAllocation();

    return 0;
}

void initialize() {
    printf("Enter number of partitions: ");
    scanf("%d", &num_partitions);
    printf("Enter sizes of partitions:\n");
    for (int i = 0; i < num_partitions; i++) {
        scanf("%d", &partitions[i]);
        allocated[i] = -1; // Initialize allocated array
    }
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &processes[i]);
    }
}

void displayPartitions() {
    for (int i = 0; i < num_partitions; i++) {
        printf("%d ", partitions[i]);
    }
    printf("\n");
}

void displayProcesses() {
    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d ", processes[i]);
    }
    printf("\n");
}

void firstFit() {
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_partitions; j++) {
            if (processes[i] <= partitions[j] && allocated[j] == -1) {
                partitions[j] -= processes[i];
                allocated[j] = i; // Mark partition as allocated to this process
                break;
            }
        }
    }
}

void bestFit() {
    for (int i = 0; i < num_processes; i++) {
        int best_index = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (processes[i] <= partitions[j] && (best_index == -1 || partitions[j] < partitions[best_index]) && allocated[j] == -1) {
                best_index = j;
            }
        }
        if (best_index != -1) {
            partitions[best_index] -= processes[i];
            allocated[best_index] = i;
        }
    }
}

void worstFit() {
    for (int i = 0; i < num_processes; i++) {
        int worst_index = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (processes[i] <= partitions[j] && (worst_index == -1 || partitions[j] > partitions[worst_index]) && allocated[j] == -1) {
                worst_index = j;
            }
        }
        if (worst_index != -1) {
            partitions[worst_index] -= processes[i];
            allocated[worst_index] = i;
        }
    }
}

void displayAllocation() {
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        int allocated_block = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (allocated[j] == i) {
                allocated_block = j + 1; // Block numbers start from 1
                break;
            }
        }
        if (allocated_block != -1) {
            printf("%d\n", allocated_block);
        } else {
            printf("Not Allocated\n");
        }
    }
}
