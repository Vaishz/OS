#include <stdio.h>
#include <math.h>
#define SIZE 8
void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int cur_track, distance;
    for (int i = 0; i < SIZE; i++)
    {
        cur_track = arr[i];
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total number of seek operations: %d\n", seek_count);
    printf("Seek Sequence is\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
}
// Driver code
int main()
{
    // request array
    int arr[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    printf("---------- FCFS DISK SCHEDULING ----------\n\n");
    FCFS(arr, head);
    return 0;
}