#include <stdio.h>
#include "ouvrir.h"
#include <unistd.h>
#include <fcntl.h>

int lister(char *arg);

int main(int argc, char **argv){
	int n = 1;
	int *C;
	while(argv[n]){
		if(*argv[n] == '-'){
			while((read(0, C, 1)));
		}else{
			lister(argv[n]);
		}
		n++;
	}
	return 0;
}

int lister(char *arg){
	int fd, nblus = 0;
	char buf[256];
	fd = ouvrir(arg);
	while((nblus=read(fd,buf,sizeof(buf)))){
		if((write(1,buf,nblus))<0)
			return -1;
	}
	return 0;
}

