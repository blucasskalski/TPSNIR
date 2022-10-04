#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

//	amanu.lyceelafayette.fr:7777

int main(int argc, char** argv, char** env) {
	if (argc < 3) {
		fprintf(stderr, "usage : clientTCP <server> <ASCIIString>\n");
		return 1;
	}
	struct sockaddr_in to;
	struct hostent* toinfo;
	toinfo = gethostbyname(argv[1]);
	to.sin_family = AF_INET;
	memcpy(&to.sin_addr.s_addr, toinfo->h_addr_list[0], toinfo->h_length);
	to.sin_port = htons(7777);


	//Creation socket
	int skt = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(skt, (struct sockaddr*)&to, sizeof(to)) == -1){
		perror("Erreur de connection : "); return -1;
	}

	int snd = send(skt, argv[1], sizeof(argv[1]), 0);
	if (snd == -1){
		perror("Erreur d'envoi des données : "); return -1;
	}
	return 0;
}