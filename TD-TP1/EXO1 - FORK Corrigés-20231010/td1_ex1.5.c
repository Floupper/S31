#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){


for(int n = 0; n<6, n++) {
  if (( i = fork()) == 0) {
   printf(" Je suis le fils, mon PID : %d \n",getpid());  
   printf(" Je suis le fils,le PID de mon pere %d \n",getppid());
 //  printf(" Je suis le fils, j'ai fini \n");
  } else {
   printf(" Je suis le pere, mon PID  : %d d\n",getpid());
   printf(" Je suis le père, le PID du fils créé vaut : %d \n",i);
   printf(" Je suis le pere, j'ai fini \n");
 } 
}
}
