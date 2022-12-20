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

  
	int rec=0;
  
      void *shared_memory;
	
	int shmid;
	shmid=shmget((key_t)1122,1024,0666);
    
		while(rec<10){
			int highest=-1;
		char temp[6];
		     
		for(int dd=0;dd < 5;dd++){
			sleep(1);
		strcpy(buffer,(char*)shared_memory);
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
            	
        		
		strcpy(shared_memory,temp); 
			
			  rec++;
			
		}
            
      
	return 0;
}
