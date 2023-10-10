#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child process\n");
        exit(0);
    }
    else if (pid > 0)
    {
        // Parent process
        printf("Parent process\n");
        wait(NULL);
        printf("Child process has terminated\n");
    }
    else
    {
        // Error
        printf("Error forking process\n");
        exit(1);
    }

    return 0;
}