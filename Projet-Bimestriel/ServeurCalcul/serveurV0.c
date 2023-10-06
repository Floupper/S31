#include <stdio.h>
#include <stdlib.h>

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
int main()
{
  // Déclaration de l'instruction précédente "add 12 7":
  Instruction PI = {1, 12, 7, 0, 0, 0};
  // Affichage de l'instruction :
  printf("add 12 7 : | %d | %d | %d | %d | %d | %d |\n", PI[0], PI[1], PI[2], PI[3], PI[4], PI[5]);
  // Exécution de l'instruction :
  execute_instruction(PI);
  // Affichage du résultat :
  printf("Résultat : | %d | %d | %d | %d | %d | %d |\n", PI[0], PI[1], PI[2], PI[3], PI[4], PI[5]);
}
