#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int *f1(int *pi)
{
    printf("Pendant1\n");
    static int res = 0;
    res = *pi + 1;
    printf("th1 : res = %3d, pi = %p, &res = %p, *pi = %3d\n", res, pi, &res, *pi);
    return &res;
}
int *f2(int *pi)
{
    printf("Pendant2\n");
    static int res = 0;
    res = *pi + 1;
    printf("th2 : res = %3d, pi = %p, &res = %p, *pi = %3d\n", res, pi, &res, *pi);
    return &res;
}
int main()
{
    int a, b;
    int *ret1 = 0, *ret2 = 0;
    pthread_t th1, th2;
    a = 10;
    b = 20;
    /* création des deux threads */
    printf("Avant la création du thread1.\n");
    pthread_create(&th1, NULL, (void *)f1, &a);
    pthread_join(th1, (void *)&ret1);
    printf("Après la création du thread1.\n");
    printf("Avant la création du thread2.\n");
    pthread_create(&th2, NULL, (void *)f2, &b);
    pthread_join(th2, (void *)&ret2);
    printf("Après la création du thread2.\n");
    /* Attendre la fin de leur exécutions */

      printf("main) th1 : *ret1 = %3d, &res = %p\n", *ret1, ret1);
      printf("main) th2 : *ret2 = %3d, &res = %p\n", *ret2, ret2);
    return 0;
}