#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef int Instruction[6];

void Frecu(int S){
    // printf("Signal reçu %d \n",S);
    int shmid;
    key_t key = 3;
    Instruction *shared_memory;
    shmid = shmget(key, sizeof(Instruction), 0666);
    shared_memory = (Instruction *)shmat(shmid,NULL,0);

    *shared_memory[3] = *shared_memory[1] * *shared_memory[2];
    printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", *shared_memory[0], *shared_memory[1], *shared_memory[2], *shared_memory[3], *shared_memory[4], *shared_memory[5]);

}


int main(int argc, char const *argv[])
{
    struct sigaction new_action;
    new_action.sa_handler = Frecu;
    sigaction(SIGUSR1,&new_action,NULL);
    // while (1){}
    // pause();
    sleep(10000);
    return 0;
}