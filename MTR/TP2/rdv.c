#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
pthread_t tid[3];
...
...
void f1() {
	sleep(1); printf("(1)f1 synchronizing ...\n");
	sleep(1); printf("(2)f1 synchronizing ...\n");
	sleep(1); printf("(3)f1 synchronizing ...\n");
	/* Attente du RDV */
	printf("f1 synchronization done ...\n");
	/* instructions ... */
}
void f2() {
	sleep(1); printf("(1)f2 synchronizing ...\n");
	sleep(1); printf("(2)f2 synchronizing ...\n");
	sleep(1); printf("(3)f2 synchronizing ...\n");
	sleep(1); printf("(5)f2 synchronizing ...\n");
	sleep(1); printf("(6)f2 synchronizing ...\n");
	/* Attente du RDV */
	printf("f2 synchronization done ...\n");
	/* instructions ... */
}
void f3() {
	sleep(1); printf("(1)f3 synchronizing ...\n");
	/* Attente du RDV */
	printf("f3 synchronization done ...\n");
	/* instructions ... */
}
int main() {
	int i = 0;
	int err;
	...
		err = pthread_create(&(tid[0]), NULL, (void* (*)(void*))f1, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	err = pthread_create(&(tid[1]), NULL, (void* (*)(void*))f2, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	err = pthread_create(&(tid[2]), NULL, (void* (*)(void*))f3, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	/* Attendre la fin de leur exécutions + destruction de ce qui doit
	l'être*/
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	...
		return 0;
}