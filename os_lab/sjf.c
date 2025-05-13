#include <stdio.h>

#define MAX_PROCESSES 100

int main() {
    int n, i, j, smallest, temp, bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES], total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // SJF Scheduling (non-preemptive)
    for (i = 0; i < n; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[smallest]) {
                smallest = j;
            }
        }

        // Swap for sorting
        temp = bt[i];
        bt[i] = bt[smallest];
        bt[smallest] = temp;
    }

    // Calculate waiting time
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Calculate total waiting and turnaround times
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting and turnaround times
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
