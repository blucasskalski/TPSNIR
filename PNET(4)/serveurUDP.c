#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 9999

int main(int argc, char** argv, char** env) {
	inet_addr("127.0.0.1");
	struct sockaddr_in localaddr;
	localaddr.sin_family = PF_INET;
	localaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	localaddr.sin_port = htons(PORT);

	int liso = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (liso == -1) {
		perror("Erreur socket");
		return -1;
	}

	if (bind(liso, (struct sockaddr*)&localaddr, sizeof(localaddr)) == SO_ERROR) {
		perror("Erreur de bind");
		return -1;
	}
	return 0;
}