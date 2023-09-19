/*********************************************/
/* Prog client mulicast UDP                  */
/* PM v2                                     */
/* 2/10/18                                   */
/* gcc -Wall -o clientMULTI clientMULTIsuj.c */
/*********************************************/

#include <sys/types.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 256
#define PORT 5000

int main(int argc, char *argv[])
{
  int s, r;
  struct sockaddr_in srv, remote;
  struct ip_mreq mreq;
  char buf[MAXBUF];
  char GROUP[16];
  bzero(&srv, sizeof(srv));

  /* TO DO renseigner port et famille */
  srv.sin_family = PF_INET;
  srv.sin_port = htons(PORT);
  /* TO DO adresse multicast   CF serveur pour l'adresse deja mise */
  //renseigner le champ adresse
  if (argc == 2)
  {
    sprintf(GROUP, "%s", argv[1]);
  }
  else
  {
    fprintf(stderr, "Usage:  %s <IP Multicast>\n", argv[0]);
    exit(1);
  }

  if ((inet_aton(GROUP, &srv.sin_addr)) < 0)
  {
    perror("inet_aton");
    return 1;
  }

  /* TO DO creation socket MODE DGRAM */
  if ((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
  {
    perror("socket");
    return 1;
  }
  printf("N socket cliente %d\n", s);

  /* Attachement socket à la structure locale */
  if (bind(s, (struct sockaddr *)&srv, sizeof(srv)) < 0)
  {
    perror("bind");
    return 1;
  }

  /* specifique au multicast */
  /*TO DO completer adresse du multicast */
  mreq.imr_multiaddr.s_addr = inet_addr(GROUP);

  /*adresse source du client */
  mreq.imr_interface.s_addr = htonl(INADDR_ANY); /* toute adresse possible */

  /* TO DO rajout du client ds le groupe de multicast => Abonnement */
  if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0)
  {
    perror("setsockopt");
    return 1;
  }

  socklen_t n = sizeof(remote); // taille du distant => taille du "serveur multicast "
                                /* TO DO boucle de reception et affichage !! */
  while (1)
  {
    r = recvfrom(s, buf, sizeof(buf), 0, (struct sockaddr *)&srv, &n);
    buf[r] = 0;
    printf("reçu : %s", buf);
  }
}
