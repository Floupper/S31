#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    pid_t pid;
    int num;

    pipe(fd);

    // Création du processus fils
    pid = fork();

    if (pid == 0)
    {
        // Processus fils
        close(fd[0]);

        printf("Entrez un entier inférieur à 10^10 : ");
        scanf("%d", &num);

        // Écrire l'entier dans le tube
        write(fd[1], &num, sizeof(int));

        close(fd[1]);
    }
    else
    {
        // Processus parent
        close(fd[1]);

        // Lire l'entier depuis le tube
        read(fd[0], &num, sizeof(int));

        printf("Le processus fils a envoyé l'entier : %d\n", num);

        close(fd[0]);
    }

    return 0;
}
