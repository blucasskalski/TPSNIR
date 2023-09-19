#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

pthread_t tid[5];
int tab[2];
sem_t M_Lect, M_Red, Red;
int lect = 0;
void c_lect(void);
void f_lect(void);
void c_ecrit(void);
void f_ecrit(void);
void lecteur(void);
void redacteur(void);

int main()
{
    sem_init(&M_Lect, 0, 1);
    sem_init(&M_Red, 0, 1);
    sem_init(&M_Red, 0, 1);
    int err;
    err = pthread_create(&(tid[0]), NULL, (void *)lecteur, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[1]), NULL, (void *)lecteur, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[2]), NULL, (void *)lecteur, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[3]), NULL, (void *)redacteur, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[4]), NULL, (void *)redacteur, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    sem_destroy(&M_Lect);
    sem_destroy(&M_Red);
    sem_destroy(&Red);
}
void c_lect()
{
    printf("c_lect\n");
    sem_wait(&M_Lect);
    sem_post(&M_Lect);
    lect++;
    if (lect == 1)
    {
        sem_wait(&Red);
    }
    sem_post(&M_Lect);
}

void f_lect()
{
    printf("f_lect\n");
    sem_wait(&M_Lect);
    lect--;
    if (lect == 0)
    {
        sem_post(&Red);
    }
    sem_post(&M_Lect);
}

void c_ecrit()
{
    printf("c_ecrit\n");
    sem_wait(&M_Red);
    sem_wait(&Red);
}

void f_ecrit()
{
    printf("f_ecrit\n");
    sem_post(&Red);
    sem_post(&M_Red);
}
 
void redacteur()
{
    c_ecrit();
    //Écrire entier dans la zone partagée
    srand(time(NULL));
    tab[1] = rand() % 100000;
    printf("redacteur\n");
    f_ecrit();
}

void lecteur()
{
    c_lect();
    //Copier les deux entiers partagé en local
    int tab2[2];
    tab2[0] = tab[0];
    tab2[1] = tab[1];
    printf("copy : %d\n", tab2[0]);
    printf("copy2 : %d\n", tab2[1]);
    printf("lecteur\n");
    f_lect();
}