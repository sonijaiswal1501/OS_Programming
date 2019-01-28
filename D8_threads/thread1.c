#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


pthread_t tid[2];


void* thread_fun(void *);


int main()
{
	

	printf("\nCreating thread\n");
	pthread_create(&(tid[0]), NULL, thread_fun, "\nHello");
	pthread_create(&tid[1], NULL, thread_fun, "\nByee");
	printf("\nCreated thread\n");
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	return 0;
}

void* thread_fun(void *arg)
{
	
	printf("\n%s\n",(char*)arg);
	

	return NULL;
}

