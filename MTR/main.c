/*--------------------------------------------*/
// Programme :	main.c
// Language:	C (standard)
//  
//
/*--------------------------------------------*/


//	Création de Thread
//#include <pthread.h>
//int pthread_create(pthread_t* restrict thread,
//	const pthread_attr_t* restrict attr,
//	void* (*start_routine)(void*),
//	void* restrict arg);
// 
// deux thread, sync on end ---- /!\ lier avec -lpthread


#include <pthread.h>
#include <stdio.h>

int* f1(int* pi);
int* f2(int* pi);

int main() {
	int a, b;
	int* ret1 = 0, * ret2 = 0;
	pthread_t th1, th2;
	a = 10;
	b = 20;
	/* création des deux threads */
	/* Attendre la fin de leur exécutions */
	printf("main) th1 : *ret1 = %3d, &res = %p\n", *ret1, ret1);
	printf("main) th2 : *ret2 = %3d, &res = %p\n", *ret2, ret2);
	return 0;
}


int* f1(int* pi) {
	static int res = 0;
	res = *pi + 1;
	printf("th1 : res = %3d, pi = %p, &res = %p, *pi = %3d\n",
		res, pi, &res, *pi);
	return &res;
}
int* f2(int* pi) {
	static int res = 0;
	res = *pi + 1;
	printf("th2 : res = %3d, pi = %p, &res = %p, *pi = %3d\n",
		res, pi, &res, *pi);
	return &res;
}