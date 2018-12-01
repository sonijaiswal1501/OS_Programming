/* Write a program to cp using system calls */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	int fd, fd1, count;
	unsigned char buff[120];
		
	
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	fd1 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	if(fd == -1)
	  perror("Error");	
	else
	 {
	   write(fd,"\nHelloWorld\n",11);
	   close(fd);
	 }
	fd = open(argv[1], O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd1 == -1)
	  perror("Error");
	else
	 {
	   
	   count = read(fd, buff, 120);
	   write(fd1, buff, count);
	   close(fd);
	   close(fd1);
	 }
	
	
	return 0;
} 
