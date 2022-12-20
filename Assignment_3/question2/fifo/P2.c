#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/un.h>


int main(){
	char buffer[6];
	int fd,f;

	mkfifo("pipe1",0777);
	
	mkfifo("pipe2",0777);
	
	int rec=0;
	while(rec<10){ 
		int highest=-1;
		char temp[6];
		     
		for(int dd=0;dd < 5;dd++){
			sleep(1);
		
			
			fd=open("pipe1",O_RDONLY);
			
			f=read(fd, buffer, sizeof(buffer));
			
			close(fd);
			int t=(int)(buffer[0]);
			if(t>highest){
				highest=t;
				for(int i=0;i<6;i++)
				temp[i]=buffer[i];	
			}
			
		}
		 printf("Data received with highest ID is ");
			for(int i=1;i<6;i++){
				printf("%c",temp[i]);
			}
			printf(" with ID: %d\n",highest);
		rec++;
		
		fd=open("pipe2",O_WRONLY);
		
        	int r=write(fd, temp, sizeof(temp));
        	
		close(fd);
	}
	return 0;
        
}

