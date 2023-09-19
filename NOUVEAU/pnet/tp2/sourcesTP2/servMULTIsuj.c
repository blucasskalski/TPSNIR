/*******************************************/
/* Prog serveur multicast  UDP             */
/* PM v2                                   */
/* 9/16                                    */
/* gcc -Wall -o servMULTI servMULTIsuj.c   */
/*******************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAXBUF 256
#define PORT 5000
#define GROUP "224.0.0.224" //Associer ici une adresse IP autorisée pour du multicast

int main(void)
{
  int s,r ;
  struct sockaddr_in srv; //structure serveur
  char buf[MAXBUF];

  bzero(&srv, sizeof(srv));

  /* TODO creation du serveur sur port 5000 */
  srv.sin_family = PF_INET;
  srv.sin_port = htons(PORT);

  /* TODO renseigne l'adresse du groupe de multicast */
  if (inet_aton(GROUP, &srv.sin_addr) < 0)
  {
    perror("inet_aton");
    return 1;
  }

  /* TODO creation de la socket en DGRAM */
  if ((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
  {
    perror("socket");
    return 1;
  }
  printf("N socket serveur %d\n", s);

  /* TO DO boucle de lecture clavier et envoi sur la socket de multicast */
  for (;;)
  {
    int taille = sizeof(srv);
    for (int i = 0; i < sizeof(buf); *(buf + i++) = '\0')
      ;
    int recu = read(0, buf, sizeof(buf));
    buf[recu] = 0;
    if (recu)
    {
      r = sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&srv, taille);
    }
    printf("envoyé : %d\n", r);
  }
}