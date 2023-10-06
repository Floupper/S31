#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

// Déclaration d'un type Instruction
typedef int Instruction[6];

// Nombre maximal d'instruction dans le tableau
#define MaxI 10

// La fonction qui exécute l'instruction
void fill_shared_memory(Instruction OP, Instruction *shared_memory)
{
    for (size_t i = 0; i < 4; i++)
    {
        *shared_memory[i] = OP[i];
    }
}
void execute_instruction(Instruction TP, pid_t serv_pid, Instruction *shared_memory)
{
    fill_shared_memory(TP, shared_memory);
    sleep(1);
    kill(serv_pid, SIGUSR1);
}

// Le programme principal V0
int main()
{

    int i = 0;
    int f;
    char *myCommand[10];
    myCommand[0] = "";
    myCommand[1] = NULL;

    pid_t add_pid;
    int shmid_add;
    key_t key_add = 1;
    Instruction *shared_memory_add;
    shmid_add = shmget(key_add, sizeof(Instruction), IPC_CREAT | 0666);
    shared_memory_add = (Instruction *)shmat(shmid_add, NULL, 0);

    if ((f = fork()) == 0)
    {
        execv("/mnt/c/Users/acker/OneDrive/Bureau/BUT2/S31-Systemes_exploitation_1erePartie/Projet-Bimestriel/serverV2/addServ", myCommand);
    }
    else
    {
        add_pid = f;
    }

    pid_t sub_pid;
    int shmid_sub;
    key_t key_sub = 2;
    Instruction *shared_memory_sub;
    shmid_sub = shmget(key_sub, sizeof(Instruction), IPC_CREAT | 0666);
    shared_memory_sub = (Instruction *)shmat(shmid_sub, NULL, 0);

    if ((f = fork()) == 0)
    {
        execv("/mnt/c/Users/acker/OneDrive/Bureau/BUT2/S31-Systemes_exploitation_1erePartie/Projet-Bimestriel/serverV2/subServ", myCommand);
    }
    else
    {
        sub_pid = f;
    }

    // Déclaration d'un tableau d'instructions TPI
    Instruction TPI[MaxI + 1]; // c'est donc un tableau de 10 instructions +1 pour marqué par code opération -1

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

    // TPI[2][0] = 5; TPI[2][1] = 19; TPI[2][2] = 6; TPI[2][3] = 0; TPI[2][4] = 0; TPI[2][5] = 0; //  divE 19 6 0

    /* etc. div 13 2 0; divE 13 3 0 ; add 68 4 0 */

    /* On note la fin de la liste par un codeOp de -1 */
    TPI[2][0] = -1;

    while ((TPI[i][0] != -1) && (i < MaxI))
    {
        pid_t serv_pid = 0;
        // Affichage de l'instruction :
        printf("A executer : | %d | %d | %d | %d | %d | %d |  \n", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);

        if (TPI[i][0] == 1)
        {
            // fill_shared_memory(TPI[i], shared_memory_add);
            // serv_pid = add_pid;
            // printf("add pid : %d\n", add_pid);
            // sleep(1);
            // kill(add_pid,10);
            execute_instruction(TPI[i], add_pid, shared_memory_add);
        }
        else if (TPI[i][0] == 2)
        {
            execute_instruction(TPI[i], sub_pid, shared_memory_sub);
        }

        i++;
    }
}
