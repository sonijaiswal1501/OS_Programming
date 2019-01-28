#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


pthread_t tid[3];


void* thread_fun(void *);


int main()
{
	int i=0, err;

	while(i < 4)
	{
	   err = pthread_create(&tid[i], NULL, &thread_fun, NULL);
	   
	   if(err != 0)
	       printf("\nThread can't create thread :[%s]", strerror(err));
	   else
	       printf("\nThread created successfully\n");

	   i++;
	}
	pthread_join(tid[2], NULL);

	//sleep(2);
	
	return 0;
}

void* thread_fun(void *arg)
{
	
	unsigned long i=0;
	pthread_t id = pthread_self();	 

	if(pthread_equal(id, tid[0]) != 0)  
	   printf("\nHello\n");
	else if(pthread_equal(id, tid[1]) != 0)
	   printf("\nByee\n");
	else
	   printf("\nHi\n");
	
	
	//for(i=0; i<(0xffffffff); i++);

	return NULL;
}

