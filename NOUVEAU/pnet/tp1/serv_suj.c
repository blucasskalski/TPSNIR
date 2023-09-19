/************************************/
/* Prog serveur tcp                 */
/* Auteur ....                      */
/* 9/9/16                           */
/* serveur TCP                      */
/* gcc -Wall -o        ...........  */
/************************************/

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#define DEBUG 11

int sock_SERVEUR; /* identifiant socket serveur */
int nb_client = 0;

/***************************/
/* gestionnaire signal     */
/***************************/
void arret()
{
	printf(" \nARRET PROG DE TEST SOCKET   ---> echo \n");

	/* Fermer la socket   */
	close(sock_SERVEUR);
	kill(getpid(), SIGKILL);
}

int main()
{

	struct sockaddr_in myaddr, from; /* myaddr : format adresse locale  ,   from : format adresse du client(distant)*/

	char buf[100], res[100];
	int cc = 0, i = 0;
	signal(SIGINT, arret);
	// Attache routine sortie correcte sur CTR-C

	bzero((char *)&myaddr, sizeof(myaddr)); /* init à 0 des adresses */

	/* Creation socket serveur */
	sock_SERVEUR = socket(PF_INET, SOCK_STREAM, 0);
	printf("%d", sock_SERVEUR);
	/* Renseigner les champs domaine, adresse et port de la structure adresse locale */

	myaddr.sin_addr.s_addr = INADDR_ANY;
	myaddr.sin_port = htons(5000);

	/* Attachement de l'adresse locale a la socket SERVEUR */
	if (bind(sock_SERVEUR, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("erreur de bind\n");
		exit(-1);
	}

	/* attente connexions clientes 1  ici*/
	printf("attente de demande connexion\n");
	/*   TO DO  */
	listen(sock_SERVEUR, 2);

	int new, len = sizeof(from); /* taille du distant */

	/* Accepter une nouvelle connexion */
	while (1)
	{
		int service;
		int read_msg;
		signal(SIGINT, arret);
		//TO DO
		service = accept(sock_SERVEUR, (struct sockaddr *)&from, (void *)&len);
		printf("nouveau client sur fd %d\n", service);
		int pid = fork();
		if (pid == 0)
		{
			close(sock_SERVEUR);
			printf("DEBUT serveur\n");
			int nbclient = nb_client++;

			for (;;)
			{
				while ((read_msg = read(service, buf, sizeof(buf))) > 0)
				{
					buf[read_msg] = '\0';
					write(1, buf, strlen(buf));
					memset(buf, '\0', sizeof(buf));
				}
				signal(SIGINT, arret);
			}
		}
		else if (pid == -1)
		{
			perror("pipe issue");
		}
		else
		{
			close(service);
		}
		if (service < 0)
		{
			perror("accept");
			exit(-1);
		}

		/* TODO    Boucle d'envoi / reception */
		/*for (;;)
		{
			while ((read_msg = read(new, buf, sizeof(buf))) > 0)
			{
				buf[read_msg] = '\0';
				write(1, buf, strlen(buf));
				memset(buf, '\0', sizeof(buf));
			}
		}*/
	}
	sleep(1);
	printf("FIN serveur \n");
	close(new); //ferme socket de service

	close(sock_SERVEUR);

	exit(0);
}
