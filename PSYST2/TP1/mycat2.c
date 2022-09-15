#include <stdio.h>
#include "ouvrir.h"
#include <unistd.h>

int main(int argc, char **argv){
	int fd, nblus = 0;
	char buf[256];
	fd = ouvrir(argv[1]);
	while((nblus=read(fd,buf,sizeof(buf))))
		if((write(1,buf,nblus))<0)
			perror("err lecture");
	return 0;
}
