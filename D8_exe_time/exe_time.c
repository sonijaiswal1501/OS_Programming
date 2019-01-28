#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
	FILE *fp=NULL;
	unsigned char buff[100];
	double time_spent = 0.0;
	
	clock_t begin = clock();

	fp = fopen("sum.o","r");

	while( !feof(fp))
	fread(buff,sizeof(buff),1,fp);

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nTime elapsed is %f seconds\n", time_spent);

	return 0;
}

	
