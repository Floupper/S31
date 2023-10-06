#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
// #include "addServeur.c"
// #include "subServeur.c"

typedef int Instruction[6];
#define MaxI 10

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

int main()
{
    Instruction TPI[MaxI + 1];

    // Initialisation des instructions (comme dans votre exemple)
    TPI[0][0] = 1;
    TPI[0][1] = 12;
    TPI[0][2] = 7;
    TPI[0][3] = 0;
    TPI[0][4] = 0;
    TPI[0][5] = 0; // add 12 7 0

    TPI[1][0] = 2;
    TPI[1][1] = 36;
    TPI[1][2] = 8;
    TPI[1][3] = 0;
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
    TPI[3][5] = 1; // div 13 2 1

    TPI[4][0] = 5;
    TPI[4][1] = 13;
    TPI[4][2] = 3;
    TPI[4][3] = 0;
    TPI[4][4] = 0;
    TPI[4][5] = 1; // divE 13 3 1

    TPI[5][0] = 1;
    TPI[5][1] = 68;
    TPI[5][2] = 4;
    TPI[5][3] = 0;
    TPI[5][4] = 0;
    TPI[5][5] = 0; // add 68 4 0

    /* On note la fin de la liste par un codeOp de -1 */
    TPI[2][0] = -1;

    int i = 0;
    int status;

    while ((TPI[i][0] != -1) && (i < MaxI))
    {
        if (TPI[i][0] >= 1 && TPI[i][0] <= 5)
        {
            char operation_str[20];
            char operation_str_file[20];
            switch (TPI[i][0])
            {
            case 1:
                strcpy(operation_str, "addServeur");
                strcpy(operation_str_file, "addServeur.c");
                break;
            case 2:
                strcpy(operation_str, "subServeur");
                strcpy(operation_str_file, "subServeur.c");
                break;
            case 3:
                strcpy(operation_str, "mul");
                strcpy(operation_str_file, "mulServeur.c");
                break;
            case 4:
                strcpy(operation_str, "div");
                strcpy(operation_str_file, "divServeur.c");
                break;
            case 5:
                strcpy(operation_str, "divE");
                strcpy(operation_str_file, "divEServeur.c");
                break;
            }

            int arg1 = TPI[i][1];
            int arg2 = TPI[i][2];

            int flag;
            flag = TPI[i][5];

            int f;
            if ((f = fork()) == 0)
            {
                execlp(operation_str_file, operation_str, arg1, arg2, flag, NULL);
                fprintf(stderr, "Erreur lors du lancement de %s\n", operation_str);
                exit(1);
            }
            else
            {
                if (TPI[i][5] == 0)
                {
                    waitpid(f, &status, WNOHANG);
                }
                else if (TPI[i][5] == 1)
                {
                    waitpid(f, &status, 0);
                }
            }
        }
        else
        {
            fprintf(stderr, "Code opération non reconnu : %d\n", TPI[i][0]);
        }

        i++;
    }

    return 0;
}
