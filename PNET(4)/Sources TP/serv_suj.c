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

int sock_SERVEUR;  /* identifiant socket serveur */   

/***************************/
/* gestionnaire signal     */
/***************************/
void arret()
{
	printf(" \nARRET PROG DE TEST SOCKET   ---> echo \n");
	 
	/* Fermer la socket   */
	kill(getpid(),SIGKILL);
}

main()
{
	
	struct sockaddr_in	myaddr , from;    /* myaddr : format adresse locale  ,   from : format adresse du client(distant)*/

	char buf[100],res[100];
	int cc = 0, i = 0;
    
	// Attache routine sortie correcte sur CTR-C
	//signal(    );
	
	bzero((char *)&myaddr,sizeof(myaddr));   /* init à 0 des adresses */
	
	/* Creation socket serveur */
	sock_SERVEUR = socket(PF_INET, SOCK_STREAM, 0);
	printf("%d", sock_SERVEUR);
	/* Renseigner les champs domaine, adresse et port de la structure adresse locale */
	
	
	
    /* Attachement de l'adresse locale a la socket SERVEUR */
   	if (bind(sock_SERVEUR , (struct sockaddr *) &myaddr , sizeof(myaddr)) < 0) 
   	{
		perror("erreur de bind");
		exit(-1);
	}		

	/* attente connexions clientes 1  ici*/
	printf("attente de demande connexion");
	/*   TO DO  */
    // listen( );
	
				 
	int new, len = sizeof(from); /* taille du distant */
	
    /* Accepter une nouvelle connexion */
	
    //TO DO
	//new = accept(        ....     );
	printf("nouveau client sur fd %d\n",new);

	if(new<0)
	{
		perror("accept");
		exit(-1);
	}
	printf("DEBUT serveur\n");
		
	/* TODO    Boucle d'envoi / reception */

                       
	sleep(1);
	printf("FIN serveur \n");
	close(new);      //ferme socket de service
	
	close(sock_SERVEUR);
			  
	exit(0);
}
