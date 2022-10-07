/********************************************************
 *  * nom     : clientUdpDaytime.c
 *  * Auteur  : AF 05/03/2007
 *  * version : 0.1
 *  * descr   : client UDP daytime
 *  * licence : GPL
 *********************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
    /* ... */
    struct sockaddr_in to;
    char buffer[1024];
    time_t timestamp = time( NULL );
    struct tm * pTime = localtime( & timestamp);
    struct hostent *toinfo;

    if (argc < 2)
    {
        fprintf(stderr, "usage : %s server\n", argv[0]);
        return (1);
    }

    toinfo = gethostbyname(argv[1]);

    to.sin_family = PF_INET;
    to.sin_addr.s_addr = htonl(INADDR_ANY);
    to.sin_port = htons(9999);

    int descripteur = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

  

    if (bind(descripteur, (struct sockaddr *)&to,
             sizeof(to)) == SO_ERROR)
    {
        perror("bind ");
    }

    unsigned int fromlen = sizeof(to);


    int retour = recvfrom(descripteur, buffer, sizeof(buffer), 0, (struct sockaddr *)&to, &fromlen);
    if (retour == -1)
    {
        printf("Probleme sendto :[%s]\n", strerror(retour));
    }
    else
    {
          printf("toinfo name : %s\ntoinfo ip: %d,%d,%d,%d\n", toinfo->h_name,
           (to.sin_addr.s_addr & 0xFF) >> 0,
           (to.sin_addr.s_addr & 0xFF00) >> 8,
           (to.sin_addr.s_addr & 0xFF0000) >> 16,
           (to.sin_addr.s_addr & 0xFF000000) >> 24);

           printf("%s\n", buffer);
    }

    strftime( buffer, 80, "%d/%m/%Y %H:%M:%S", pTime);

    retour = sendto(descripteur, buffer, sizeof(buffer), 0, (struct sockaddr *)&to, sizeof(to));
    if (retour == -1)
    {
        printf("Probleme sendto :[%s]\n", strerror(retour));
    }

    close(descripteur);

    return (0);
}