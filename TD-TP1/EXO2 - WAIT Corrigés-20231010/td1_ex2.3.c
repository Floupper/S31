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
       exit(42+n);
    } else {
     printf(" Je suis le pere, mon PID  : %d  PID du fils n = %d créé --> %d  \n",getpid(),n,i);
     if (n%2) { kidpid = wait(&status);
                     printf(" === Père se reveille  Mort de mon fils  PID : %d Status (1 : normal) %d valeur de retour du fils : %d \n", kidpid,WIFEXITED(status), WEXITSTATUS(status)); }
   } 
  } 
   printf(" ++++++++++ Je suis le pere, je verifie la mort de tous mes fils  +++++++++++ \n");
    i = 3;      
    do {
          while ((kidpid = waitpid(-1, &status, WNOHANG)) > 0) { 
              printf(" Je suis le père et je me reveille suite à la mort de mon fils %d  : terminaison (1: normal) %d valeur de retour du fils : %d \n",  kidpid,WIFEXITED(status), WEXITSTATUS(status));
              i--;
         }
    } while (i != 0);
    printf(" Je suis le père : Termine \n");
}
