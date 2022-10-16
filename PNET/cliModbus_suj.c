
/* Prog client tcp  Modbus            		                                        */
/* BLS v1.0              		                                                */
/* 11/10/22                         		                                        */
/* client TCP Modbus                		                                        */
/* Fabrication : make all ou gcc -Wall -o cliModbus cliModbus_suj.c modbus.o -lm	*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>


#include <sys/wait.h>
#include <sys/types.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
	  
#include <unistd.h>
#include <string.h>
#include <strings.h>

//header "maison" à ne pas retirer !
#include "modbus.h"

int sock_CLIENT;

void arret(int sig)
{
	printf(" \nARRET PROG CLIENT SOCKET   ---> echo \n");
	 close(sock_CLIENT);
	 kill(getpid(),SIGKILL);
       	  
}

int main(int argc, char **argv){
	//structure d'adresse cliente
	struct sockaddr_in	sin;
	  
	unsigned long hostAddr = 0;   //pour adresse ip

    
    /* declaration de toute variable utile pour lire / ecrire les paramètres modbus*/
    char buffer[50];
    int intput;
    float input;
    
	/* Attache routine sortie correcte sur CTRL-C */
	signal(SIGINT, arret);
												   

	bzero((char *) &sin,sizeof(sin));
	if(argc == 2)
	{
        // ip automate saisie ligne de commande
   	 hostAddr = (inet_addr(argv[1]));
	 hostAddr &= 0xFFFFFFFF;
	  
        //Q2.1 //adresse ip du distant à renseigner  à partir de l'adresse ip saisie sur ligne de commande
				bcopy(&hostAddr, &sin.sin_addr,sizeof(hostAddr));
               // famille de la socket à renseigner
				sin.sin_family = PF_INET;
               //port 502   à renseigner
			   sin.sin_port = htons(502);
              
	
	}
	else if (argc == 1)
	{
		printf("usage ./cliModbus <adresse_ip_serveur>\n");
		exit(-1);
	}
    //Q2.2 creation socket
	sock_CLIENT = socket(PF_INET,SOCK_STREAM,0);
    //Q2.3 demande de connexion au serveur
	 if (connect(sock_CLIENT,(struct sockaddr*)&sin,sizeof(sin)) == -1) {
		perror("ça marche pas la");
		return -1;
	 }
    //Q3 menu utilisateur

    while(1){
    	printf("OP type : [1] READ | [2] WRITE | [E] SAFE EXIT\n");
    	printf("> ");
    	scanf("%s", buffer);
    	if(strcmp(buffer, "1")==0){
    		printf("|### -\tREAD MODBUS CLI  - ###|\n");
    		printf("VAR OPT : [P] Pente | [M] Masse | [V] Vitesse | [C] Couple\n");
 			printf("[BT1]/ [BT2]/ [BT3]/ [BT4] Tension des Batteries 1,2,3,4 |\n");
    		printf("[C1]/ [C2]/ [C3]/ [C4] Courant charges Batteries 1,2,3,4 |\n");
    		scanf("%s", buffer);
    		if(strcmp(buffer,"BT1")==0)
				printf("READ ==> BT1 : %f\n", lecture(32)/1000);
			if(strcmp(buffer,"BT2")==0)
				printf("READ ==> BT2: %f\n", lecture(34)/1000);
			if(strcmp(buffer,"BT3")==0)
				printf("READ ==> BT3 : %f\n", lecture(36)/1000);
			if(strcmp(buffer,"BT4")==0)
				printf("READ ==> BT4 : %f\n", lecture(38)/1000);
			if(strcmp(buffer,"C1")==0)
				printf("READ ==> C1 : %f\n", lecture(40)/1000);
			if(strcmp(buffer,"C2")==0)
				printf("READ ==> C2 : %f\n", lecture(42)/1000);
			if(strcmp(buffer,"C3")==0)
				printf("READ ==> C3 : %f\n", lecture(44)/1000);
			if(strcmp(buffer,"C4")==0)
				printf("READ ==> C4 : %f\n", lecture(46)/1000);
			if(strcmp(buffer,"P")==0)
				printf("READ ==> Pente : %f\n", lecture(22));
			if(strcmp(buffer,"M")==0)
				printf("READ ==> Masse : %f\n", lecture(18));
			if(strcmp(buffer,"V")==0)
				printf("READ ==> Vitesse : %f\n", lecture(14));
			if(strcmp(buffer,"C")==0)
				printf("READ ==> Couple : %f\n", lecture(16));
			if(strcmp(buffer,"L")==0)
				printf("READ ==> Local : %f\n", lecture(00));
    	}else if(!strcmp(buffer, "2")){
    		printf("|### -\tWRITE MODBUS CLI - ###|\n");
    		printf("VAR OPT : [P] Pente | [M] Masse | [V] Vitesse | [C] Couple\n");
    		scanf("%s", buffer);
    		if(strcmp(buffer,"P")==0){
				printf("INPUT VAL?"); scanf("%f", &input); ecriture(22, input);
    		}
			if(strcmp(buffer,"M")==0){
				printf("INPUT VAL?"); scanf("%f", &input); ecriture(18, input);
			}
			if(strcmp(buffer,"V")==0){
				printf("INPUT VAL?"); scanf("%f", &input); ecriture(14, input);
			}
			if(strcmp(buffer,"C")==0){
				printf("INPUT VAL?"); scanf("%f", &input); ecriture(16, input);
			}
			if(strcmp(buffer,"L")==0){
				printf("INPUT VAL?"); scanf("%f", &input); ecriture(00, input);
			}
    	}else if(!strcmp(buffer, "E")){
    		printf("|### -\tQUIT MODBUS CLI  - ###|\n");
    		arret(SIGKILL);
    	}
    }


    close(sock_CLIENT);
    exit(0);
}
