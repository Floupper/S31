#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>

int main(int argc, char *argv []) {

char c;
   ... fd[2];   // Pipe entre le père et le fils 

  // Création du pipe 
  pipe(...); 
  if (fork() == 0) {
    ...
    write( ... , ... , ...);
    printf("Caractère écrit par le fils : %c \n",c); }
  else {
    read( ... , ... , ... );
    printf("Caractère lu par le père : %c \n",c);
  }
}\