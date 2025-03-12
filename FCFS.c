#include <stdio.h>
    int n, i, j, pos, temp, choice, BT[20], WT[20], TAT[20], process[20], total=0;
    float avgtat=0, avgwt=0;
int FCFS()
{
    WT[0]=0;
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
            WT[i]+=BT[j];
    }
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
        avgwt+=WT[i];
        avgtat+=TAT[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,BT[i],WT[i],TAT[i]);
    }
    avgwt =(float)(avgwt)/(float)i;
    avgtat=(float)(avgtat)/(float)i;
    printf("\nAverage Waiting Time:%.2f",avgwt);
    printf("\nAverage Turnaround Time:%.2f\n",avgtat);
    return 0;
}
int main()
{
    printf("Enter the total number of processes:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&BT[i]);
        process[i]=i+1;
    }
    printf("FCFS Scheduling\n");
    FCFS();
}
