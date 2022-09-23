#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>

pthread_t tid[5];
sem_t M_Lect, M_Red, Red;
int Lect=0;
int Ecr=-1;
int tab[2];
int rnd;
void commencerLire();
void finirLecture();
void commencerEcrire();
void finirEcrire();
void algoProd();
void algoCons();

int main (){
	srand(time(NULL));
	sem_init(&M_Lect, 0, 1);
	sem_init(&M_Red	, 0, 1);
	sem_init(&Red	, 0, 1);
	pthread_create(&(tid[0]), NULL, (void *) algoProd	, NULL);
	pthread_create(&(tid[1]), NULL, (void *) algoProd	, NULL);
	pthread_create(&(tid[2]), NULL, (void *) algoCons	, NULL);
	pthread_create(&(tid[3]), NULL, (void *) algoCons	, NULL);
	pthread_create(&(tid[4]), NULL, (void *) algoCons	, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	algoCons();
	sem_destroy(&M_Lect);
	sem_destroy(&M_Red);
	sem_destroy(&Red);
}

void commencerLire() {
	sem_wait(&M_Lect);
	Lect++;
	if (Lect == 1) {
		sem_wait(&Red);
	}
	printf("commencerLire\n");
	sem_post(&M_Lect);
}

void finirLecture() {
	sem_wait(&M_Lect);
	printf("finirLire\n");
	Lect--;
	if (Lect == 0) {
		sem_post(&Red);
	}
	sem_post(&M_Lect);
}

void commencerEcrire() {
	sem_wait(&M_Red);
	Ecr++;
	sem_wait(&Red);
	printf("commencerEcrire\n");
}

void finirEcrire() {
	sem_post(&Red);
	printf("finirEcrire\n");
	sem_post(&M_Red);
}

void algoProd() {
	int r = rand();
	printf("alogProd\n");
	commencerEcrire();
	//TODO écrire entier dans tab[1];
	//printf("\nalgoProd\n\tentier rand: %i\n", r);
	tab[Ecr] = r;
	//printf("\tLect : %i\n", Lect);
	//printf("\tEcr : %i\n", Ecr);
	finirEcrire();
}

void algoCons() {
	printf("alogCons\n");
	commencerLire();
	//TODO Copie des entiers vers var locale puis affichage
	int loc0, loc1;
	loc0 = tab[0];
	loc1 = tab[1];
	printf("\n\tvaleur de tab[0] : %i\n\tvaleur de tab[1] : %i\n", loc0, loc1);
	//printf("\tLect : %i\n", Lect);
	finirLecture();
}