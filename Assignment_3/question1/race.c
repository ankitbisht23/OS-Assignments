#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1;
int main(){
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
x=shared;
printf("val of x in fun1: %d\n",x);
x++;
sleep(1);
shared=x;
printf("val of shared in fun1: %d\n",shared);

}
void* fun2(){
int x;
x=shared;
printf("val of y in fun2: %d\n",x);
x--;
sleep(1);
shared=x;
printf("val of shared in fun2: %d\n",shared);

}
