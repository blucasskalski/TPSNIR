#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char** argv, char** env{
	if (argc < 3) {
		fprintf(stderr, "usage : clientTCP <server> <ASCIIString>\n");
		return 1;
	}
	return 0;
}