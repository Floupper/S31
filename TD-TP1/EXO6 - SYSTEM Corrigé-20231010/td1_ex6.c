#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

  if (argc != 3) {
    printf(" Usage : %s commande_linux M N \n", argv[0]); 
    return -1;
  }

 char  myCommand[100];
 strcat(myCommand,"./multifork");
 strcat(myCommand," ");
 strcat(myCommand,  argv[1]);
 strcat(myCommand," ");
 strcat(myCommand,  argv[2]);
    
 printf("Commande a exécuter : %s \n", myCommand);
 system(myCommand);
}
