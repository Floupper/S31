#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int i = 0, status, kidpid;
 for(int n = 0; n<6; n++) {
  if ((i = fork()) == 0) {
     printf(" Je suis le fils n : %d, mon PID : %d PID de mon pere %d \n",n,getpid(),getppid());
     exit(42);
  } else {
     printf(" Je suis le pere, mon PID  : %d  PID du fils n = %d créé --> %d  \n",getpid(),n,i);
      kidpid = wait(&status);
     printf(" === Père se reveille  Mort de mon fils  PID : %d Status (1 : normal) %d valeur de retour du fils : %d \n", kidpid, WIFEXITED(status), WEXITSTATUS(status));
   } 
 } 
 printf(" Je suis le pere, j'ai fini \n");
}
