#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void calcule(int OP[]) {
  switch (OP[0]) {
    case 1: OP[3] = OP[1] + OP[2]; break; 
    case 2: OP[3] = OP[1] - OP[2]; break;
    case 3: OP[3] = OP[1] * OP[2]; break;
    case 4: if (OP[2] !=0) OP[3] = OP[1] / (int) OP[2]; break;
    case 5: OP[3] = OP[1] / OP[2];
	    OP[4] = OP[1] % OP[2]; break;
  }
}

void SaisirOP(int OP[]) {
  printf(" Donnez le code opération - entre 1 et 5 \n");
  scanf("%d",&OP[0]);
  printf(" Donnez le premier argument \n");
  scanf("%d",&OP[1]);

  printf(" Donnez le deuxième argument \n");
  scanf("%d",&OP[2]);  

}

void AfficherOP(int OP[]) {
  printf(" Code opération %d  \n", OP[0]);
  printf(" Arguments  %d %d \n", OP[1], OP[2]); 
  printf(" Résultat  %d %d \n", OP[3], OP[4]);
}

/* Le main */

int main(int argc, char *argv[]){
  // Déclaration et création d'un template d'instruction 
 int myOP[5] = { 0, 0, 0, 0, 0};

// Test paramètres
  if (argc != 4) {
    printf(" Usage : %s codeOp arg1 arg2 \n",argv[0]); 
    return -1;
  }
 
 // Initialisation de l'instruction
  myOP[0] = atoi(argv[1]);
  myOP[1] = atoi(argv[2]);
  myOP[2] = atoi(argv[3]);  



int status;

  if ( fork() == 0) {
     sleep(1);
     printf(" Je suis le fils (%d) et je réalise l'opération\n ", getpid());
     AfficherOP(myOP) ;
     calcule(myOP);
     printf("==> Dans le fils Res : %d %d\n", myOP[3],  myOP[4]);
     exit(10);
 } else {
   printf(" Je suis le pere (%d) et je me met en attente\n ", getpid());
   wait(&status);
   printf(" Je suis le père et je me reveille suite à la mort de mon fils %d valeur de retour du fils : %d \n", WIFEXITED(status), WEXITSTATUS(status));
 }
}