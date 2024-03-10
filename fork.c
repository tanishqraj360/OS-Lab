#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Hello from Child\n");
        printf("Child Process Id: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());

        char *args[] = {"ls", "-l", "/home/tanishqraj360/Projects", NULL};

        execvp("ls", args);
    }
    else
    {
        wait(NULL);
        printf("Hello from Parent\n");
        printf("Parent Process ID %d", getpid());
    }

    return 0;
}
