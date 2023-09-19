#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int sock_CLIENT; /*  identifiant socket cliente */
/***************************/
/* gestionnaire signal     */
/***************************/
void arret()
{
	printf(" \nARRET PROG CLIENT SOCKET   ---> echo \n");
	/*   TODO Q2  Fermer la socket */
	close(sock_CLIENT);
	kill(getpid(), SIGKILL);
}

main(int argc, char **argv)
{
	struct sockaddr_in sin;		/* format d'adresse locale sockaddr_in*/
	unsigned long hostAddr = 0; /* pour adresse IP*/
	int taille = 0;
	char cm[200], txt[200];
	char c, *cmd;
	int pos, i;

	/* Attache routine sortie correcte sur CTRL-C */
	signal(SIGINT, arret);
	bzero((char *)&sin, sizeof(sin));	 /* init. à 0 des champs de l'adresse   */
	hostAddr = (inet_addr("127.0.0.1")); /* recup. adresse du serveur (ici localhost dans un permier temps) */
	/* adresse */
	/* TODO Q2 /* copie de l'adresse du serveur */
	/* CF man en 1er arg adresse source ; en 2ème le champ adresse de votre structure locale, en 3 eme la taille */
	bcopy(&hostAddr, (struct sockaddr_in *)&sin.sin_addr, sizeof(hostAddr));
	/*  TODO Q2 Renseigner domaine de la socket */
	sin.sin_family = PF_INET;
	/* TODO Q2 Renseigner le port du serveur */
	sin.sin_port = htons(5000);
	/* Creation socket */
	sock_CLIENT = socket(PF_INET, SOCK_STREAM, 0);

	printf("N socket cliente %d\n", sock_CLIENT);

	/* TODO Q2 demande de connexion au serveur */
	if (connect(sock_CLIENT, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("client:pb connexion au serveur par socket");
		exit(-1);
	}
	/*  TODO Q2 boucle envoi / reception */
	char buf[2000];
	for(;;)
	{
		while(read(0, buf, 1) > 0)
		{
			write(sock_CLIENT, buf, 1);
		}
	}
	close(sock_CLIENT); /* ferme socket cliente**/
	exit(0);
}
