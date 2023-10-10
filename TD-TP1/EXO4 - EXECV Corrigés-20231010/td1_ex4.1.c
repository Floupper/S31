#include <stdio.h>
#include <string.h>
 #include <unistd.h>

int main(int argc, char *argv[]){

  int i = 0;
 char * myCommand[10];
 
 for(i = 0; i<argc ; i++) { printf(" Argv %d %s \n", i, argv[i]); myCommand[i] = argv[i+1];}
 myCommand[i] = NULL;
    
 printf("Commande a executer : %s %s %s\n", myCommand[0], myCommand[1], myCommand[2] );
 
 execv(myCommand[0], myCommand);
}
