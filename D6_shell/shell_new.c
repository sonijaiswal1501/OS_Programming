#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<string.h>

#define BUFFER_LEN 128


int main(int argc, char const *argv[])
{
	char data[BUFFER_LEN];
	char* argv1[100];
	char* path = "/bin/";
	char file_path[20];
	
	while(1)
	{
	   printf("SS@ ");
	   
	   if(!fgets(data, BUFFER_LEN, stdin))
		break;

	   if(strcmp(data, "exit\n") == 0)
		break;

	   char *token;
	   token = strtok(data, " ");
	   
	   int i=0;

	   while(token != NULL)
	   {
		argv1[i] = token;
		token = strtok(NULL," ");
		i++;
	   }

	   argv1[i] = NULL;	   
	   
	   strcpy(file_path, path);
	   strcat(file_path, argv1[0]);

	   for(i=0; i<strlen(file_path); i++)
	   {
		if(file_path[i] == '\n')
			file_path[i] = '\0';
	   }

	   int pid = fork();
	
	   if(pid == 0)
	   {
		execvp(file_path, argv1);
		//execl(file_path , "argv[1]", NULL);
           }
	   else
	   {
		wait(NULL);
		
	   }
         }
	    return 0;
}





