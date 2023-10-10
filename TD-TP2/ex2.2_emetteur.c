#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int pid = atoi(argv[1]);
    int signal_num = atoi(argv[2]);
    kill(pid, signal_num);

    int F1 = fork();
    int F2 = fork();

    if (F1 == 0)
    {
        // Child process F1
        kill(getpid(), SIGUSR1);
        signal(SIGUSR2, SIG_IGN);
    }
    else if (F2 == 0)
    {
        // Child process F2
        kill(getpid(), SIGUSR2);
        signal(SIGUSR1, SIG_IGN);
    }
    else
    {
        // Parent process
        printf("Parent process\n");
        pause();
    }
}