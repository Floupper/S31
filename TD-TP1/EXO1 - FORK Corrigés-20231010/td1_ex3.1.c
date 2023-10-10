#include <stdio.h>
#include <string.h>
 #include <unistd.h>

int main(int argc, char *argv[]){

 const *char = "ls"

 char * myCommand[5];
 myCommand[0] = "ls"];
 myCommand[1] = "-l";
 myCommand[2] = NULL;
    
	printf("Commande a executer : %s  %s %s\n", myCommand[0], myCommand[1], myCommand[2]);
	
	 execv(myCommand[0], myCommand);
}
