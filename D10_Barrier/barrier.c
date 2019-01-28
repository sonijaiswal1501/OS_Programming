#include<stdio.h>
//#define __USE_XOPEN2K
#include<pthread.h>
#include<unistd.h>


void* lcd(void *);
void* serial(void *);
void* update(void *);


int ir = 0;
pthread_barrier_t initbar;


int main()
{
	pthread_t lcdid, serialid, updateid;
	pthread_barrier_init(&initbar, NULL, 3);

	pthread_create(&lcdid, NULL, lcd, NULL);
	pthread_create(&serialid, NULL, serial, NULL);
	pthread_create(&updateid, NULL, update, NULL);

	pthread_join(lcdid, NULL);
	pthread_join(serialid, NULL);
	pthread_join(updateid, NULL);

	pthread_barrier_destroy(&initbar);

	return 0;
}

void* lcd(void *data)
{	
	   printf("LCD: Init started\n");
	   sleep(5);
	   pthread_barrier_wait(&initbar);	   
	   printf("LCD: end: Task started\n");
}

void* serial(void *data)
{	
	   printf("SERIAL: Init started\n");
	   sleep(7);
	   pthread_barrier_wait(&initbar);	   
	   printf("SERIAL: end: Task started\n");	
}

void* update(void *data)
{	   
	   printf("UPDATE: Init started\n");
	   sleep(9);	
	   pthread_barrier_wait(&initbar);   
	   printf("UPDATE: end: Task started\n");	
}

