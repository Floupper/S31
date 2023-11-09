// Déclaration d'un type Instruction 
typedef int Instruction[6] ;

// Nombre maximal d'instructions dans le tableau
#define MaxI 10

void chargerProgramme(Instruction TPI[10]) {
 int i = 0;
  for(i = 0;i<MaxI;i++) 
       for(int j = 0; j<6;j++) TPI[i][j] = 0;

  TPI[0][0] = 1; TPI[0][1] = 12; TPI[0][2] = 7; TPI[0][3] = 0; TPI[0][4] = 0;TPI[0][5] = 1 ;        // add 12 7 0
  TPI[1][0] = 2; TPI[1][1] = 36; TPI[1][2] = 8; TPI[0][3] = 0; TPI[1][4] = 0; TPI[1][5] = 0 ;       //  sub 36 8 0
  TPI[2][0] = 5; TPI[2][1] = 19; TPI[2][2] = 6; TPI[2][3] = 0; TPI[2][4] = 0; TPI[2][5] = 0 ;       //  divE 19 6 0 
  TPI[3][0] = 4; TPI[3][1] = 13; TPI[3][2] = 2; TPI[3][3] = 0; TPI[3][4] = 0; TPI[3][5] = 1 ;       //  div 13 2 1
  TPI[4][0] = 5; TPI[4][1] = 13; TPI[4][2] = 3; TPI[4][3] = 0; TPI[4][4] = 0; TPI[4][5] = 1 ;       //  divE 13 3 1 
  TPI[5][0] = 1; TPI[5][1] = 68; TPI[5][2] = 4; TPI[5][3] = 0; TPI[5][4] = 0; TPI[5][5] = 0 ;       //  add 68 4 0
  TPI[6][0] = -1;


}

void demandeService(int i, Instruction TPI) {
      char * myCommand[6];
	   // Création de la demande de service :
       switch (TPI[0] ) {
   	 	case 1: 	 myCommand[0] = "addService" ; myCommand[1] = "add";  break;
   	 	case 2: 	 myCommand[0] = "subService" ; myCommand[1] = "sub";  break;
   	 	case 3: 	 myCommand[0] = "mulService" ; myCommand[1] = "mul";  break;
   	 	case 4: 	 myCommand[0] = "divService" ; myCommand[1] = "div";  break;
   	 	case 5: 	 myCommand[0] = "divEService" ;  ; myCommand[1] = "divE"; break;
   	 	default:  printf(" ======  Gasp !!  Instruction i : %d  codeOP %d inconnu ==== \n",i,TPI[0] ); exit(-1);
   	 }
   	 
     char arg1[100], arg2[100], flag[3];
      sprintf(arg1, "%d", TPI[1]);   myCommand[2] = arg1;
      sprintf(arg2, "%d", TPI[2]);   myCommand[3] = arg2; 
      sprintf(flag, "%d", TPI[3]);    myCommand[4] = flag; 
      myCommand[5] = NULL;

 	   printf(" \n\n ==============   Demande créée  -- instruction i : %d -- :  %s %s %s %s  =============\n\n",i,myCommand[0],myCommand[1],myCommand[2],myCommand[3]);
   // Exécution de la demande de service :
    execv(myCommand[0], myCommand);
    perror(" ======   Gasp !! Service non rendu "); 
	     printf("--> Defaut de service  - instruction i : %d -- pid serveur service = %d -- : %s %s %s %s %s  ======  \n",i, getpid(), myCommand[0], myCommand[1], myCommand[2], myCommand[3], myCommand[4]  );
}
