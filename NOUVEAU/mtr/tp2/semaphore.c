#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABSZ 4
pthread_mutex_t lock; //creation du mutex
pthread_t th1, th2;   //creation des deux thread

void f1(int *tab)
{
    int i;
    printf("\t\t\tf1 started...\n");
    for (i = 0; i < 10; i++)
    {
        /* P */
        printf("\t\t\t\t\t\tf1 tentative de prise du mutex1 \n");
        pthread_mutex_lock(&lock); //tentative de prise du mutex
        printf("\t\t\t\t\t\tf1 prise effective du mutex1 (P)\n\n\n\n\n");

        tab[0]++;
        tab[1] = tab[0] + 1;
        sleep(rand() % 4);
        tab[2] = tab[1] + 1;
        tab[3] = tab[2] + 1;
        /* V */
        printf("\t\t\t\t\t\tf1 rendre mutex1 (V) \n");
        pthread_mutex_unlock(&lock); //rendre mutex
    }
    printf("fin1");
}
void f2(int *tab)
{
    int i;
    printf("\t\t\t\t\t\tf2 started...\n");
    for (i = 0; i < 10; i++)
    {
        /* P */
        printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 tentative de prise du mutex2 \n");
        pthread_mutex_lock(&lock); //tentation de prise du mutex
        printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 prise effective du mutex2 (P)%d\n\n\n\n\n", i);
        tab[0] = tab[0] + ((i % 2) ? 100 : -100);
        tab[1] = tab[1] + ((i % 2) ? 100 : -100);
        sleep(rand() % 4); // changement de contexte artificiel
        tab[2] = tab[2] + ((i % 2) ? 100 : -100);
        tab[3] = tab[3] + ((i % 2) ? 100 : -100);
        /* V */
        printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 rendre mutex2 (V) \n");
        pthread_mutex_unlock(&lock); //rendre mutex
    }
    printf("fin2");
}
void printTab(int *tab)
{
    int i;
    /* P */
    printf("PrintTab tentative de prise du mutex3 \n");
    pthread_mutex_lock(&lock); //tentation de prise du mutex
    printf("PrintTab prise effective du mutex3 (P)\n");
    for (i = 0; i < TABSZ; i++)
        printf("[%d] = %d\n", i, tab[i]);
    printf("\n");
    /* V */
    printf("PrintTab rendre mutex3 (V) \n");
    pthread_mutex_unlock(&lock); //rendre mutex
}
int main()
{
    int tab[TABSZ] = {0, 0, 0, 0}; // ressource partagée
    int i = 0;
    /* création des deux threads et du mutex/sémaphore*/
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("\n mutex init failed\n");
        return 1;
    }
    pthread_create(&th1, NULL, (void *)f1, &tab);
    pthread_create(&th2, NULL, (void *)f2, &tab);

    for (i = 0; i < 10; i++)
    {
        printTab(tab);
        sleep(1);
    }
/*
Sans mettre le mutex en place, les valeurs de tab sont aléatoires, puisque les fonctions f1, f2 sont
exécuter parallélement.

[0] = 10
[1] = 11
[2] = 12
[3] = 13
    Le resultat est cohérent puisque dans f1, nous mettons le tableau aux valeur 10, 11, 12 et 13.
    Puis dans f2, à chaque boucle for, i incrémente, il commence à 0. 0 modulo 2 équivaut à false,
    donc notre valeur 10 est décrementé de 100, puis i incrémentre de nouveau, 1 modulo 2 équivaut
    à true, -90 incrémente de 100. Donc à la fin de la boucle dans f2, pour i = 9, notre valeur
    reviendra à sa valeur initial = 10, 11, 12 et 13.
*/

    pthread_mutex_destroy(&lock);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    /* Attendre la fin de leur exécutions + destruction de ce qui doit l'être*/
    printTab(tab);
    return 0;
}