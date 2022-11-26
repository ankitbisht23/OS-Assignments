
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int res,n;
	char buffer[100];
	res=open("fifo1",O_RDONLY); // o_wronly- read only mode
	n=read(res,buffer,100);
	printf("Reader process PID %d get the data\n",getpid());
	printf("Data received by PID- %d recevier is:  %s\n",getpid(),buffer);
	return 0;
}

