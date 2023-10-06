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

typedef struct opServ
{   
    pid_t pid;
    key_t op_key;
    int shmid;
    Instruction *shared_memory;
}opServ;

// Nombre maximal d'instruction dans le tableau
#define MaxI 10

// La fonction qui exécute l'instruction
void fill_shared_memory(Instruction OP, Instruction *shared_memory){
    for (size_t i = 0; i < 4; i++)
    {
        *shared_memory[i] = OP[i];
    }
    
}
void execute_instruction(Instruction TP,opServ serv)
{   
    fill_shared_memory(TP, serv.shared_memory);
    sleep(1);
    kill(serv.pid,SIGUSR1);
}

void fill_serv(opServ *serv,key_t key, char *serv_name){
    
    serv->op_key = key;
    serv->shmid = shmget(serv->op_key,sizeof(Instruction),IPC_CREAT | 0666 );
    serv->shared_memory = (Instruction *)shmat(serv->shmid,NULL,0);

    int f;
    char path[1024];

    char *myCommand[10];
    myCommand[0] = "";
    myCommand[1] = NULL;

    strcpy(path, "/home/xeragon/Bureau/BUT_S3/S31/projet/serverV2/");
    strcat(path, serv_name);

    if((f = fork()) == 0){
        execv(path,myCommand);
    }
    else{
       serv->pid = f;
    }
    
}

// Le programme principal V0
int main()
{

    int i = 0;

    opServ addServ;
    fill_serv(&addServ,1,"addServ");

    opServ subServ;
    fill_serv(&subServ,2,"subServ");

    opServ multServ;
    fill_serv(&multServ,3,"multServ");

    opServ divServ;
    fill_serv(&divServ,4,"divServ");

    opServ rdivServ;
    fill_serv(&rdivServ,5,"rdivServ");

    // Déclaration d'un tableau d'instructions TPI
    Instruction TPI[MaxI + 1]; // c'est donc un tableau de 10 instructions +1 pour marqué par code opération -1

    TPI[0][0] = 1; TPI[0][1] = 12; TPI[0][2] = 7; TPI[0][3] = 0; TPI[0][4] = 0; TPI[0][5] = 0; // add 12 7 0
    TPI[1][0] = 2; TPI[1][1] = 36; TPI[1][2] = 8; TPI[0][3] = 0; TPI[1][4] = 0; TPI[1][5] = 0; //  sub 36 8 0
    TPI[2][0] = 5; TPI[2][1] = 19; TPI[2][2] = 6; TPI[2][3] = 0; TPI[2][4] = 0; TPI[2][5] = 0; //  divE 19 6 0
    TPI[3][0] = -1;


    while ((TPI[i][0] != -1) && (i < MaxI))
    {
        // printf("A executer : | %d | %d | %d | %d | %d | %d |  \n", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);

        if(TPI[i][0] == 1)
        {
            execute_instruction(TPI[i],addServ);
        }
        else if(TPI[i][0] == 2){
            execute_instruction(TPI[i],subServ);
        }
        else if(TPI[i][0] == 3){
            execute_instruction(TPI[i],multServ);
        }
        else if(TPI[i][0] == 4){
            execute_instruction(TPI[i],divServ);
        }
        else if(TPI[i][0] == 5){
            execute_instruction(TPI[i],rdivServ);
        }

        i++;
    }
}
