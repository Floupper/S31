#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
 int i;
 int p = getpid();
 i = fork();
 if ( i == 0) {
  printf(" Je suis le fils, mon PID : %d, mon créateur : %d, mon pere %d\n", getpid(), p, getppid());
 } else {
   sleep(3);
   printf(" Je suis le pere, mon PID vaut : %d et celui de mon fils %d\n", getpid(),i);
 } 
}
