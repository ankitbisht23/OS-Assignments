#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t chopstick[5];
void *philos(void *);
void eat(int);
void pickleft(int);
void pickright(int);
void releaseleft(int);
void releaseright(int);
int main(){
	int i,n[5];
	pthread_t T[5];
	for(i=0;i<5;i++)
	sem_init(&chopstick[i],0,1);
	for(i=0;i<5;i++){
		n[i]=i;
		pthread_create(&T[i],NULL,philos,(void*)&n[i]);

	}
	for(i=0;i<5;i++){
		pthread_join(T[i],NULL);
	}
	return 0;
}

void* philos(void* n){
	int ph=*(int*)n;
	printf("Philosopher %d wants to eat\n",ph);
	if(ph%2==0){
		pickleft(ph);
		pickright(ph);
	}
	else{
		pickright(ph);
		pickleft(ph);
	}
	
	eat(ph);
	releaseright(ph);
	releaseleft(ph);
	
}
void eat(int ph){
	
	printf("Philosopher %d is eating\n",ph);
	sleep(2);
	printf("Philosopher %d finished eating\n",ph);
}
void pickleft(int ph){
	printf("Philosopher %d tries to pick left chopstick\n",ph);
	sem_wait(&chopstick[ph]);
	
	printf("Philosopher %d  picks the left chopstick\n",ph);
	sleep(1);
}
void pickright(int ph){
	printf("Philosopher %d tries to pick right chopstick\n",ph);
	sem_wait(&chopstick[(ph+1)%5]);
	
	printf("Philosopher %d  picks the right chopstick\n",ph);
	sleep(1);
}
void releaseleft(int ph){
	sem_post(&chopstick[ph]);
	printf("Philosopher %d leaves the left chopstick\n",ph);
}
void releaseright(int ph){
	sem_post(&chopstick[(ph+1)%5]);
	printf("Philosopher %d leaves the right chopstick\n",ph);
	
}
