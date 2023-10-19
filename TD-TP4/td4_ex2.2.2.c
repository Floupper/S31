#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

// #include <fcntl.h>

int main(int argc, char *argv[])
{

    int fd[2]; // Pipe entre le père et le fils

    // Création du pipe
    pipe(fd);
    if (fork() == 0)
    {
        write(fd[1], &argv[1], 1);
        printf("Caractère écrit par le fils : %s \n", argv[1]);
    }
    else
    {
        read(fd[0], &argv[1], 1);
        printf("Caractère lu par le père : %s \n", argv[1]);
    }
}