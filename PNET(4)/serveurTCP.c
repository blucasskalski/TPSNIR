#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SOCKET_ERROR -1

int main(int argc, char** argv, char** env) {
	struct sockaddr_in localaddr;
	localaddr.sin_family = AF_INET; /* Protocole internet */
	int listen_socket = socket(AF_INET, SOCK_STREAM, 0);

		/* Toutes les adresses IP de la station 
		localaddr.sin_addr.s_addr = htonl(INADDR_ANY); */
	
	/* Utilisation de l'adresse locale */
	localaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	/* port d'écoute par défaut au-dessus des ports réservés */
	localaddr.sin_port = htons(430);
	if (bind(listen_socket, (struct sockaddr*)&localaddr, sizeof(localaddr)) == SOCKET_ERROR){
		perror("Erreur dans la fonction bind");
		return -1;
	}

	if (listen(listen_socket, 10) == SOCKET_ERROR) {
		perror("Erreur dans la fonction listen");
		return -1;
	}

	Sockaddr_in Appelant;
	/* structure destinée à recueillir les renseignements sur l'appelant */
	Appelantlen = sizeof(from);
	accept(socket_local,(struct sockaddr*)&Appelant, &Appelantlen);

	int buffer[sizeof(argv[1])];
	rtr = recv(listen_socket, buffer, sizeof(buffer), 0);
	if (rtr == -1) {
		perror("Erreur de recv()");
		return -1;
	}

	int rtr = send(listen_socket, buffer, sizeof(buffer), 0);
	if (rtr == -1) {
		perror("Erreur de send()");
		return -1;
	}

	return 0;
}