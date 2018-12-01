/* Parent -> input 2 (int) ====> Child sum(int, int) =====> Parent result */


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define BSIZE 4

int main(int argc, char const *argv[])
{
	int i, n1, n2, fd1[2], fd2[2], sum;	
	unsigned char input[BSIZE], data1[BSIZE], data2[BSIZE];
	pid_t id;
	
	pipe(fd1);
	pipe(fd2);

	id = fork();
	
	if(0 == id)
	{
	    printf("\nChild\n");
	    close(fd1[1]);	    
	    read(fd1[0], data1, sizeof(data1));	
   	    read(fd1[0], data2, sizeof(data2));	    
	    
	    n1 = atoi(data1);
	    n2 = atoi(data2);
	    sum = n1 + n2;
	   	    	       
	    close(fd1[0]);
	    close(fd2[0]);
	    write(fd2[1], &sum, BSIZE);
	    close(fd2[1]);
	 }
	else
	{
	    printf("\nParent\n");
	     close(fd1[0]);
	     
	    printf("\nEnter the two numbers: ");
	    for(i=0; i<2; i++)
	    {	 
	      scanf("%s", input);	
	      write(fd1[1], input , sizeof(input));
	    }
	       
	    close(fd1[1]);
	    close(fd2[1]);
	    read(fd2[0], &sum, 15);
	    printf("\nSum  of two number: %d\n", sum);
	    close(fd2[0]);
	 }
	
	
	return 0;
} 
