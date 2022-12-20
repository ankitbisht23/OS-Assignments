#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


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
	
	for(i=0;i<5;i++){
		n[i]=i+1;
		pthread_create(&T[i],NULL,Philosopher,(void*)&n[i]);
		pthread_join(T[i],NULL);

	}
	for(i=0;i<5;i++){
		
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
	picksauce(num);
	eat(num);
	releaseright(num);
	releaseleft(num);
	releasesauce(num);
	
}
void eat(int num){
	
	printf("Philosopher %d is eating\n",num);
	sleep(2);
	printf("Philosopher %d is done\n",num);
}
void pickleft(int num){
	printf("Philosopher %d tries to pick left chopstick\n",num);
	
	
	printf("Philosopher %d  picks the left chopstick\n",num);
	sleep(1);
}
void pickright(int num){
	printf("Philosopher %d tries to pick right chopstick\n",num);
	
	
	printf("Philosopher %d  picks the right chopstick\n",num);
	sleep(1);
}
void releaseleft(int num){
	
	printf("Philosopher %d leaves the left chopstick\n",num);
}
void releaseright(int num){
	
	printf("Philosopher %d leaves the right chopstick\n",num);
	
}
void picksauce(int num){
	
	printf("Philosopher %d pick sauce\n",num);
}
void releasesauce(int num){

	
	printf("Philosopher %d leaves the sauce\n",num);
}
