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

	return 0;
}