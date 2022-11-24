#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>

int main(){
int pidA,pidB,pidC;
struct timespec stA,stB,stC,spA,spB,spC;
pidA=fork();
clock_gettime(CLOCK_REALTIME,&stA);
if(!pidA){
	execl("/bin/sh","sh","shellA.sh",NULL);
	
}
else{

	pidB=fork();
	clock_gettime(CLOCK_REALTIME,&stB);
	if(!pidB){
		
		execl("/bin/sh","sh","shellB.sh",NULL);
		}
	else{
		pidC=fork();
		clock_gettime(CLOCK_REALTIME,&stC);
		if(!pidC){
	
		execl("/bin/sh","sh","shellC.sh",NULL);
		}
		else{
		int i=0;
		while(i<3){
		int p=waitpid(-1,NULL,WNOHANG);
		if(p==pidA){
			clock_gettime(CLOCK_REALTIME,&spA);
			double t=spA.tv_sec-stA.tv_sec;
			printf("Process A time: %f\n",t);
			i++;
		}
		if(p==pidB){
			clock_gettime(CLOCK_REALTIME,&spB);
			double t=spB.tv_sec-stB.tv_sec;
			printf("Process B time: %f\n",t);
			i++;
		}
		if(p==pidC){
			clock_gettime(CLOCK_REALTIME,&spC);
			double t=spC.tv_sec-stC.tv_sec;
			printf("Process C time: %f\n",t);
			i++;
		}
		
		
		
		}
		
		
		}
		
		
	}
}

}
