#include <stdio.h>
#define MAX 10

int main()
{
    // Variables declaration: p for processes, r for resources
    int p, r, count = 0, i, j;
    int alc[MAX][MAX], max[MAX][MAX], need[MAX][MAX], safe[MAX], available[MAX], finish[MAX] = {0};

    // Input number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &r);

    // Input allocation of resources for all processes
    printf("Enter allocation of resources for all processes (%dx%d matrix):\n", p, r);
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alc[i][j]);
        }
    }

    // Input maximum resources required by processes
    printf("Enter the maximum resources required by processes (%dx%d matrix):\n", p, r);
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("Enter the available resources:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &available[i]);

    // Calculate and display need resources matrix
    printf("\nNeed resources matrix:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }


    while (count < p) //count is no of proc in safe state
    {
        int isSafe = 0; // Flag to indicate if the current process can be included in the safe sequence

        // Iterate over each process
        for (i = 0; i < p; i++)
        {
            // Check if the process is already finished
            if (finish[i] == 0)
            {
                int canProceed = 1; // Flag to indicate if the process can proceed with the available resources

                // Check if all resource needs of the process can be satisfied with available resources
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        canProceed = 0; // Process cannot proceed due to insufficient resources
                        break;
                    }
                }

                // If all needs are met, add process to safe sequence
                if (canProceed)
                {
                    safe[count] = i; // Add the process to the safe sequence
                    finish[i] = 1;   // Mark the process as finished
                    count++;         // Increment the number of processes included in the safe sequence
                    isSafe = 1;      // Set flag to indicate that a process was included in this iteration

                    // Release resources
                    for (j = 0; j < r; j++)
                    {
                        available[j] += alc[i][j];
                    }
                }
            }
        }

        // If no process was added to the safe sequence in this iteration, it means deadlock
        if (!isSafe)
        {
            printf("Safe sequence does not exist");
            break;
        }
    }

    if (count == p)
    {
        printf("\nAvailable resources after completion:\n");
        for (i = 0; i < r; i++)
        {
            printf("%d\t", available[i]);
        }
        printf("\nSafe sequence:\n");
        for (i = 0; i < p; i++)
        {
            printf("p%d\t", safe[i]);
        }
    }
}