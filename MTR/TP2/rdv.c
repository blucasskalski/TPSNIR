#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

#define N 3

pthread_t tid[3];

//Initialisation s�maphores et variable
sem_t MUTEX, ATTENTE;
int nb_att = 0;

void b_sync();

void f1() {
	sleep(1); printf("(1)f1 synchronizing ...\n");
	sleep(1); printf("(2)f1 synchronizing ...\n");
	sleep(1); printf("(3)f1 synchronizing ...\n");
	b_sync();
	printf("f1 synchronization done ...\n");
	/* instructions ... */
}
void f2() {
	sleep(1); printf("(1)f2 synchronizing ...\n");
	sleep(1); printf("(2)f2 synchronizing ...\n");
	sleep(1); printf("(3)f2 synchronizing ...\n");
	sleep(1); printf("(5)f2 synchronizing ...\n");
	sleep(1); printf("(6)f2 synchronizing ...\n");
	b_sync();
	printf("f2 synchronization done ...\n");
	/* instructions ... */
}
void f3() {
	sleep(1); printf("(1)f3 synchronizing ...\n");
	b_sync();
	printf("f3 synchronization done ...\n");
	/* instructions ... */
}

void b_sync() {
	/*------------------------------*/
	//S�maphore MUTEX rendu
	sem_wait(&MUTEX);
	//Incr�mentation de nb_att --> Une t�che a pris le MUTEX
	nb_att++;
	/*------------------------------*/
	if (nb_att == N) { // SI N t�ches ont prisent le MUTEX
		/*------------------------------*/
		//Prise du s�maphore ATTENTE N fois
		for (int i = 1; i <= N; i++) {
			sem_post(&ATTENTE);
		}
		/*------------------------------*/
		nb_att = 0;
		//Prise du s�maphore MUTEX de nouveau
		sem_post(&MUTEX);
	}
	else { //Sinon
		/*------------------------------*/
		//Reprise du MUTEX et ATTENTE rendu
		sem_post(&MUTEX);
		sem_wait(&ATTENTE);
		/*------------------------------*/
	}
}

int main() {
	int err;
	/*------------------------------*/
	//Initialisation des s�maphores
	sem_init(&ATTENTE, 0, 0);
	sem_init(&MUTEX, 0, 1);
	/*------------------------------*/
	err = pthread_create(&(tid[0]), NULL, (void* (*)(void*))f1, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	err = pthread_create(&(tid[1]), NULL, (void* (*)(void*))f2, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	err = pthread_create(&(tid[2]), NULL, (void* (*)(void*))f3, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	/* Attendre la fin de leur ex�cutions + destruction de ce qui doit
	l'�tre*/
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	/*------------------------------*/
	//D�struction des s�maphores
	sem_destroy(&ATTENTE);
	sem_destroy(&MUTEX);
	/*------------------------------*/
		return 0;
}