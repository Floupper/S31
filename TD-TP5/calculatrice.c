#include "myIncludes.h"

int main(int argc, char *argv[])
{
    // Déclaration et création d'un template d'instruction
    int myOP[5] = {0, 0, 0, 0, 0};

    // Test paramètres
    if (argc != 4)
    {
        printf(" Usage : %s codeOp arg1 arg2 \n", argv[0]);
        return -1;
    }

    // Initialisation de l'instruction
    myOP[0] = atoi(argv[1]);
    myOP[1] = atoi(argv[2]);
    myOP[2] = atoi(argv[3]);

    int status;

    if (fork() == 0)
    {
        sleep(1);
        printf(" Je suis le fils (%d) et je réalise l'opération\n ", getpid());
        AfficherOP(myOP);
        calcule(myOP);
        printf("==> Dans le fils Res : %d %d\n", myOP[3], myOP[4]);
        exit(10);
    }
    else
    {
        printf(" Je suis le pere (%d) et je me met en attente\n ", getpid());
        wait(&status);
        printf(" Je suis le père et je me reveille suite à la mort de mon fils %d valeur de retour du fils : %d \n", WIFEXITED(status), WEXITSTATUS(status));
    }
}