#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
pthread_t tid[4];
sem_t M_Lect;
sem_t M_Red;
sem_t Red;
int Lect;


void commencerLect()
{
	sem_wait(&M_Lect);
	Lect++;
	if (Lect == 1)
		{
			sem_wait(&Red);
		}
	sem_post(&M_Lect);
}

void finiLect()
{
	sem_wait(&M_Lect);
	Lect--;
	if (Lect == 0)
		{
			sem_post(&Red);
		}
	sem_post(&M_Lect);
}

void commencerEcr ()
{
	sem_wait(&M_Red);
	sem_wait(&Red);
}

void finiEcr ()
{
	sem_post(&Red);
	sem_post(&M_Red);
}

void algoPro ()
{

}

void algoRed ()
{

}
int main ()
{
	sem_init(&M_Lect, 0, 1);
	sem_init(&M_Red, 0, 1);
	sem_init(&Red, 0, 1);
	pthread_create(&(tid[0]), NULL, (void *) algoPro, NULL);
	pthread_create(&(tid[1]), NULL, (void *) algoPro, NULL);
	pthread_create(&(tid[2]), NULL, (void *) algoPro, NULL );
	pthread_create(&(tid[3]), NULL, (void *) algoRed, NULL);
	pthread_create(&(tid[3]), NULL, (void *) algoRed, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	sem_destroy(&M_Lect);
	sem_destroy(&M_Red);
	sem_destroy(&Red);
}
