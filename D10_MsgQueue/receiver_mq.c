#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>



int main()
{
	unsigned char buff[24];
	unsigned int prior;
	mqd_t cdacmq;
	struct mq_attr cdacattr;
	cdacattr.mq_flags =  0; cdacattr.mq_msgsize = 24; cdacattr.mq_maxmsg = 3; cdacattr.mq_curmsgs = 0;

	cdacmq = mq_open("/cmq", O_RDONLY , S_IRUSR | S_IWUSR, &cdacattr);

	if(-1 == cdacmq)
	   perror("\nError opening mq\n");

	mq_receive(cdacmq, buff,sizeof(buff), &prior);
	printf("\nRecieved message %s with priority %d\n", buff, prior);

	mq_close(cdacmq);

	return 0;
}

