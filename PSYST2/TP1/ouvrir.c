#include <fcntl.h>
#include <unistd.h>

int ouvrir(char *nom){
	int fd;
	if((fd = open(nom, O_RDONLY))<0){
		perror("erreur ouverture");
		return -1;
	}
	return fd;
}
