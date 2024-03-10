#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, m;
    printf("Enter number of processes and memory:\n");
    scanf("%d %d", &n, &m);
    int psize[n], msize[m], internalfrag[m], pn[n];
    bool flag[m];
    printf("Enter size of processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &psize[i]);
    }

    printf("Enter size of memory:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &msize[i]);
        flag[i] = 0;
        internalfrag[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (psize[i] <= msize[j] && flag[j] == 0)
            {
                flag[j] = 1;
                pn[j] = i;
                internalfrag[j] = msize[j] - psize[i];
                break;
            }
        }
    }

    printf("%-20s %-20s %-20s\n", "Memory", "Process", "Internal Fragmentation");
    int totalInternalFrag = 0;

    for (int i = 0; i < m; i++)
    {
        if (flag[i] == 1)
        {
            printf("%-20d %-20d %-20d\n", msize[i], psize[pn[i]], internalfrag[i]);
            totalInternalFrag += internalfrag[i];
        }
        else
        {
            printf("%-20d %-30s\n", msize[i], "----------Memory Not Allocated----------");
        }
    }
    printf("\nTotal Internal Fragmentation: %d\n", totalInternalFrag);
    return 0;
}
