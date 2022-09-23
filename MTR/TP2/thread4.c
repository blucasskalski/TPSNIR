#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
pthread_t tid[4];
sem_t M_Lect, M_Red, Red;
int Lect;
int tab[2];

void commencerLire(){
	sem_wait(&M_Lect);
	Lect++;
	if (Lect == 1){
		sem_wait(&Red);
	}
	sem_post(&M_Lect);
}

void finirLecture(){
	sem_wait(&M_Lect);
	Lect--;
	if (!Lect){
			sem_post(&Red);
		}
	sem_post(&M_Lect);
}

void commencerEcrire(){
	sem_wait(&M_Red);
	sem_wait(&Red);
}

void finirEcrire(){
	sem_post(&Red);
	sem_post(&M_Red);
}

void algoProd (){
	commencerEcrire();
	//TODO écrire entier dans tab[1];
	finirEcrire();
}

void algoCons (){

}
int main (){
	sem_init(&M_Lect, 0, 1);
	sem_init(&M_Red	, 0, 1);
	sem_init(&Red	, 0, 1);
	pthread_create(&(tid[0]), NULL, (void *) algoPro	, NULL);
	pthread_create(&(tid[1]), NULL, (void *) algoPro	, NULL);
	pthread_create(&(tid[2]), NULL, (void *) algoPro	, NULL);
	pthread_create(&(tid[3]), NULL, (void *) algoCons	, NULL);
	pthread_create(&(tid[3]), NULL, (void *) algoCons	, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	sem_destroy(&M_Lect);
	sem_destroy(&M_Red);
	sem_destroy(&Red);
}
