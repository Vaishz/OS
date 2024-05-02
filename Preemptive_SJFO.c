#include <stdio.h>

int finish[10], process_name[10], arrival_time[10], burst_time[10], waiting_time[10], turn_around_time[10];
int n, pending, remain_burst_time[10], time=0, count;

void input() {
    int i;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        process_name[i] = i;
        printf("\nEnter Burst Time of Process %d: ", process_name[i]);
        scanf("%d", &burst_time[i]);
        remain_burst_time[i] = burst_time[i];
        printf("\nEnter arrival time of Process %d: ", process_name[i]);
        scanf("%d", &arrival_time[i]);
    }
}

void output() {
    int i;
    printf("\n\nProcess A.T. B.T. W.T. T.A.T");
    for (i = 0; i < n; i++) {
        printf("\n P%d \t%d \t%d \t%d \t%d", process_name[i], arrival_time[i], burst_time[i], waiting_time[i], turn_around_time[i]);
    }
}

void sort() {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (burst_time[i] < burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = remain_burst_time[i];
                remain_burst_time[i] = remain_burst_time[j];
                remain_burst_time[j] = temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = waiting_time[i];
                waiting_time[i] = waiting_time[j];
                waiting_time[j] = temp;

                temp = process_name[i];
                process_name[i] = process_name[j];
                process_name[j] = temp;

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;
            }
        }
    }
}

void sjf_preempt() {
    int i;
    input();
    pending = n;
    printf("\n\nGantt Chart==> ");
    for (i = 0; i < n; i++) {
        finish[i] = 0;
        waiting_time[i] = 0;
    }
    for (time = 0, count = 0; pending > 0;) {
        sort();
        for (count = 0; count < n; count++) {
            if (finish[count] != 1 && arrival_time[count] <= time) { //here time means current time
                printf("P%d ", process_name[count]);
                time += 1;
                remain_burst_time[count] -= 1;
                for (i = 0; i < n; i++) {
                    if (i == count || finish[i] == 1)
                        continue;
                    waiting_time[i] += 1;
                }
                if (remain_burst_time[count] == 0) {
                    pending--;
                    finish[count] = 1;
                    waiting_time[count] -= arrival_time[count];
                    turn_around_time[count] = waiting_time[count] + burst_time[count];
                }
                break;
            }
        }
    }
    output();
}

int main() {
    sjf_preempt();
    return 0;
}
