#include "calculatrice.h"
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

int status;

  if ( fork() == 0) {
     sleep(3);
   printf(" Je suis le fils (%d) et j'attend 4 secondes \n ", getpid());
     sleep(4);
     printf("==> FIN DU FILS\n");
     exit(10); } 
 else { 
   printf(" Je suis le pere (%d) et je me met en attente\n ", getpid());
   wait(&status);
   printf(" Je suis le père et je me reveille suite à la mort de mon fils %d valeur de retour du fils : %d \n", WIFEXITED(status), WEXITSTATUS(status));
  }
}
