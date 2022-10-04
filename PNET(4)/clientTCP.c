#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

//	amanu.lyceelafayette.fr:7777n

int main(int argc, char** argv, char** env) {
	if (argc < 3) {
		fprintf(stderr, "usage : clientTCP <server> <ASCIIString>\n");
		return 1;
	}

	struct sockaddr_in to;
	struct hostent* toinfo;
	int desc = socket(AF_INET, SOCK_STREAM, 0);
	if (desc == -1) {
		perror("Erreur socket");
		return -1;
	}
	to.sin_family = AF_INET;
	toinfo = gethostbyname(argv[1]);
	if (toinfo == NULL) {
		perror("Erreur de gethostbyname()");
		return -1;
	}
	memcpy(&to.sin_addr.s_addr, toinfo->h_addr_list[0], toinfo->h_length);
	//printf("%d.%d.%d.%d", to.sin_addr.s_addr & 0xFF000000, to.sin_addr.s_addr & 0x00FF0000 >> 8, to.sin_addr.s_addr & 0x0000FF00 >> 16, to.sin_addr.s_addr & 0x000000FF >> 24);
	//printf("%ls\n", toinfo->h_addr_list[0] & 0x0000FF000);
	to.sin_port = htons(7777);

	if (connect(desc, (struct sockaddr*)&to, sizeof(to)) == -1) {
		perror("erreur connection");
		return -1;
	}
	
	int rtr = send(desc, argv[2], strlen(argv[2]), 0);
	if (rtr == -1) {
		perror("erreur d'envoi");
		return -1;
	}

	int buffer[sizeof(argv[1])];
	rtr = recv(desc, buffer, sizeof(buffer), 0);
	if (rtr == -1) {
		perror("erreur de reception");
		return -1;
	}

	printf("Sortie : %s\n", buffer);

	//rtr = close(desc);
	//if (rtr == -1) {
	//	perror("erreur de fermeture : ");
	//	return -1;
	//}

	return 0;
}