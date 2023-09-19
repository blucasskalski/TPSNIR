/*
 *  CThread.h
 *  CThread
 *
 *  Created by Alexandre Facchin on 04/03/11.
 *  Copyright 2011 LTLF. All rights reserved.
 *
 */



#ifndef CTHREAD_H
#define CTHREAD_H

#include <pthread.h>

class CThread {
	
private:
	pthread_t thread;
	static void *thread_func(void *d) {
		((CThread *)d)->run(); 
		return 0;
	}
	
public:
	CThread() {
	}
	
	virtual ~CThread() {
	}
	
	virtual void run() = 0;
	
	void start() {
		pthread_create ( &thread, NULL, CThread::thread_func, (void*)this );
	}
	
	void stop() {
		pthread_exit (NULL);
	}
	
	void wait() {
		pthread_join (thread, NULL);
	}
	
};

#endif