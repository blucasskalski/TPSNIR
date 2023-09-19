/**************************************************
* Projet : Seveur Web
* Fichier : TraitementServeurWeb.c
* Version 0.1
*
* Historique
* V0.0 : Création
* V0.1 : publication
*
* Compilation gcc -Wall TraitementServeurWeb.c serveurWeb_v0.1.c -o srvweb -pthread
*
* port par défaut : celui que l'on passe en paramètre 8080 est conseillé
* docroot : chemin ou se trouve les fichiers HTML et images ./docRoot/
*
* Auteur : Flavian LAXENAIRE
* Date : 05/10/21
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
#include <sys/signal.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAXPENDING 5 /* Maximum outstanding connection requests */
#define true 1
#define false 0
#define NB 8
sem_t NB_client;
char log_txt[200];

struct structure
{
    pthread_mutex_t mutex;
    pthread_t thread;
    int socket;
};

extern int fin;
void log_funct(char *);
void Myfunct(struct structure *elem);
void die();
void get_blody_signal();

void DieWithError(char *errorMessage);   /* Error handling function */
void HandleTCPClient(int client_socket); /* TCP client handling function */

void get_blody_signal(int s)
{
    //printf(" Signal : %d\n", s);
    sprintf(log_txt, "Signal : %d\n", s);
    log_funct(log_txt);
    die();
}

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

void die()
{
    fin = true;
    sprintf(log_txt, "Fermeture des transmission\n");
    log_funct(log_txt);
    //printf("Fermeture des transmission\n");
    sleep(1);
    sprintf(log_txt, "Fermeture du serveur\n");
    log_funct(log_txt);
    // printf("Fermeture du serveur\n");
    exit(0);
}

void Myfunct(struct structure *elem)
{
    while (1)
    {
        pthread_mutex_lock(&elem->mutex);
        HandleTCPClient(elem->socket);
        elem->socket = -1;
        sem_post(&NB_client);
    }
}

void log_funct(char *log_txt)
{
    int log = open("log.txt", O_RDWR | O_APPEND | O_CREAT, 0666);
    if (log != -1)
    {
        write(log, log_txt, strlen(log_txt));
    }
    else
    {
        printf("Impossible de creer le fichier log.txt\n");
    }
}

int main(int argc, char *argv[])
{
    int servSock;                    /* Socket descriptor for server */
    int clntSock;                    /* Socket descriptor for client */
    struct sockaddr_in httpServAddr; /* Local address */
    struct sockaddr_in httpClntAddr; /* Client address */
    unsigned short httpServPort;     /* Server port */
    unsigned int clntLen;            /* Length of client address data structure */
    int optval = 1;                  /* for set sockopt reuseaddr */
    struct structure tab[NB];
    time_t timestamp = time(NULL);
    struct tm *timeInfos = localtime(&timestamp);
    sprintf(log_txt, "\nDate and local time : %04d/%02d/%02d %02d:%02d:%02d\n",
            timeInfos->tm_year + 1900, timeInfos->tm_mon + 1, timeInfos->tm_mday,
            timeInfos->tm_hour, timeInfos->tm_min, timeInfos->tm_sec);
    //  printf("log : %s", log_txt);
    log_funct(log_txt);

    for (int i = 0; i < NB; i++)
    {
        pthread_mutex_init(&(tab[i].mutex), NULL);
        pthread_mutex_lock(&(tab[i].mutex));
        tab[i].socket = -1;
        pthread_create(&(tab[i].thread), NULL, (void *)Myfunct, &tab[i]);
    }
    sem_init(&NB_client, 1, NB);

    signal(SIGINT, get_blody_signal);
    signal(SIGPIPE, get_blody_signal);

    if (argc != 2) /* Test for correct number of arguments */
    {
        fprintf(stderr, "Usage:  %s <Server Port>\n", argv[0]);
        exit(1);
    }

    httpServPort = atoi(argv[1]); /* First arg:  local port */

    /* Create socket for incoming connections */
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    if (setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
        DieWithError("reuseaddr error");

    /* Construct local address structure */
    memset(&httpServAddr, 0, sizeof(httpServAddr));   /* Zero out structure */
    httpServAddr.sin_family = AF_INET;                /* Internet address family */
    httpServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    httpServAddr.sin_port = htons(httpServPort);      /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *)&httpServAddr, sizeof(httpServAddr)) < 0)
        DieWithError("bind() failed");

    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
        DieWithError("listen() failed");

    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        clntLen = sizeof(httpClntAddr);

        /* Wait for a client to connect */
        if ((clntSock = accept(servSock, (struct sockaddr *)&httpClntAddr,
                               &clntLen)) < 0)
            DieWithError("accept() failed");

        sem_wait(&NB_client);
        for (int i = 0; i < NB; i++)
        {
            if (tab[i].socket == -1)
            {
                tab[i].socket = clntSock;
                pthread_mutex_unlock(&(tab[i].mutex));
                break;
            }
        }
        /* clntSock is connected to a client! */
        //HandleTCPClient(clntSock);
        //printf("Handling client %s\n", inet_ntoa(httpClntAddr.sin_addr));
        sprintf(log_txt, "Handling client %s\n", inet_ntoa(httpClntAddr.sin_addr));
        log_funct(log_txt);
    }
    // sigprocmask(SIG_BLOCK,)
    /* NOT REACHED */
}