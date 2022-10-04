/************************************/
/* Prog serveur udp                 */
/* Auteur ....                      */
/* 9/9/16                           */
/* serveur UDP                      */
/* gcc -Wall -o        ...........  */
/************************************/




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

int sock_SERVEUR;
void arret(int sig)
{
	printf(" \nARRET PROG serveur SOCKET   ---> echo \n");
	 close(sock_SERVEUR);
	kill(getpid(),SIGKILL);
       	  
}

main(int argc, char **argv)
{
	struct sockaddr_in	sin_dest , sin_src; //adresses sockets destination et sources
	socklen_t taille = sizeof(sin_src);
	unsigned long hostAddr = 0;
	//int	taille=0;
	char	cm[200],txt[200];
	char	c,*cmd;
	int		pos,i;

	/* Attache routine sortie correcte sur CTRL-C */
	signal(SIGINT, arret);
												   
	/* init socket destination CLIENTE */
	bzero((char *) &sin_dest,sizeof(sin_dest));
	
    //COMPLETEZ ci - dessous le port
    sin_dest.sin_port =     ;  /*  Numero de port du client  */
	
    sin_dest.sin_family = PF_INET;
	
	 
	/* n'importe quelle adresse "acceptable" (par le serveur) en tant qu'adresse source  */
    /* Complétez ci-dessous  Pensez à une constante systeme vue en cours ... */
	sin_dest.sin_addr.s_addr =           ;
       
       	
    
	/* init socket source SERVEUR */
	//init à zero de tous les champs
	bzero((char *) &sin_src,sizeof(sin_src));
	
   	
	sin_src.sin_port =      ;   /* port serveur  A renseigner*/
    
    /* RENSEIGNEMENT adresse  Tout est fait ici !!! */
    hostAddr = (inet_addr("127.0.0.1"));
	if((long) hostAddr != (long) -1)
	{
		bcopy(&hostAddr,&sin_src.sin_addr.s_addr,sizeof(hostAddr));
        sin_src.sin_family = PF_INET;
	}
	   
	
     /* CREER la socket serveur pour protocole UDP */

	if((sock_SERVEUR=socket(                             ))<0){
		perror("client:pb creation socket");
		exit(-1);
	}
		printf("N socket serveur %d\n",sock_SERVEUR);
	
	
    /* ATTACHEZ descripteur de la socket SERVEURà la structure socket "source" sin_src  */
    
    if (bind(    ,(struct sockaddr*)       , sizeof(       )) < 0)
    {
        perror("erreur de bind");
        exit(-1);
    }
    
    /* boucle reception / emission   socket   */
    for(;;)
    {
        taille = sizeof(sin_src);//   REINIT du champ taille a chaque reception
        

		       	/*lecture reponse client */
			for(i=0;i < sizeof(txt); *(txt+i++) = '\0')  ;   /* init du buffer de reception */    
			/* CODER la RECEPTION sur socket   recvfrom(      ) */
				 
        
            /* renvoie vers le client prendre   sendto()*/
				
		}
		   	
	close(sock_SERVEUR);    //fermeture socket serveur
	exit(0);
}
