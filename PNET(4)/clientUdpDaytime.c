#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char** argv, char** env) {
	struct sockaddr_in to;
	struct hostent* toinfo;
	
	if (argc < 2) {
		fprintf(stderr, "Format : %s <serveur>\n", argv[0]);
		return(1);
	}

	to.sin_family = PF_INET;
	toinfo = gethostbyname(argv[1]);
	if (toinfo == NULL) {
		perror("Erreur de gethostbyname()");
		return -1;
	}
	to.sin_port = htons(13);
	memcpy(&to.sin_addr.s_addr, toinfo->h_addr_list[0], toinfo->h_length);
	printf("Adresse : %d.%d.%d.%d\n",
		to.sin_addr.s_addr & 0xFF,
		(to.sin_addr.s_addr & 0xFF00) >> 8,
		(to.sin_addr.s_addr & 0xFF0000) >> 16,
		(to.sin_addr.s_addr & 0xFF000000) >> 24
	);
	
	int desc = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (desc == -1) {
		perror("Erreur socket");
		return -1;
	}
	char buffer[48];
	int rtr = sendto(desc, buffer, sizeof(buffer), 0, (struct sockaddr *)&to, sizeof(to));
	if (rtr == -1) {
		perror("Erreur d'envoi");
		return -1;
	}
	unsigned from, fromlen;

	rtr = recvfrom(desc, buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen);
	if (rtr == -1) {
		perror("Erreur de reception");
		return -1;
	}
	printf("%s\n", buffer);

	rtr = close(desc);
	if (rtr == -1) {
		perror("Erreur de fermeture");
		return -1;
	}
	/*	fin	*/
	return (0);
}