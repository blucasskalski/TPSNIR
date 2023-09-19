/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          myshell3_suj.c
 | 
 | Projet :       myshell3_suj
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o myshell3_suj myshell3_suj.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define N_ARGS 12

//Q1
//creation des 2 tblx de descripteurs
int fd12[2]; //fils1 vers fils2
int fd21[2]; //fils2 vers fils1

/* descripteur des processus */

void fils1(char *cmd1);
void fils2(char *cmd2);

/* fonction de lecture des arguments du shell maison */
int read_arg(int fd, char *buffer, int size)
{
	int nblus = 0;
	nblus = read(0, buffer, size);
	if (nblus)
		buffer[nblus - 1] = 0; //mets le fin de chaine
	return nblus;
}

int main(int argc, char **argv)
{
	/* Mettre votre code du TP precedent myshell */
	char *list_arg[N_ARGS]; //tableau des pointeurs d'arguments
	char line[1024];
	char cmd[50];
	char cmd1[50];
	char cmd2[50];
	int i = 0, nb = 0, num_arg = 0, ispipe = 0;
	while (1)
	{
		//Q1
		num_arg = 0;
		i = 0;
		memset(cmd1, 0, 50);
		memset(cmd2, 0, 50);
		memset(line, 0, 1024);
		*list_arg = 0;

		nb = read_arg(0, line, sizeof(line)); //APPEL de read_arg()
		printf(">%s<\n", line);

		if (nb == 0)
			exit(0); //sort si CTRL-D

		list_arg[num_arg++] = line; //1er arg = commande
		char *p;
		p = line;
		int temp = 0;
		//Q2   boucle de découpage : isole les arguments de la ligne de commande
		while (i < nb)
		{
			if (line[i] == 0x7C)
			{
			}
			if (line[i] == 0x20)
			{
				line[i] = 0;
				//(1 ligne ) remplace espace par 0
				//(1 ligne ) passe au caract suivant de line
				i++;
				while (line[i] == 0x20)
					i++; // boucle échappement de plusieurs espaces : ne pas retirer...

				//(1 ligne ) AFFECTE LE debut ieme argument list_arg[num_arg] = .....

				p -= temp;
				p += i;
				temp = i;
				list_arg[num_arg++] = p;

				//list_arg[num_arg++] = line + i;
			}
			i++;

			//( 1 ligne )passe au caractere suivant de line
		}
		list_arg[num_arg] = NULL; //dernier argument
		//boucle affichage des arguments isoles
		int status = 0;
		ispipe = 0;
		for (i = 0; i < num_arg; i++)
		{
			printf("arg[%d] --> %s\n", i, list_arg[i]);
			if (strcmp(list_arg[i], "|") == 0)
			{
				ispipe = 1;
				status = 1;
			}
			if (status == 0)
			{
				strcat(cmd1, list_arg[i]);
				strcat(cmd1, " ");
			}
			else if (status == 2)
			{
				strcat(cmd2, list_arg[i]);
				strcat(cmd2, " ");
			}
			else
				status = 2;
		}
		printf("cmd 1 : %s\ncmd 2 : %s\n", cmd1, cmd2);
		//Q4 fork()
		if (ispipe == 0)
		{
			int pid = fork();
			if (pid == 0) //fils
			{
				//execl("/bin/ps", "ps", "-aux", 0);
				printf("1je suis le fils de pid ---> %d\n", getpid());
				sprintf(cmd, "/bin/%s", list_arg[0]);
				printf("Output cmd :\n");
				execv(cmd, list_arg);
			}
			else
			{
				printf("1je suis le pere de pid ---> %d\n", getpid());
				wait(NULL);
			}
		}
		//Q3 lancement des commandes

		//puts(" ce programme ne fera rien sans votre code du TP Myshell 2...");

		//Q1 creer les 2 tubes
		// TODO …
		if (ispipe == 1)
		{
			if (pipe(fd12) == -1 || pipe(fd21) == -1)
			{
				perror("pipe issue");
			}
			/*Q2 Algorithme principal CF annexe 2 du sujet
		 2-1 création du fils 1
		 2-2 création fils2
		 2-3 gestion de l’attente de terminaison par le pere	
	*/
			//TODO …

			int pid1, pid2;

			if ((pid1 = fork()) > 0)
			{
				if ((pid2 = fork()) > 0)
				{
					close(fd12[0]);
					close(fd21[1]);
					close(fd12[1]);
					close(fd21[0]);
					int pidexit;
					int nb = 2;
					while (nb)
					{
						pidexit = wait(0);
						if (pidexit == pid1)
							nb--;
						else if (pidexit == pid2)
							nb--;
					}
				}
				else
				{
					fils2(cmd2);
				}
			}
			else
			{
				fils1(cmd1);
			}
		}
	} //fin bcle generale
}

void fils1(char *cmd1)
{
	//char buf;
	//fermeture descripteurs inutiles
	close(fd12[0]);
	close(fd21[1]);
	printf("je suis le fils 1 de pid ---> %d, lit sur fd%d et ecrit sur fd%d\n", getpid(),
		   fd21[0], fd12[1]);
	//write(fd12[1], "A", 1);
	//read(fd21[0], &buf, 1);
	//printf("cmd : %s\n", cmd);

	//redirection flux stdout vers la sortie tube fils1 vers fils2
	//TO DO Q3

	//appel à dup(   );
	dup2(fd12[1], 1);
	//dup(fd21[1]);
	//TO DO Q3
	//appel de execl();   //envoi 1ere cde
	execl("/bin/sh", "sh", "-c", cmd1, (char *)0);
	printf("exit1\n");
	exit(0);
}

void fils2(char *cmd2)
{
	//char buf;
	//fermeture descripteurs inutiles
	close(fd12[1]);
	close(fd21[0]);
	//dup()
	printf("je suis le fils 2 de pid ---> %d, lit sur fd%d et ecrit sur fd%d\n", getpid(),
		   fd12[0], fd21[1]);
	//read(fd12[0], &buf, 1);
	//write(fd21[1], "B", 1);
	//redirection flux stdin vers l'entree tube fils1 vers fils2
	//TO DO Q3

	//appel à dup();
	dup2(fd12[0], 0);
	//dup(fd21[0]);
	//appel de execl();   //envoi 2eme cde
	execl("/bin/sh", "sh", "-c", cmd2, NULL);
	printf("exit2\n");
	exit(0);
}
