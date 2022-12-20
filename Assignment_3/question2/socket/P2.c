#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <time.h>
#define S_NAME "socket"

int main(int argc, char *argv[])
{
    struct sockaddr_un name;
   
     unlink(S_NAME);
    int socket1;
    int connection;
   
    char buffer[6];

    socket1 = socket(AF_UNIX, SOCK_SEQPACKET, 0);
    memset(&name, 0, sizeof(name));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, S_NAME, sizeof(name.sun_path) - 1);
    int p = bind(socket1, (const struct sockaddr *)&name, sizeof(name));
    
    int c= listen(socket1, 20);
    
	int rec=0;
  
        connection = accept(socket1, NULL, NULL);
    
		while(rec<10){
			int highest=-1;
		char temp[6];
		     
		for(int dd=0;dd < 5;dd++){
			sleep(1);
		int po = read(connection, buffer, sizeof(buffer));
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
            	
        		int co= write(connection, temp, sizeof(temp));
		
			
			  rec++;
			
		}
            
        close(connection);
      
        
    
    close(socket1);
  
	return 0;
}
