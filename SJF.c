#include <stdio.h>
    int n, i, j, pos, temp, choice, BT[20], WT[20], TAT[20], process[20], total=0;
    float avgtat=0, avgwt=0;
int SJF()
{
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[pos])
                pos=j;
        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
        WT[0]=0;
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
            WT[i]+=BT[j];
        total+=WT[i];
    }
    avgwt=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
        total+=TAT[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",process[i],BT[i],WT[i],TAT[i]);
    }
    avgtat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avgwt);
    printf("\nAverage Turnaround Time=%f\n",avgtat);
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
    printf("SJF Scheduling\n");
    SJF();
}
