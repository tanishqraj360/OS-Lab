#include <stdio.h>

struct sjf
{
    int bt;
    int pid;
};

int main()
{
    int n;

    printf("Enter number of Processes: ");
    scanf("%d", &n);

    struct sjf s[n];
    printf("Enter Process ID:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].pid);
    }

    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].bt);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j].bt > s[j + 1].bt)
            {
                struct sjf temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    int wt[n], twt = 0, tat = 0;
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = s[i - 1].bt + wt[i - 1];
    }

    printf("%-20s %-20s %-20s %-20s\n", "Process ID", "Burst Time", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < n; i++)
    {
        printf("%-20d %-20d %-20d %-20d\n", s[i].pid, s[i].bt, wt[i], wt[i] + s[i].bt);
        twt += wt[i];
        tat += (wt[i] + s[i].bt);
    }

    float att, awt;
    awt = twt / n;
    att = tat / n;
    printf("\nThe Average Wait Time = %f", awt);
    printf("\nThe Average Turnaround Time = %f", att);

    return 0;
}
