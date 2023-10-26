#include "myIncludes.h"

void SaisirOP(int OP[])
{
    printf(" Donnez le code opération - entre 1 et 5 \n");
    scanf("%d", &OP[0]);
    printf(" Donnez le premier argument \n");
    scanf("%d", &OP[1]);

    printf(" Donnez le deuxième argument \n");
    scanf("%d", &OP[2]);
}

void AfficherOP(int OP[])
{
    printf(" Code opération %d  \n", OP[0]);
    printf(" Arguments  %d %d \n", OP[1], OP[2]);
    printf(" Résultat  %d %d \n", OP[3], OP[4]);
}