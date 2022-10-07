#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 7777

/* ... */
int main(int argc, char** argv, char** env) {
	struct sockaddr_in to;
	struct hostent* toinfo;
	//TODO
	if (argc < 2) {
		fprintf(stderr, "Format : %s <serveur>\n", argv[0]);
		return(1);
	}
	int desc = socket(AF_INET, SOCK_DGRAM, 0);
	if (desc == -1) {
		perror("Erreur socket");
		return -1;
	}
	to.sin_family = PF_INET;
	toinfo = gethostbyname(argv[1]);
	if (toinfo == NULL) {
		perror("Erreur de gethostbyname()");
		return -1;
	}
	memcpy(&to.sin_addr.s_addr, toinfo->h_addr_list[0], toinfo->h_length);
	to.sin_port = htons(PORT);
	
	return (0);
}