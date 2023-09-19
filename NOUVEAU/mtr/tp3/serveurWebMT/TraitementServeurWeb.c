
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
 * Ce fichier contient la fonction de traitement du client qui se connecte au serveur.
 *
 *****************************************************/

#include <stdio.h>     /* for printf() and fprintf() */
#include <stdlib.h>    /* for atoi() and exit() */
#include <string.h>    /* for memset() */
#include <unistd.h>    /* for close() */
#include <fcntl.h>     /* open */
#include <sys/types.h> /* idem */
#include <sys/stat.h>  /* idem */
#include <sys/types.h>
#include <sys/socket.h>
#include <ctype.h>
//#include <features.h>

#define LISTENQ 1024 /* Taille de la file d'attente de la socket */
#define MAXLEN 512   /* Taille des buffer */
#define MAXARG 200   /* Nb de champs max dans un header HTTP */

#define MILIEU 0
#define DEBUT 1

#define true 1
#define false 0

int fin = false;

/*
 * Variable global Header HTML et 404
 */
const char *headerhtml = "\
HTTP/1.0 200 OK\n\
Server: embeded IRIS server\n\
Connection: close\n\
Content-Type: text/html\n\
X-Pad: avoid browser bug\n\n";

const char *header404 = "\
HTTP/1.0 404 OK\n\
Server: embeded IRIS server\n\
Connection: close\n\
Content-Type: text/html\n\
X-Pad: avoid browser bug\n\n";

/*
 * Variable global Header Image
 */
const char *headerimg = "\
HTTP/1.0 200 OK\n\
Server: \n\
Accept-Ranges: bytes\n\
Content-Type: image\n\
Connection: close\n\n";

const char *message404 = "<html><body>404 Not Found<BR>IRIS Serveur 2009<body></html>";

int debug = 0;

/* Fonction qui permet le découpage de req en un tableau de char* */
void parser(char *req, char **ret);

/* fonction de traitement du serveur Web*/
void HandleTCPClient(int client_socket);

char log_txt[200];
void parser(char *req, char **ret); // fonction de découpage de la requête
void log_funct(char *);
void HandleTCPClient(int client_socket)
{

    static int count = 0;
    int flag404 = false;
    int num_bytes_received, num_bytes_sent, tot = 0;
    const char *header;
    char client_message[MAXLEN];
    char client_file[MAXLEN] = "./docRoot/"; // docroot
    char *tab[MAXARG];
    char *pc;
    int i, j, ret;
    FILE *f;
    struct stat statFile;

    while (!strstr(client_message, "\r\n\r\n") && !strstr(client_message, "\n\n"))
    {
        num_bytes_received = recv(client_socket, client_message + tot, MAXLEN - tot, 0);
        tot += num_bytes_received;
        client_message[tot] = '\0';
        if (num_bytes_received < 0)
        {
            fprintf(stderr, "recv error\n");
            exit(1);
        }
        //printf (">%s\n", client_message);
    }
    if (debug)
    {
        //printf("Client says: --->%s<\n", client_message);
        sprintf(log_txt, "Client says: --->%s<\n", client_message);
        log_funct(log_txt);
    }
    /* Découpage du header */
    parser(client_message, tab);

    /* Ouverture du fichier */
    strcat(client_file, tab[1]);
    if (debug)
    {
        // printf("get file : %s\n", client_file);
        sprintf(log_txt, "get file : %s\n", client_file);
        log_funct(log_txt);
    }

    ret = stat(client_file, &statFile); //recup état du fichier

    if ((ret == 0) && S_ISREG(statFile.st_mode))
    {
        f = fopen(client_file, "r");
        if (f == NULL)
        {
            perror("Ouverture du fichier impossible");
            exit(-1);
        }
        else
        {
            if (debug)
            {
                //printf("fichier ouvert\n");
                sprintf(log_txt, "fichier ouvert\n");
                log_funct(log_txt);
            }
        }
    }
    else
    {
        // printf("404 - NotFound %s\n", client_file);
        sprintf(log_txt, "404 - NotFound %s\n", client_file);
        log_funct(log_txt);
        flag404 = true;
    }

    // paramétrage header et envoie
    pc = strstr(client_file, ".html");
    if (flag404)
    {
        header = header404;
    }
    else
    {
        if (pc)
        {
            if (*(pc + ((strlen(".html") + 1))) == '\0')
            {
                header = headerhtml;
            }
            else
            {     //bin
                ; //header = headerimg; // non traité
            }
        }
        else
        {
            header = headerimg;
        }
    }
    num_bytes_sent = send(client_socket, header, strlen(header), 0);

    if (num_bytes_sent != strlen(header))
        fprintf(stderr, "send header error");
    i = 0; //init taille
    do
    {
        if (!flag404)
        {
            j = fread(client_message, sizeof(char), MAXLEN, f);
            if (debug)
            {
                //printf("read : %d\n", j);
                sprintf(log_txt, "read : %d\n", j);
                log_funct(log_txt);
            }
        }
        else
        { // 404
            strncpy(client_message, message404, strlen(message404));
            j = strlen(message404);
        }
        num_bytes_sent = send(client_socket, client_message, j, 0);
        if (num_bytes_sent < 0)
        {
            fprintf(stderr, "send error\n");
            break;
        }
        i += j;
        //printf("envoie buffer : %d\n", j );
        usleep(200000); // frein
    } while (j > 0 && !flag404 && !fin);

    if (fin)
    {
        //printf("arrêt prématuré demandé\n");
        sprintf(log_txt, "arrêt prématuré demandé\n");
        log_funct(log_txt);
    }
    if (j == 0)
    {
        // printf("%d) File Sent : %d; ", count++, i);
        // printf("file : %s, stat = %d\n", client_file, ret);
        sprintf(log_txt, "%d) File Sent : %d; file : %s, stat = %d\n", count++, i, client_file, ret);
        log_funct(log_txt);
    }
    else
    {
        // printf("erreur d'envoi\n");
        sprintf(log_txt, "erreur d'envoi\n");
        log_funct(log_txt);
    }

    close(client_socket);
}

void parser(char *req, char **ret)
{
    //début de découpage
    int i, j = 0, flag = DEBUT;
    if (debug)
    {
        //printf("parser :\n");
        sprintf(log_txt, "parser :\n");
        log_funct(log_txt);
    }

    for (i = 0; i < MAXLEN && req[i] != '\0'; i++)
    {
        if (isspace(req[i]))
        {
            if (flag == MILIEU)
            { // FLAG == FIN
                req[i] = '\0';
                flag = DEBUT;
                j++;
                if (j == MAXARG)
                    exit(-1);
            }
        }
        else
        {
            if (flag == DEBUT)
            {
                ret[j] = &req[i];
                flag = MILIEU;
            }
            else  //FLAG == MILIEU
                ; // RIEN
        }
    }
    ret[j] = NULL;
    j = 0;
    //fin du découpage

    // Debug affichage des arguments
    if (debug)
        for (i = 0; i < MAXARG && ret[i] != 0; i++)
        {
            //printf("--->%s<\n", ret[i]);
            sprintf(log_txt, "--->%s<\n", ret[i]);
            log_funct(log_txt);
        }
    if (debug)
    {
       // printf("parser done\n");
        sprintf(log_txt, "parser done\n");
        log_funct(log_txt);
    }
}
