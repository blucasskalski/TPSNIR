/************************************/
/* Prog client udp                  */
/* AUteur ......                    */
/* 9/9/16                           */
/* client UDP                       */
/* gcc -Wall -o ........            */
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


int sock_CLIENT;
void arret(int sig)
{
	printf(" \nARRET PROG CLIENT SOCKET   ---> echo \n");
	 close(sock_CLIENT);
	kill(getpid(),SIGKILL);
       	  
}

main(int argc, char **argv)
{
	struct sockaddr_in	sin_dest , sin_src; //adresses sockets destination et sources
	socklen_t taille = sizeof(sin_src);
	
	struct hostent *hp;
	unsigned long hostAddr = 0;
	//int	taille=0;
	char	cm[200],txt[200];
	char	c,*cmd;
	int		pos,i;


	/* Attache routine sortie correcte sur CTRL-C */
	signal(SIGINT, arret);
												   
	/* init socket destination SERVEUR */
	bzero((char *) &sin_dest,sizeof(sin_dest));
	
   	 hostAddr = (inet_addr("127.0.0.1"));
	 
    if((long) hostAddr != (long) -1)
	 	{
            /* copie champ adresse du serveur */
			bcopy(&hostAddr,&sin_dest.sin_addr,sizeof(hostAddr));
			sin_dest.sin_family = PF_INET;
	 	}
	 	
    /* RENSEIGNEZ le port serveur dans la socket "distante"  */

    sin_dest.sin_port =       ;
    
	 
       	
	
	/* init socket source "cliente" */
	
	bzero((char *) &sin_src,sizeof(sin_src));
	
   	 /* RENSEIGNEZ le port client dans la socket "source"  */
    
    /* CREER la socket client pour protocole UDP */
       
	if((sock_CLIENT=socket(                   ))<0)
	{
		perror("client:pb creation socket");
		exit(-1);
	}
	printf("N socket cliente %d\n",sock_CLIENT);
	
	/* ATTACHEZ descripteur de la socket CLIENTE à la structure socket "source" sin_src  */
    
	if (bind(    ,(struct sockaddr*)       , sizeof(       )) < 0)
	{       
		perror("erreur de bind");
		exit(-1);
	}

    /* boucle lecture clavier et envoi / reception socket   */
    for(;;)
    {
        taille = sizeof(sin_src);  //   REINIT du champ taille a chaque reception
        
         /* Lire au clavier read() par ex */
        
        
        /* On envoie sur la socket    PRENDRE sendto()*/
        
        
    
        for(i=0;i < sizeof(txt); *(txt+i++) = '\0')  ;   /* init du buffer de reception */
        
        /* CODER la RECEPTION sur socket   recvfrom(      ) */
        
        
    }
    
    close(sock_CLIENT);    //fermeture socket cliente
	exit(0);
}
