//
//  myshellfork.c
/**********************************************************/
/* Prog support pour recréer un Shell     		  */
/* 9/21							  */
/* compilation par : gcc -Wall -o myshell2 myshell2_suj.c */
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N_ARGS 12


int read_arg(int fd, char* line, int size)
{
	int nblus = 0; //nb caracteres lus

	//Q1  lecture ligne de commande et stockage dans line
	nblus = read(0,line, size);
	if(nblus) line[nblus-1] = 0; //mets le fin de chaine
	return nblus;

}


int main(int argc, char **argv)
{
	char *list_arg[N_ARGS];   //tableau des pointeurs d'arguments
	char line[1024];
	char cmd[50];
	int pid;

	int i = 0,	 nb = 0, num_arg = 0;
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
			if(line[i] == 0x20)
			{
				line[i] = 0;		//(1 ligne ) remplace espace par 0
				i++;	//(1 ligne ) passe au caract suivant de line

				while(line[i] == 0x20) i++;    // boucle échappement de plusieurs espaces : ne pas retirer...

				list_arg[num_arg++] = &line[i] ;  //(1 ligne ) AFFECTE LE debut ieme argument list_arg[num_arg] = ...
			}

			i++;	//( 1 ligne )passe au caractere suivant de line
		}

		list_arg[num_arg] = NULL;  //dernier argument

		//boucle affichage des arguments isoles
		for(i = 0; i < num_arg ; i ++)
		printf("arg[%d] --> %s\n",i,list_arg[i]);

		//Q3 lancement des commandes
		sprintf(cmd,"/bin/%s",list_arg[0]);

		if((pid = fork()) == 0) //fils
		{
			printf("je suis le fils de pid ---> %d\n",getpid());
			execv(cmd,list_arg);

			sleep(2);
		}
		else
		{
			printf("je suis le pere de pid ---> %d\n",getpid());
			wait(0);
			printf("finis");

		}

	}//fin bcle generale
}