#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <time.h>
#include<sys/ipc.h> // for shmget
#include<sys/shm.h> // for both

#define S_NAME "socket"


int main(int argc, char *argv[])
{
  
    char buffer[6];
    
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
	void *shared_memory;
	
	int shmid;
	shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
   shared_memory=shmat(shmid,NULL,0);
	int datasent=0;
    int times=0;
    while (times<10){
		int i=0;
        while (i<5){
            
           strcpy(shared_memory,arr[datasent]);
                printf("Data sent to P2 is ");
			for(int i=1;i<6;i++){
				printf("%c",arr[datasent][i]);
			}
			printf(" with ID: %d\n",arr[datasent][0]);
			i++;
			datasent++;
			sleep(1); 
        }
       
	
      
        printf("Data read from shared memory is : %s\n",(char*)shared_memory);
	//strcpy(buffer,(char*)shared_memory);
       //datasent=(int)(buffer[0]);
       times++;
		
    }

   
	return 0;
}
