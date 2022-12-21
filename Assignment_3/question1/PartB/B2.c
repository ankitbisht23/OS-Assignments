#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t forks[5],sauce;
void *Philosopher(void *);
void eat(int);
void pickleft(int);
void pickright(int);
void releaseleft(int);
void releaseright(int);
void picksauce(int);
void releasesauce(int);
int main(){
	int i,n[5];
	pthread_t T[5];
	for(i=0;i<5;i++)
	sem_init(&forks[i],0,1);
	sem_init(&sauce,0,2);
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
	printf("Philosopher %d is thinking\n",num);
	sleep(1);
	printf("Philosopher %d wants to eat\n",num);
	if(num%2==0){
		pickleft(num);
		pickright(num);
	}
	else{
		pickright(num);
		pickleft(num);
	}
	picksauce(num);
	eat(num);
	releaseright(num);
	releaseleft(num);
	releasesauce(num);
	printf("Philosopher %d is thinking\n",num);
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
void picksauce(int num){
	sem_wait(&sauce);
	printf("Philosopher %d pick sauce\n",num);
}
void releasesauce(int num){

	sem_post(&sauce);
	printf("Philosopher %d leaves the sauce\n",num);
}
