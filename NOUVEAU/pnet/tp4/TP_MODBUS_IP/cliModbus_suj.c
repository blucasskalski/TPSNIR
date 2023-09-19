/*************************************************************************************************/
/* Prog client tcp  Modbus            		            */
/* PM v2.0              		                        */
/* 6/10/20                          		            */
/* client TCP Modbus                		            */
/* gcc -Wall -o cliModbus cliModbus_suj.c modbus.o -lm	*/
/*************************************************************************************************/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <signal.h>
//header "maison" à ne pas retirer !
#include "modbus.h"

int sock_CLIENT;

void arret(int sig)
{
	printf(" \nARRET PROG CLIENT SOCKET   ---> echo \n");
	close(sock_CLIENT);
	kill(getpid(), SIGKILL);
}

int main(int argc, char **argv)
{
	//structure d'adresse cliente
	struct sockaddr_in sin;
	unsigned long hostAddr = 0; //pour adresse ip
								/* declaration de toute variable utile pour lire / ecrire les paramètres modbus*/
	/* Attache routine sortie correcte sur CTRL-C */
	signal(SIGINT, arret);
	bzero((char *)&sin, sizeof(sin));
	if (argc == 2)
	{
		// ip automate saisie ligne de commande
		hostAddr = (inet_addr(argv[1]));
		hostAddr &= 0xFFFFFFFF;
		sin.sin_addr.s_addr = INADDR_ANY;
		//Q2.1 //adresse ip du distant à renseigner  à partir de l'adresse ip saisie sur ligne de commande
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
	if ((sock_CLIENT = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("client:pb creation socket");
		exit(-1);
	}
	//Q2.3 demande de connexion au serveur
	if (connect(sock_CLIENT, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("client:pb connexion au serveur par socket");
		exit(-1);
	}
	printf("hostAddr : %lX\n", hostAddr);
	printf("N socket cliente %d\n", sock_CLIENT);
	//Q3 menu utilisateur
	int etape = 0;
	int status = 0; //1 = lect / 2 = ecrits
	while (1)
	{
		char buf[20];
		int save = 0;
		if (etape == 0)
		{
			printf("Tapez votre choix operation : 1 lecture , 2 ecriture , e pour sortir\n");
			scanf("%s", buf);
			if (buf[0] == 49)
			{
				status = 1;
				printf("parametre : BT1 tension batterie1  ; BT2 tension batterie2; BT3 tension batterie3; BT4 tension batterie4;\n"
				"C1 : courant charge batterie1 ; C2 : courant charge batterie2 ; C3 : courant charge batterie3 ; C4 : courant charge batterie4 ;\n"
				"P pente ; M masse ; V vitesse; C couple; L:local / distant\n");
				etape = 1;
			}
			else if (buf[0] == 50)
			{
				status = 2;
				printf("parametre : P pente ; M masse ; V vitesse ; C couple ;L:local / distant\n");
				etape = 1;
			}
			else if (buf[0] == 101)
			{
				close(sock_CLIENT);
				exit(0);
			}
		}
		else if (etape == 1)
		{
			char *choice[14] = {"BT1", "BT2", "BT3", "BT4", "C1", "C2", "C3", "C4", "P", "M", "V", "C", "L"};
			char *nombre[14] = {"40033", "40035", "40037", "40039", "40041", "40043", "40045", "40047", "40023", "40019", "40015", "40017", "40001"};
			scanf("%s", buf);
			for (int i = 0; i < 13; i++)
			{
				if (strcmp(buf, choice[i]) == 0)
				{
					save = i;
				}
			}
			if (status == 1)
			{
				float value = lecture((atoi(nombre[save])) - 40001);
				printf("Value : %f\n", value);
			}
			else if (status == 2)
			{
				printf("Valeur ? ");
				scanf("%s", buf);
				buf[strlen(buf)] = 0;
				ecriture(atoi(nombre[save]) - 40001, atoi(buf));
			}
			etape = 0;
		}
	}
	close(sock_CLIENT);
	exit(0);
}
