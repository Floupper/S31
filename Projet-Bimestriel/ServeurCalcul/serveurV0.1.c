#include <stdio.h>

// Déclaration d'un type Instruction
typedef int Instruction[6];

// La fonction qui exécute l'instruction
void execute_instruction(Instruction OP)
{
  switch (OP[0])
  {
  case 1:
    OP[3] = OP[1] + OP[2];
    break;
  case 2:
    OP[3] = OP[1] - OP[2];
    break;
  case 3:
    OP[3] = OP[1] * OP[2];
    break;
  case 4:
    if (OP[2] != 0)
      OP[3] = OP[1] / OP[2];
    break;
  case 5:
    OP[3] = OP[1] / OP[2];
    OP[4] = OP[1] % OP[2];
    break;
  }
}

// Le programme principal V0
int main(int argc, char *argv[])
{

  if (argc != 5)
  {
    printf(" Usage : %s codeOp arg1 arg2 flag  \n", argv[0]);
    return -1;
  }

  // Déclaration de l'instruction:
  Instruction PI = {1, 12, 7, 0, 0, 0};

  // Lecture du code alphanumérique et transformation en un entier qui sera mis dans PI[0]
  if (strcmp(argv[1], "add") == 0)
    PI[0] = 1;
  else if (strcmp(argv[1], "sub") == 0)
    PI[0] = 2;
  else if (strcmp(argv[1], "mul") == 0)
    PI[0] = 3;
  else if (strcmp(argv[1], "div") == 0)
    PI[0] = 4;
  else if (strcmp(argv[1], "divE") == 0)
    PI[0] = 5;
  else
  {
    printf(" !! Gasp !! Opération non reconnue : %s \n", argv[1]);
    return 0;
  }

  // Lecture des arguments de l'instruction
  PI[1] = atoi(argv[2]);
  PI[2] = atoi(argv[3]);

  // Lecture du flag de l'instruction
  PI[5] = atoi(argv[4]);

  // Affichage de l'instruction :
  printf("A executer : | %d | %d | %d | %d | %d | %d |\n", PI[0], PI[1], PI[2], PI[3], PI[4], PI[5]);
  // Exécution de l'instruction :
  execute_instruction(PI);
  // Affichage du résultat :
  printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", PI[0], PI[1], PI[2], PI[3], PI[4], PI[5]);
}
