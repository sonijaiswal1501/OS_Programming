/* Use system call for doing printf functionality (input using scanf and output using system call) */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int fd, fd1, count=0;
	unsigned char buff[120]={0};
	fd = open("syscall.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	printf("\nEnter the string :");
	scanf("%s", buff);		
		
	if(fd == -1)
	  perror("Error");	
	else
	 {
	   write(fd,buff,120);
	   close(fd);
	 }

	fd = open("syscall.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd1 == -1)
	  perror("Error");
	else
	 {	   
	   count = read(fd, buff, 120);
	   write(1, buff, count);
	   write(1, "\n", 1);
	   close(fd);	
	 }
	
	
	return 0;
} 
