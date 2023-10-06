#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void frecu(int sigrecu) {
 printf(" La fonction freçu a été appelée à la réception du signal %d\n", sigrecu);

}
int main(int argc, char *argv[]){

  struct sigaction new_action;
  new_action.sa_handler = frecu ;
  sigaction (SIGUSR1, &new_action, NULL);

// Mise en attente du signal
  pause(); 
}
