#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[1000]; // Taille maximale de la chaîne

    pipe(fd);

    // Création du processus fils
    pid = fork();

    if (pid == 0)
    {
        // Processus fils

        // Fermer l'extrémité de lecture du tube
        close(fd[0]);

        printf("Entrez une chaîne de caractères : ");
        fgets(message, sizeof(message), stdin);

        // Écrire la chaîne dans le tube
        write(fd[1], message, strlen(message));

        // Fermer l'extrémité d'écriture du tube
        close(fd[1]);
    }
    else
    {
        // Processus parent

        // Fermer l'extrémité d'écriture du tube
        close(fd[1]);

        // Lire la chaîne depuis le tube
        int bytesRead = read(fd[0], message, sizeof(message) - 1);
        if (bytesRead >= 0)
        {
            message[bytesRead] = '\0'; // Ajouter le caractère nul de fin de chaîne
            printf("Le processus fils a envoyé : %s", message);
        }

        // Fermer l'extrémité de lecture du tube
        close(fd[0]);
    }

    return 0;
}
