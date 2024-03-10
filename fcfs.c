#include <stdio.h>

int main()
{
    int pid[15];
    int bt[15];
    int n;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter ID of all process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter the Burst Time of all process: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    int wt[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("%-20s %-20s %-20s %-20s\n", "Process ID", "Burst Time", "Waiting Time", "Turnaround Time");
    float twt = 0, tat = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%-20d %-20d %-20d %-20d\n", pid[i], bt[i], wt[i], bt[i] + wt[i]);
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    float awt, att;
    att = tat / n;
    awt = twt / n;
    printf("\nThe Average Wait Time = %f", awt);
    printf("\nThe Average Turnaround Time = %f\n", att);
}
