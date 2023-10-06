#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char *argv[]){
int i;
int E = 100;

 if (( i = fork())==0) {
   printf(" Je suis le fils, mon PID : %d \n",getpid());  
   printf(" Je suis le fils,le PID de mon pere %d \n",getppid());
   E =  E + ;4
 //  printf(" Je suis le fils, j'ai fini E = %d \n", E);
 } else {
   printf(" Je suis le pere, mon PID  : %d d\n",getpid());
   printf(" Je suis le père, le PID de mon fils vaut : %d \n",i);
  // E = E + 4;
   printf(" Je suis le pere, j'ai fini E = %d  \n", E);
 } 
}