#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter number of pages and frame size: ");
    scanf("%d %d", &n, &m);

    int pages[n], frames[m], nextFrame = 0, pageFault = 0;

    printf("Enter page size: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < m; i++)
    {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {

        printf("Referencing page %d...\n", pages[i]);
        int pageFound = 0;

        for (int j = 0; j < m; j++)
        {
            if (frames[j] == pages[i])
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            frames[nextFrame] = pages[i];
            nextFrame = (nextFrame + 1) % m;
            pageFault++;
            printf("Page Fault occured!\n");
        }
        else
        {
            printf("Page Hit!\n");
        }

        printf("Frames: ");
        for (int j = 0; j < m; j++)
        {
            if (frames[j] == -1)
            {
                printf("[ ]");
            }
            else
            {
                printf("[%d]", frames[j]);
            }
        }
        printf("\n\n");
    }

    printf("Total Page Faults: %d", pageFault);
    return 0;
}
