#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i = 9;
    int tab[4] = {-90, -89, -88, -87}; // ressource partagée
    tab[0] = tab[0] + ((i %2) ? 100 : -100);
    tab[1] = tab[1] + ((i % 2) ? 100 : -100);
    tab[2] = tab[2] + ((i % 2) ? 100 : -100);
    tab[3] = tab[3] + ((i % 2) ? 100 : -100);
    for (int i = 0; i < 4; i++)
        printf("[%d] = %d\n", i, tab[i]);
    printf("\n");
}