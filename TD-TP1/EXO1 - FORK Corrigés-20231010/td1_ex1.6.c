#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
 int  N,i=0;

  if (argc != 2) {
    printf(" Usage : %s  N \n", argv[0]); 
    return -1;
  }
  N = atoi(argv[1]);



for(; N>0; N--) {
  if (( i = fork()) == 0) {
   printf(" Je suis le fils N= %d, mon PID : %d  et celui de mon pere %d \n",N,getpid(),getppid());
   } else {
   sleep(N%3);
   printf(" ==== Je suis le pere N = %d, mon PID  : %d et  j'ai fini \n",N,getpid());
    exit(0);
 } 
}

}
