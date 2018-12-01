#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define BSIZE 128

int main(int argc, char const *argv[])
{
	int i, choice, fd[2];	
	unsigned char cmd[BSIZE], data[BSIZE];
	pid_t id;
	
	pipe(fd);
	id = fork();
	start:
	if(0 < id)
	{  
	    do
	    {   printf("\nParent\n");
		close(fd[0]);
		printf("SS@");
		scanf("%s", cmd);
		write(fd[1], cmd, sizeof(cmd));
		close(fd[1]); 
	    }while(strcmp(cmd, "exit") != 0);
	
	}
	if(0 == id)
	{   printf("\nChild\n");
	    close(fd[1]);
	    read(fd[0], data, sizeof(data));  	    
	 
            if(strcmp(data, "ls") == 0)   	    
	        choice = 1;
	    else if(strcmp(data, "pwd") == 0)  
	        choice = 2;
	    else if(strcmp(data, "exit") == 0)  
	        choice = 3;
	    
	    switch(choice)
	    {
	      case 1: execl("/bin/ls", "-a","-l","-al", NULL);
		      break;
	      case 2: execl("/bin/pwd","-L", "-P", NULL); 
		      break;
	      case 3: execl("/bin/exit","/bin/exit", NULL);
		      break;
	    }
	   
	    close(fd[0]);
	}
	
	return 0;
} 
