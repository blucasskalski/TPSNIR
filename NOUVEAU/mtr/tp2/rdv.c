#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

pthread_t tid[3];
sem_t mutex, attente;
void barriere(void);
int nb_att = 0;
int n = 3;

void f1()
{
    sleep(1);
    printf("(1)f1 synchronizing ...\n");
    sleep(1);
    printf("(2)f1 synchronizing ...\n");
    sleep(1);
    printf("(3)f1 synchronizing ...\n");
    /* Attente du RDV */
    barriere();
    printf("f1 synchronization done ...\n");
    /* instructions ... */
}

void f2()
{
    sleep(1);
    printf("(1)f2 synchronizing ...\n");
    sleep(1);
    printf("(1)f2 synchronizing ...\n");
    sleep(1);
    printf("(1)f2 synchronizing ...\n");
    sleep(1);
    printf("(1)f2 synchronizing ...\n");
    sleep(1);
    /* Attente du RDV */
    barriere();
    printf("f2 synchronization done ...\n");
    /* instructions ... */
}

void f3()
{
    sleep(1);
    printf("(1)f3 synchronizing ...\n");
    /* Attente du RDV */
    barriere();
    printf("f3 synchronization done ...\n");
    /* instructions ... */
}

void barriere()
{
    sem_wait(&mutex);
    nb_att++;
    if (nb_att == n)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            sem_post(&attente);
        }
        nb_att = 0;
        sem_post(&mutex);
    }
    else
    {
        sem_post(&mutex);
        sem_wait(&attente);
    }
}

int main()
{
    int err;
    sem_init(&mutex, 0, 1);
    sem_init(&attente, 0, 0);
    err = pthread_create(&(tid[0]), NULL, (void *(*)(void *))f1, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[1]), NULL, (void *(*)(void *))f2, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[2]), NULL, (void *(*)(void *))f3, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    /* Attendre la fin de leur exécutions + destruction de ce qui doit
l'être*/

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    sem_destroy(&mutex);
    sem_destroy(&attente);
    return 0;
}