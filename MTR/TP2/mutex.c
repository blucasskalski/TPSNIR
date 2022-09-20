#include ...
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABSZ 4
...
...
void f1(int* tab) {
	int i;
	printf("\t\t\tf1 started...\n");
	for (i = 0; i < 10; i++) {
		/* P */
		printf("\t\t\t\t\t\tf1 tentative de prise du mutex \n");
		...
			printf("\t\t\t\t\t\tf1 prise effective du mutex (P)\n\n\n\n\n");
		tab[0] ++;
		tab[1] = tab[0] + 1;
		sleep(rand() % 4); // changement de contexte artificiel
		tab[2] = tab[1] + 1;
		tab[3] = tab[2] + 1;
		/* V */
		...
			printf("\t\t\t\t\t\tf1 rendre mutex (V) \n");
	}
}
void f2(int* tab) {
	int i;
	printf("\t\t\t\t\t\tf2 started...\n");
	for (i = 0; i < 10; i++) {
		/* P */
		printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 tentative de prise du mutex \n");
		...
			printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 prise effective du mutex (P)\n\n\n\n\n");
		tab[0] = tab[0] + ((i % 2) ? 100 : -100);
		tab[1] = tab[1] + ((i % 2) ? 100 : -100);
		sleep(rand() % 4); // changement de contexte artificiel
		tab[2] = tab[2] + ((i % 2) ? 100 : -100);
		tab[3] = tab[3] + ((i % 2) ? 100 : -100);
		/* V */
		...
			printf("\t\t\t\t\t\t\t\t\t\t\t\tf2 rendre mutex (V) \n");
	}
}

void printTab(int* tab) {
	int i;
	/* P */
	printf("PrintTab tentative de prise du mutex \n");
	...
		printf("PrintTab prise effective du mutex (P)\n");
	for (i = 0; i < TABSZ; i++)
		printf("[%d] = %d\n", i, tab[i]);
	printf("\n");
	/* V */
	...
		printf("PrintTab rendre mutex (V) \n");
}
int main() {
	int tab[TABSZ] = { 0,0,0,0 }; // ressource partagée
	int i = 0;
	int err;
	/* création des deux threads et du mutex/sémaphore*/
	...
		...
		...
		for (i = 0; i < 10; i++) {
			printTab(tab);
			sleep(1);
		}
	/* Attendre la fin de leur exécutions + destruction de ce qui doit
	l'être*/
	...
		...
		printTab(tab);
	...
		return 0;
}