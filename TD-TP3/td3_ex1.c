// Les includes normaux
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <string.h>
#include <pthread.h>

int glob =3; 

static void *tache (void *argA) {  
   glob ++;
   printf ("argA : (%s) glob : %d\n",(char *)argA,glob); 
    // Affichage des informations sur le thread 
   printf ("argA : (%s) pthread_pid : %d pid : %d \n",(char *)argA,(int)pthread_self(), getpid()); 
  return NULL;
}

int main(int argc, char *argv[]){
  
  pthread_t ta = 0, tb = 0;

	pthread_create (&ta, NULL, tache, (void *)"A");
	pthread_create (&tb, NULL, tache, (void *)"B");
 	pthread_join(ta, NULL);
	pthread_join(tb, NULL);
	glob++;
  printf ("Pere (%d) %d \n", getpid(), glob );
}

