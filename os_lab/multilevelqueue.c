#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], ct[20], at[20], queue[20];
    int n;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time %d: ", i + 1);
        scanf("%d", &bt[i]);
        at[i] = 0;
        printf("Enter Number (1 = Sys, 2 = User) for Pid %d: ", i + 1);
        scanf("%d", &queue[i]);
    }

    int current_time = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                int temp_bt = bt[i], temp_queue = queue[i], temp_at = at[i];
                bt[i] = bt[j];
                queue[i] = queue[j];
                at[i] = at[j];
                bt[j] = temp_bt;
                queue[j] = temp_queue;
                at[j] = temp_at;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }

        ct[i] = current_time + bt[i];
        wt[i] = ct[i] - bt[i] - at[i];
        tat[i] = wt[i] + bt[i];
        current_time = ct[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tQUEUE\tARRIVAL TIME\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%s\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], (queue[i] == 1 ? "System" : "User"), at[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}







