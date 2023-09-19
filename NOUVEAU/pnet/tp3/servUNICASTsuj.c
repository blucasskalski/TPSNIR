/*******************************************/
/* Prog serveur unicast multiclient TCP    */
/* PM v2                                   */
/* 2/10/18                                 */
/* gcc -Wall -o servUNICAST servUNICATsuj.c*/
/* auteur : Flavian LAXENAIRE		   */
/*******************************************/


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
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#define DEBUG 11

int sTCP;
void arret(int sig)
{
	printf(" \nARRET PROG DE TEST SOCKET   ---> echo \n");
	 close(sTCP);
	kill(getpid(),SIGKILL);  
}


int main(int argc, char **argv)
{
    struct sockaddr_in	myaddr,from;
    struct hostent  *hp = NULL;
    char *Ahost_info[6];
    socklen_t t;
    char buf[100],res[100];
    int cc = 0, n, new, bytes = 0, maxfd = 0;
    int taille ;
    
    fd_set fdset, readfds ;
    
    /* structure pour le timeout du select */
    struct timeval date;
    date.tv_sec = 0;
    date.tv_usec = 50000;
    
    /* init a NULL du nom de machine */
    for(new = 0; new <6 ; new ++){
        Ahost_info[new] = NULL;
        }
	/* Attache routine sortie correcte sur CTRL-C */
    	signal(SIGINT, arret);
	/* init a zero des champs de la socket */	
	bzero((char *)&myaddr,sizeof(myaddr));
	if((sTCP =socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("serveur: Socket");
		exit(3);
	}
	myaddr.sin_family = PF_INET;
	myaddr.sin_addr.s_addr = INADDR_ANY;
	myaddr.sin_port	= htons(5000); /* PORT personnalise */
   	if (bind(sTCP,(struct sockaddr*)&myaddr, sizeof(myaddr)) < 0) {
                /*printf("%p", (void *)myaddr.sin_addr);*/
		perror("erreur de bind");
		exit(6);
	} 		
	/* attente connexions clientes 6  ici*/
	printf("attente de demande connexion");
	listen(sTCP,6);
    FD_ZERO( &fdset ) ;
    /* Q1 Enregistrement de la socket d'ecoute dans la structure fdset */
    FD_SET(sTCP,&fdset);
    /* boucle ecoute des connexions clientes */
    while(1){
        bcopy(&fdset,&readfds,sizeof(fd_set));
        maxfd = 6 ;
        /* Q2 Test d'ecoute si nouvelle connexion */
        n = select(maxfd,&readfds, NULL, NULL, &date ) ;
                 /*  Q3 TEST si nelle donnée entrante en lecture */
                if ( FD_ISSET(sTCP,&readfds)) {
                    taille = sizeof(myaddr);
                    /* Q4 accepte nouvelle connexion cliente */
                    new = accept(sTCP,(struct sockaddr *) &from, &t);
                    printf("nouveau client sur %d\n",new);
                    //on ne depasse pas le max des descripteurs
                    if(new > maxfd){
                            for(new = 0; new < maxfd; new ++){
                                free(Ahost_info[new]);
                                Ahost_info[new] = NULL; // RAZ pteur
                                close(new);
                                FD_CLR(new,&fdset); //retire descripteur service de structure fdset
                            }
                        close(sTCP);
                        exit(-1);
                    }
            /* enregistrement structure new  */
            FD_SET(new, &readfds);
            printf("lecture sur descripteur %d\n", new);
                    /* Q5 recupere info distante du nom de machine */
                    hp = gethostbyaddr(&from.sin_addr,sizeof(myaddr.sin_addr),AF_INET);
                    //recopie du nom de machine distante
                    Ahost_info[new]=(char*)malloc(strlen(hp->h_name) + 1);
                    strcpy(Ahost_info[new], hp->h_name );
                   printf("Call using #%d from %s\n",new,Ahost_info[new]);
                }
            //boucle de parcours de toutes les connexions
            for(new = 0; new < maxfd; new ++)
                {
                        if(Ahost_info[new])   // il y a une machine au bout !!! du descripteur
                        {
                            //Q6 TEST si donnees arrivees
                            ioctl(new,FIONREAD,&bytes);
                            if(bytes)  //si il y a qqchose à lire !! sinon read bloquant
                            {
                                cc = read(new,buf,sizeof(buf));
                                if(cc>=1) {
                                    buf[cc]='\0';
                                    if(write(new,buf,cc) < 0)   //erreur car machine deconnectee
                                    {
                                        free(Ahost_info[new]);
                                        Ahost_info[new] = NULL; // RAZ pteur
                                        close(new);
                                        FD_CLR(new,&fdset); //retire descripteur service de structure fdset
                                    }
                                printf("SERVEUR CIBLE Echo de %s\n",buf);
                                }
                            }
                        }
                }
    }
    close(sTCP);
    exit(0);
}
