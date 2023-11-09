#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "mesFonctionsV2A.c"

// Le programme principal V1
int main() {

 Instruction TPI[10];   // Déclaration d'un tableau d'instructions (max 10)

 int pidfils = 0; 
 int i = 0;

// Chargement des instructions 
  chargerProgramme(TPI);

//Exécution du programme

 while((TPI[i][0] >0)&&(i <MaxI)) {
    
     if( (pidfils = fork())!= 0) {
                  if (TPI[i][5] == 1) { printf(" Pere mis en attente instruction num : %d pid : %d \n",i,pidfils);  waitpid(pidfils, NULL, 0); }
                  else {  printf(" Pere NON mis en attente instruction num : %d \n",i); }
     } else {
 	    // Exécution du service
       demandeService(i,TPI[i]);
       exit(-1); 
     } 
    i++; 
    }
 }
