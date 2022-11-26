#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid=shmget((key_t)1122,1024,0666|IPC_CREAT); // creates shared memory segment with key 2345, of size 1024 0666 is permission and last for create
	printf("Key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
	printf("Process attached at %p\n",shared_memory); //this prints the address where the segment is attached
	printf("Enter some data to write to shared memory\n");
	read(0,buff,100); // get some input from user
	strcpy(shared_memory,buff); // data writted to shared memory
	printf("You Wrote: %s\n",(char*)shared_memory);
	return 0;
}
