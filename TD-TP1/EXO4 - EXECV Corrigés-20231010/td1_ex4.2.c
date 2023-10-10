#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

 int i = 0, fg = 0, status;
 char * myCommand[10];

for(i = 0; i<argc ; i++) { 
	if(argv[i][0] ==(char)'&') { fg = 1; 
         } else { myCommand[i] = argv[i+1];}
 }
 myCommand[i] = NULL;
    
 printf("Commande a executer : %s %s %s\n", myCommand[0], myCommand[1], myCommand[2] );
 
 if (fork() != 0)  { sleep(4); execv(myCommand[0], myCommand);}
 else {
          if(fg == 1) { wait(&status); printf(" Commande terminée après &\n"); }
          else  printf(" Commande terminée directemet\n"); 
 }
}
