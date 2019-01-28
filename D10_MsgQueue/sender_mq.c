#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>



int main()
{
	
	mqd_t cdacmq;
	struct mq_attr cdacattr;
	cdacattr.mq_flags =  0; cdacattr.mq_msgsize = 14; cdacattr.mq_maxmsg = 3; cdacattr.mq_curmsgs = 0;

	cdacmq = mq_open("/cmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacattr);

	if(-1 == cdacmq)
	   perror("\nError opening mq\n");
	
	mq_send(cdacmq, "pello",sizeof("Hello"), 0);

	mq_close(cdacmq);

	return 0;
}

