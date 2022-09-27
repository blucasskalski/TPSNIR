
/**************************************************
 * Projet : Seveur Web
 * Fichier : TraitementServeurWeb.c
 * Version 0.1
 *
 * Historique
 * V0.0 : Création
 * V0.1 : publication
 * 
 * Compilation gcc -Wall TraitementServeurWeb.c serveurWeb_v0.1.c -o srvweb
 *
 * port par défaut : celui que l'on passe en paramètre 8080 est conseillé
 * docroot : chemin ou se trouve les fichiers HTML et images ./docRoot/
 * 
 * Auteur : af
 * Date : 10/11/2009 revu le 30/08/2011
 * 
 * Ce fichier contient le main et la gestion des sockets pour un serveur mono-client
 *
 *****************************************************/



#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <signal.h>     /* for signal() */

#define MAXPENDING 5    /* Maximum outstanding connection requests */
#define true 1
#define false 0


extern int fin ;

void DieWithError(char *errorMessage);  /* Error handling function */
void HandleTCPClient(int client_socket);/* TCP client handling function */

void get_blody_signal(int sig);

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

void die()
{
    fin = true ;
    printf("Fermeture des transmission\n");
    sleep(1);
    printf("Fermeture du serveur\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int servSock;                    /* Socket descriptor for server */
    int clntSock;                    /* Socket descriptor for client */
    struct sockaddr_in httpServAddr; /* Local address */
    struct sockaddr_in httpClntAddr; /* Client address */
    unsigned short httpServPort;     /* Server port */
    unsigned int clntLen;            /* Length of client address data structure */
	int optval = 1;					 /* for set sockopt reuseaddr */

    if (argc != 2)     /* Test for correct number of arguments */
    {
        fprintf(stderr, "Usage:  %s <Server Port>\n", argv[0]);
        exit(1);
    }

    httpServPort = atoi(argv[1]);  /* First arg:  local port */


    /* Create socket for incoming connections */
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");
        
	if (setsockopt(servSock,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval))==-1)
		DieWithError("reuseaddr error");
	
    /* Construct local address structure */
    memset(&httpServAddr, 0, sizeof(httpServAddr));   /* Zero out structure */
    httpServAddr.sin_family = AF_INET;                /* Internet address family */
    httpServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    httpServAddr.sin_port = htons(httpServPort);      /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *) &httpServAddr, sizeof(httpServAddr)) < 0)
        DieWithError("bind() failed");

    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
        DieWithError("listen() failed");

    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        clntLen = sizeof(httpClntAddr);

        /* Wait for a client to connect */
        if ((clntSock = accept(servSock, (struct sockaddr *) &httpClntAddr, 
                               &clntLen)) < 0)
            DieWithError("accept() failed");

        /* clntSock is connected to a client! */

        printf("Handling client %s\n", inet_ntoa(httpClntAddr.sin_addr));

        HandleTCPClient(clntSock);
    }
    /* NOT REACHED */
}