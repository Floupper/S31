#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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
typedef int Instruction[6];
int fd;
void Frecu(int S){
    // printf("Signal reçu %d \n",S);
    Instruction current;
    

    read(fd,current,sizeof(int)*6);
    current[3] = current[1] * current[2];
    printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", current[0], current[1], current[2], current[3], current[4], current[5]);
    pause();
}


int main(int argc, char const *argv[])
{
    struct sigaction new_action;
    new_action.sa_handler = Frecu;
    sigaction(SIGUSR1,&new_action,NULL);
    // while (1){}
    if (mkfifo("./multServ.pipe", O_CREAT | S_IWUSR | S_IRUSR)==-1) {
    if(errno == EEXIST) {}
    else{perror("Création du fichier de pipe nommé"); exit(errno);}};
    fd = open("./multServ.pipe",O_RDONLY);
    pause();
    // sleep(10000);
    return 0;
}