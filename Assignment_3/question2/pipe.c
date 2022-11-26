/*
#include<unistd.h>
int pipe(int fd[2]);
create a unidirectional pipe
writing/sending end-fd[1]
reading/receiving end-fd[0]

*/
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h>
int main(){
	int fd[2],n;
	char buffer[100];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0){
		printf("passing value to child\n");
		write(fd[1],"hello\n",6);
	}
	else{
		printf("Child recived date\n");
		n=read(fd[0],buffer,100);
		write(1,buffer,n);	
	}
	return 0;
	
}
