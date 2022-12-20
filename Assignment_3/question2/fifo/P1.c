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

   	int i,j,len=6;
	time_t t;
	char arr[50][6];
	srand((unsigned)time(&t));
	for(i=0;i<50;i++){
		arr[i][0]=i+1;
		for(j=1;j<len;j++){
			int n=rand()%26;
			arr[i][j]=(char)(n+97);
		}
	}
	
	mkfifo("pipe1",0777);
	mkfifo("pipe2",0777);
	
	int datasent= 0;
   
    	int times=0;
    	while (times<10){
		int i=0;		
         	while(i<5){
			fd = open("pipe1",O_WRONLY);
           		f = write(fd, arr[datasent], strlen(arr[datasent]));
			close(fd);
			printf("Data sent to P2 is ");
			for(int i=1;i<6;i++){
				printf("%c",arr[datasent][i]);
			}
			printf(" with ID: %d\n",arr[datasent][0]);
			i++;
			datasent++;
			sleep(1); 
		}
       		times++;
		fd = open("pipe2",O_RDONLY);
		int r= read(fd, buffer, sizeof(buffer));
		close(fd);
		datasent=(int)(buffer[0]);	
		}
	return 0;
}
