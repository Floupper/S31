#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Déclaration d'un type Instruction 
typedef int Instruction[6] ;

int main(int argc, char * argv[]) {
  if (argc != 5) {
    printf(" Usage : %s codeOp arg1 arg2 flag  \n", argv[0]); 
    return -1;
  }

Instruction PI = {5, 0, 0, 0,0};

// Lecture du code de l'instruction
if ( (strcmp(argv[1], "5") != 0) && (strcmp(argv[1], "divE") != 0)) { printf(" !! Gasp !! Dans divEService) Opération non reconnue : %s \n", argv[1]);     return 0; }

// Lecture des arguments de l'instruction
PI[1] = atoi(argv[2]);
PI[2] = atoi(argv[3]);

// Affichage de l'instruction :
  printf("Dans divEService) A executer : | %d | %d | %d | %d | %d | %d | ", PI[0],PI[1],PI[2],PI[3],PI[4],PI[5]);

   /**** Exécution de l'addition :  ***/
         PI[3] = PI[1] / PI[2]; PI[4] = PI[1]%PI[2]; 
  /************************************/

// Affichage du résultat :
  printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n",  PI[0],PI[1],PI[2],PI[3],PI[4],PI[5]);

}
