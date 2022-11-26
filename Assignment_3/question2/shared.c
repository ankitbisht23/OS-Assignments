/*
shmget() - used to create the shared memory segment
shmat() - used to attach the shared segment with the address space of the process
#include<sys/ipc.h> // for shmget
#include<sys/shm.h> // for both
#include<sys.types.h> // for shmat
int shmget(key_t key,size_t size, int shmflg);
the int return by shmget is used in shmat
void *shmat(int shmid,const void *shmaddr, int shmflg);
2 programs-
p1- the sender
p2- the receiver

p1-
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

p2-
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid=shmget((key_t)1122,1024,0666);
	printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0); // process attached to shared memory segment
	printf("Process attached at %p\n",shared_memory);
	printf("Data read from shared memory is : %s\n",(char*)shared_memory);
	return 0;
}
*/
