#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

// #include <fcntl.h>

int main(int argc, char *argv[])
{

    char c[100];
    for (int i = 1; i < argc; i++)
    {
        c[i] = argv[i];
    }

    int fd[2]; // Pipe entre le père et le fils

    // Création du pipe
    pipe(fd);
    if (fork() == 0)
    {
        write(fd[1], &c, 1);
        printf("Caractère écrit par le fils : %s \n", c);
    }
    else
    {
        read(fd[0], &c, 1);
        printf("Caractère lu par le père : %s \n", c);
    }
}