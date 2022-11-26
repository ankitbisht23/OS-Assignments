
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int res,n;
	res=open("fifo1",O_WRONLY); // o_wronly- read only mode
	write(res,"Message",7);
	printf("Sender process PID %d sent the data\n",getpid());
	return 0;
}

