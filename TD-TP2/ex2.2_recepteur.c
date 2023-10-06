#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void frecu1(int sigrecu) {
 printf(" La fonction freçu1 a été appelée à la réception du signal %d\n", sigrecu);
}

void frecu2(int sigrecu) {
    printf("La fonction freçu2 a été appelée à la réception du signal %d\n", sigrecu);
}

void frecu3(int sigrecu) {
    printf("oui oui baguette\n");
}

int main(int argc, char *argv[]){

  struct sigaction new_action1;
  struct sigaction new_action2;
  struct sigaction new_action3;

  new_action1.sa_handler = frecu1 ;
  sigaction (SIGUSR1, &new_action1, NULL);
  new_action2.sa_handler = frecu2;
  sigaction(SIGUSR2, &new_action2, NULL);
  new_action3.sa_handler = frecu3;
  sigaction(SIGINT, &new_action3, NULL);

  // Mise en attente du signal
  pause(); 
}
