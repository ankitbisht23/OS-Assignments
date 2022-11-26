// sem_t
// sem_init()
// sem_wait()
// sem_post()
// <semaphore.h>
// int sem_init(sem_t *sem,int pshared,unsigned int value)
// pshared= 0 for thread, non zero for process(3)
// value= initial value of sem variable(1=free,0=used)
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t s;
int main(){
sem_init(&s,0,1); 
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("final value of shared: %d\n",shared);
return 0;
}
void* fun1(){
int x;
sem_wait(&s); 
x=shared;
printf("val of x in fun1: %d\n",x);
x++;
sleep(1);
shared=x;
printf("val of shared in fun1: %d\n",shared);
sem_post(&s);

}
void* fun2(){
int x;
sem_wait(&s);
x=shared;
printf("val of y in fun2: %d\n",x);
x--;
sleep(1);
shared=x;
printf("val of shared in fun2: %d\n",shared);
sem_post(&s);
}
