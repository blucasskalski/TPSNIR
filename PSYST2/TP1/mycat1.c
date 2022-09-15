#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char buffer[1024];
	int nblus;
	for(;;){
		nblus = read(0,buffer,sizeof(buffer));

		if(nblus<=0)
			break;
		if((write(1, buffer, nblus))<0){
			perror("write");
			return -1;
		}
	}
}
