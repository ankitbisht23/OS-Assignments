#include <errno.h>
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
    struct sockaddr_un addr;
    
    int connection;
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
    connection = socket(AF_UNIX, SOCK_SEQPACKET, 0);
 
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, S_NAME, sizeof(addr.sun_path) - 1);
    int c= connect(connection, (const struct sockaddr *)&addr, sizeof(addr));
   
	int datasent=0;
    int times=0;
    while (times<10){
		int i=0;
        while (i<5){
            int po = write(connection, arr[datasent], strlen(arr[datasent]));
           
                printf("Data sent to P2 is ");
			for(int i=1;i<6;i++){
				printf("%c",arr[datasent][i]);
			}
			printf(" with ID: %d\n",arr[datasent][0]);
			i++;
			datasent++;
			sleep(1); 
        }
       
	
        int r= read(connection, buffer, sizeof(buffer));
        

       datasent=(int)(buffer[0]);
       times++;
		
    }

    close(connection);
	return 0;
}
