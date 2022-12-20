#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t forks[5];
void *Philosopher(void *);
void eat(int);
void pickleft(int);
void pickright(int);
void releaseleft(int);
void releaseright(int);
int main(){
	int i,n[5];
	pthread_t T[5];
	for(i=0;i<5;i++)
	sem_init(&forks[i],0,1);
	for(i=0;i<5;i++){
		n[i]=i+1;
		pthread_create(&T[i],NULL,Philosopher,(void*)&n[i]);

	}
	for(i=0;i<5;i++){
		pthread_join(T[i],NULL);
	}
	return 0;
}

void* Philosopher(void* n){
	int num=*(int*)n;
	printf("Philosopher %d wants to eat\n",num);
	if(num%2==0){
		pickleft(num);
		pickright(num);
	}
	else{
		pickright(num);
		pickleft(num);
	}
	
	eat(num);
	releaseright(num);
	releaseleft(num);
	
}
void eat(int num){
	
	printf("Philosopher %d is eating\n",num);
	sleep(2);
	printf("Philosopher %d is done\n",num);
}
void pickleft(int num){
	printf("Philosopher %d tries to pick left fork\n",num);
	sem_wait(&forks[num-1]);
	
	printf("Philosopher %d  picks the left fork\n",num);
	sleep(1);
}
void pickright(int num){
	printf("Philosopher %d tries to pick right fork\n",num);
	sem_wait(&forks[(num)%5]);
	
	printf("Philosopher %d  picks the right fork\n",num);
	sleep(1);
}
void releaseleft(int num){
	sem_post(&forks[num-1]);
	printf("Philosopher %d leaves the left fork\n",num);
}
void releaseright(int num){
	sem_post(&forks[(num)%5]);
	printf("Philosopher %d leaves the right fork\n",num);
	
}
