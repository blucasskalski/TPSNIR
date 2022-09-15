//
//  myshell3_suj.c
/* Prog support pour recréer un Shell avec gestion des redirections  */
/* Date : 9/21                                                       */
/* compilation par : gcc -Wall -o myshell3 myshell3_suj.c      */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#define N_ARGS 12

//Q1
//creation des 2 tblx de descripteurs
	int fd12[2];     //fils1 vers fils2   
	int fd21[2];	 //fils2 vers fils1 

/* descripteur des processus */
int pid1;
int pid2;

void fils1(char *s);
void fils2(char *s);

/* fonction de lecture des arguments du shell maison */
int read_arg(int fd, char* buffer, int size)
{
	int  nblus = 0;
	
    	nblus = read(0,buffer,size);
	if(nblus) buffer[nblus-1] = 0; //mets le finc de chaine
	return nblus;

}


int main(int argc, char **argv)
{

	/* Mettre votre code du TP precedent myshell
					*/
	char *list_arg[N_ARGS];   //tableau des pointeurs d'arguments 
	char line[1024];

	int i = 0, nb = 0, num_arg = 0;
	while(1)
	{
        	//Q1
        	num_arg = 0; i =0;

        	nb = read_arg(0, line , sizeof(line)) ; //APPEL de read_arg()
        	printf(">%s<\n",line);
        
		if(nb == 0)  exit(0);  //sort si CTRL-D

        	list_arg[num_arg++] = line;  //1er arg = commande
	
        	//Q2   boucle de découpage : isole les arguments de la ligne de commande
        	while(i < nb)
        	{
			if(line[i] == 0x20){  
                		line[i] = 0;//(1 ligne ) remplace espace par 0
                		i++;//(1 ligne ) passe au caract suivant de line
                		
				while(line[i] == 0x20) i++;    // boucle échappement de plusieurs espaces : ne pas retirer...

                		list_arg[num_arg] = line+i;//(1 ligne ) AFFECTE LE debut ieme argument list_arg[num_arg] = .....
                
                        num_arg++;  //incrementer numero argument
            		}
        
        		i++;//( 1 ligne )passe au caractere suivant de line
        	}

        list_arg[num_arg] = NULL;  //dernier argument
        
	//boucle affichage des arguments isoles 
	for(i = 0; i < num_arg ; i ++)
		printf("arg[%d] --> %s\n",i,list_arg[i]);

	//Q3 lancement des commandes
	char cmd[50];
	sprintf(cmd,"/bin/%s", list_arg[0]);

	int pid = fork();
	if(!pid){
		execl(cmd,list_arg[0],list_arg[1],(char*)0);

		printf("|[Child of PID %d]|\n", getpid());
		sleep(2);
	}else{
		printf("|[Parent of PID %d]|\n", getpid());
		wait(0);
	}

	
        
	}
	
	//puts(" ce programme ne fera rien sans votre code du TP Myshell 2...");

	//Q1 creer les 2 tubes
	// TODO …
	pipe(fd12);
	pipe(fd21);


	 //Q2 Algorithme principal CF annexe 2 du sujet
	 if(pid1=fork() > 0){
		 if(pid2=fork() > 0){
			 close(fd12[1]);
			 close(fd21[1]);
			 while(fd12[0] & fd21[0]){
				 wait()
			 }
			 int nb, pidexit;
			 nb = 2;
			 while(nb){
				 pidexit = wait(0);
				 if(pidexit = pid1){
					 --nb;
				 }else if(pidexit = pid2){
					 --nb;
				 }
			 }
		 }else{
			 fils2(cmd);
		 }
	 }else{
		 fils1(cmd);
	 }
	//TODO …

}

void fils1(char *cmd)
{
        //fermeture descripteurs inutiles
		close(fd12[0]);
		close(fd21[1]);	
		printf("je suis le fils 1 de pid ---> %d, lit sur fd%d et ecrit sur fd%d\n",getpid(),\
			fd21[0],fd12[1]);
		
        //redirection flux stdout vers la sortie tube fils1 vers fils2
        //TO DO Q3
    
        //appel à dup(   );

		sleep(2);
        //TO DO Q3
		//appel de execl();   //envoi 1ere cde
		

		exit( 0);
}


void fils2(char *cmd)
{
        //fermeture descripteurs inutiles
		close(fd12[1]);
		close(fd21[0]);
		printf("je suis le fils 2 de pid ---> %d, lit sur fd%d et ecrit sur fd%d\n",getpid(),\
			fd12[0],fd21[1]);
				
    
        //redirection flux stdin vers l'entree tube fils1 vers fils2
        //TO DO Q3
    
        //appel à dup();
		
        sleep(2);
        //appel de execl();   //envoi 2eme cde
    
		
		exit( 0);


}

