#include <stdio.h>

// Déclaration d'un type Instruction
typedef int Instruction[6];

// Nombre maximal d'instruction dans le tableau
#define MaxI 10

// La fonction qui exécute l'instruction
void execute_instruction(Instruction OP)
{
    switch (OP[0])
    {
    case 1:
        OP[3] = OP[1] + OP[2];
        break;
    case 2:
        OP[3] = OP[1] - OP[2];
        break;
    case 3:
        OP[3] = OP[1] * OP[2];
        break;
    case 4:
        if (OP[2] != 0)
            OP[3] = OP[1] / OP[2];
        break;
    case 5:
        OP[3] = OP[1] / OP[2];
        OP[4] = OP[1] % OP[2];
        break;
    }
}
// Le programme principal V0
int main()
{

    // Déclaration d'un tableau d'instructions (max 10)
    Instruction TPI[11]; // c'est donc un tableau de tableaux

    TPI[0][0] = 1;
    TPI[0][1] = 12;
    TPI[0][2] = 7;
    TPI[0][3] = 0;
    TPI[0][4] = 0;
    TPI[0][5] = 0; // add 12 7 0
    TPI[1][0] = 2;
    TPI[1][1] = 36;
    TPI[1][2] = 8;
    TPI[0][3] = 0;
    TPI[1][4] = 0;
    TPI[1][5] = 0; //  sub 36 8 0
    TPI[2][0] = 5;
    TPI[2][1] = 19;
    TPI[2][2] = 6;
    TPI[2][3] = 0;
    TPI[2][4] = 0;
    TPI[2][5] = 0; //  divE 19 6 0
    TPI[3][0] = 4;
    TPI[3][1] = 13;
    TPI[3][2] = 2;
    TPI[3][3] = 0;
    TPI[3][4] = 0;
    TPI[3][5] = 0; //  div 13 2 0
    TPI[4][0] = 5;
    TPI[4][1] = 13;
    TPI[4][2] = 3;
    TPI[4][3] = 0;
    TPI[4][4] = 0;
    TPI[4][5] = 0; //  divE 13 3 0
    TPI[5][0] = 1;
    TPI[5][1] = 68;
    TPI[5][2] = 4;
    TPI[5][3] = 0;
    TPI[5][4] = 0;
    TPI[5][5] = 0; //  add 68 4 0

    /* On note la fin de la liste par un codeOp de -1 */

    TPI[3][0] = -1;

    int i = 0;
    while ((TPI[i][0] != -1) && (i < MaxI))
    {
        // Affichage de l'instruction :
        printf("A executer : | %d | %d | %d | %d | %d | %d |  ", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);
        // Exécution de l'instruction :
        execute_instruction(TPI[i]);
        // Affichage du résultat :
        printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);
        i++;
    }
}
