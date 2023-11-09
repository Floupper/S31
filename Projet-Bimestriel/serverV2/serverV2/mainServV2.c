#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

// Déclaration d'un type Instruction
typedef int Instruction[6];

typedef struct opServ
{   pid_t pid;
    int fd;
} opServ;

// Nombre maximal d'instruction dans le tableau
#define MaxI 10

// La fonction qui exécute l'instruction
void fill_shared_memory(Instruction OP, opServ serv){
    write(serv.fd, OP, sizeof(int) * 6);
}

void execute_instruction(Instruction TP, opServ serv){
    fill_shared_memory(TP, serv);
    usleep(10000);
    kill(serv.pid, SIGUSR1);
}

void fill_serv(opServ *serv, char *serv_name){

    char pipe_path[100];
    sprintf(pipe_path, "./%s.pipe", serv_name);

    if (mkfifo(pipe_path,  O_CREAT | S_IWUSR | S_IRUSR) == -1) {
        if (errno == EEXIST) {}
        else {
            perror("Création du fichier de pipe nommé");
            exit(errno);
        }
    };

    int f;
    char path[1024];
    // printf("1\n");

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
    serv->fd = open(pipe_path, O_WRONLY);

    if (serv->fd == -1) {
        perror("Error opening the named pipe");
        exit(errno);
    }
}

// Le programme principal V0
int main()
{
    int i = 0;
    
    opServ addServ;
    fill_serv(&addServ, "addServ");
    
    opServ subServ;
    fill_serv(&subServ, "subServ");

    opServ multServ;
    fill_serv(&multServ, "multServ");

    opServ divServ;
    fill_serv(&divServ, "divServ");

    opServ rdivServ;
    fill_serv(&rdivServ, "rdivServ");

    // // Déclaration d'un tableau d'instructions TPI
    Instruction TPI[MaxI + 1]; // c'est donc un tableau de 10 instructions +1 pour marquer par code opération -1

    TPI[0][0] = 1; TPI[0][1] = 12; TPI[0][2] = 7; TPI[0][3] = 0; TPI[0][4] = 0; TPI[0][5] = 0; // add 12 7 0
    TPI[1][0] = 2; TPI[1][1] = 36; TPI[1][2] = 8; TPI[0][3] = 0; TPI[1][4] = 0; TPI[1][5] = 0; //  sub 36 8 0
    TPI[2][0] = 5; TPI[2][1] = 19; TPI[2][2] = 6; TPI[2][3] = 0; TPI[2][4] = 0; TPI[2][5] = 0; //  divE 19 6 0
    TPI[3][0] = -1;

    while ((TPI[i][0] != -1) && (i < MaxI))
    {

        printf("A executer : | %d | %d | %d | %d | %d | %d |  ", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);
        usleep(10000);
        fflush(stdout);
        if (TPI[i][0] == 1)
        {
            execute_instruction(TPI[i], addServ);
        }
        else if (TPI[i][0] == 2) {
            execute_instruction(TPI[i], subServ);
        }
        else if (TPI[i][0] == 3) {
            execute_instruction(TPI[i], multServ);
        }
        else if (TPI[i][0] == 4) {
            execute_instruction(TPI[i], divServ);
        }
        else if (TPI[i][0] == 5) {
            execute_instruction(TPI[i], rdivServ);
        }
        i++;
    }
}
