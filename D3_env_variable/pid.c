/* Write a program for getpid() and getppid() */


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{

	printf("\nChild's pid : %d", getpid());
	printf("\nParent's pid : %d\n", getppid());

	return 0;
}

