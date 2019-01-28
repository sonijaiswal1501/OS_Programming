#include<stdio.h>
#include<pthread.h>

int count = 0;

void* incThread(void *);
void* decThread(void *);


int main()
{
	pthread_t idInc, idDec;

	pthread_create(&idInc, NULL, incThread, NULL);
	pthread_create(&idDec, NULL, decThread, NULL);

	pthread_join(idInc, NULL);
	pthread_join(idDec, NULL);

	return 0;
}


void* incThread(void *data)
{
	while(1)
	{
	   count++;
	   printf("Incthread: %d\n", count);
	}
}

void* decThread(void *data)
{
	while(1)
	{
	   count--;
	   printf("Decthread: %d\n", count);
	}
}


