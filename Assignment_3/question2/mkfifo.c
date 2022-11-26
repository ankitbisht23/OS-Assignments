/*
both reader and writer process must be present-- called blocked mode - defauld mode
also has unblocked mode
#include<sys/types.h>
#include<sys/stat.h>
int mkfifo(const char *pathname,mode_t mode); 0 if success
pathname- name of pipe
mode- permission(rwx)

need 3 program p1-create a named pipe, p2-create a sender process, p3-create a receiver process

p1-
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int res=mkfifo("fifo1",0777);
	printf("named pipe created\n");
	return 0;
}

p2-
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int res,n;
	res=open("fifo1",O_WRONLY); // o_wronly- write only mode  
 	//res=open("fifo1",O_NONBLOCK,O_WRONLY); // for unblocked mode
	write(res,"Message",7);
	printf("Sender process PID %d sent the data\n",getpid());
	return 0;
}

p3-
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int res,n;
	char buffer[100];
	res=open("fifo1",O_RDONLY); // o_rdonly- read only mode
	//res=open("fifo1",O_NONBLOCK,O_RDONLY); // for unblocked mode
	n=read(res,buffer,100);
	printf("Reader process PID %d get the data\n",getpid());
	printf("Data received by  recevier is:  %s\n",buffer);
	return 0;
}

run both receiver and sender - ./sender & ./receiver

*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int res=mkfifo("fifo1",0777);
	printf("named pipe created\n");
	return 0;
}
