#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000

struct Process
{
    char name[10];
    int at;
    int bt;
    int rt; // Remaining time
    int ct;
    int tat;
    int wt;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Process arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].at > arr[j+1].at)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void calculateCompletionTime(struct Process processes[], int n)
{
    // Sort processes based on arrival time using bubble sort
    bubbleSort(processes, n);

    // Calculate Completion Time
    int currentTime = 0;
    int completed = 0;
    while (completed < n)
    {
        int minRemainingTime = MAX;
        int shortestIndex = -1;     //o stores the index of the process that has the shortest remaining time 
        for (int i = 0; i < n; i++)
        {
            if (processes[i].at <= currentTime && processes[i].rt < minRemainingTime && processes[i].rt > 0)
            {
                minRemainingTime = processes[i].rt;
                shortestIndex = i;
            }
        }
        if (shortestIndex == -1)
        {
            currentTime++;
        }
        else
        {
            processes[shortestIndex].rt--;
            currentTime++;
            if (processes[shortestIndex].rt == 0)
            {
                completed++;
                processes[shortestIndex].ct = currentTime;
            }
        }
    }
}

void calculateTurnAroundTime(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}

void calculateWaitingTime(struct Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

int main()
{
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter name of process %d: ", i);
        scanf("%s", processes[i].name);
        printf("Enter arrival time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].at);
        printf("Enter burst time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt;
    }
    calculateCompletionTime(processes, n);
    calculateTurnAroundTime(processes, n);
    calculateWaitingTime(processes, n);
    float avgTAT =0;
    float avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        avgTAT += processes[i].tat;
        avgWT += processes[i].wt;
    }
    avgTAT /= n;
    avgWT /= n;
    printf("\nAverage TAT: %.2f", avgTAT);
    printf("\nAverage WT: %.2f", avgWT);
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].at,
               processes[i].bt, processes[i].ct,
               processes[i].tat, processes[i].wt);
    }
    return 0;
}
 
