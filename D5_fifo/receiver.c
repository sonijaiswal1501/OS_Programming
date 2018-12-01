/* Write a program to get FIFO behavior (receiver) */


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int fd;
	unsigned char buff[128];
		
	fd = open("myfifo", O_RDONLY);
	read(fd, buff,sizeof(buff));
	printf("\nRead the fifo file :%s\n", buff);
	close(fd);

	return 0;
}
	
