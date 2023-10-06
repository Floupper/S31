#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    int pid=atoi(argv[1]);
    int signal=atoi(argv[2]);
    kill(pid, signal);
}