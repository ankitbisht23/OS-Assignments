#include<stdio.h>
#include<math.h>
#include<time.h>
#include<pthread.h>
#define BILLION 1000000000L;

void* countA(){
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
	long long int a;
	long long int b=pow(2,32);
	
		
	for(a=0;a<b;a++){
	
	}
	
	clock_gettime(CLOCK_REALTIME,&stop);
	double t=(stop.tv_sec-start.tv_sec)+( stop.tv_nsec - start.tv_nsec )/ BILLION;
	printf("%lf\n",t);
	
}
void* countB(){
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
	long long int a;
	long long int b=pow(2,32);
	
		
	for(a=0;a<b;a++){
	
	}
	
	clock_gettime(CLOCK_REALTIME,&stop);
	double t=(stop.tv_sec-start.tv_sec)+( stop.tv_nsec - start.tv_nsec )/ BILLION;
	printf("%lf\n",t);
	
}
void* countC(){
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
	long long int a;
	long long int b=pow(2,32);
	
		
	for(a=0;a<b;a++){
	
	}
	
	clock_gettime(CLOCK_REALTIME,&stop);
	double t=(stop.tv_sec-start.tv_sec)+( stop.tv_nsec - start.tv_nsec )/ BILLION;
	printf("%lf\n",t);
	
}
int main(){
	
	pthread_t threadA,threadB,threadC;
	int rc;
	struct sched_param param;
	int policyA=SCHED_OTHER,policyB=SCHED_RR,policyC=SCHED_FIFO;
	
	param.sched_priority=-5;
	rc=pthread_create(&threadA,NULL,countA,NULL);
	rc=pthread_create(&threadB,NULL,countB,NULL);
	rc=pthread_create(&threadC,NULL,countC,NULL);
	rc=pthread_setschedparam(threadA,policyA,&param);
	rc=pthread_setschedparam(threadB,policyB,&param);
	rc=pthread_setschedparam(threadC,policyC,&param);
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);
	
	param.sched_priority=10;
	rc=pthread_create(&threadA,NULL,countA,NULL);
	rc=pthread_create(&threadB,NULL,countB,NULL);
	rc=pthread_create(&threadC,NULL,countC,NULL);
	rc=pthread_setschedparam(threadA,policyA,&param);
	rc=pthread_setschedparam(threadB,policyB,&param);
	rc=pthread_setschedparam(threadC,policyC,&param);
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);
	
	param.sched_priority=15;
	rc=pthread_create(&threadA,NULL,countA,NULL);
	rc=pthread_create(&threadB,NULL,countB,NULL);
	rc=pthread_create(&threadC,NULL,countC,NULL);
	rc=pthread_setschedparam(threadA,policyA,&param);
	rc=pthread_setschedparam(threadB,policyB,&param);
	rc=pthread_setschedparam(threadC,policyC,&param);
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);
	
	param.sched_priority=20;
	rc=pthread_create(&threadA,NULL,countA,NULL);
	rc=pthread_create(&threadB,NULL,countB,NULL);
	rc=pthread_create(&threadC,NULL,countC,NULL);
	rc=pthread_setschedparam(threadA,policyA,&param);
	rc=pthread_setschedparam(threadB,policyB,&param);
	rc=pthread_setschedparam(threadC,policyC,&param);
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);
	
	
	param.sched_priority=25;
	rc=pthread_create(&threadA,NULL,countA,NULL);
	rc=pthread_create(&threadB,NULL,countB,NULL);
	rc=pthread_create(&threadC,NULL,countC,NULL);
	rc=pthread_setschedparam(threadA,policyA,&param);
	rc=pthread_setschedparam(threadB,policyB,&param);
	rc=pthread_setschedparam(threadC,policyC,&param);
	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);
	pthread_join(threadC,NULL);
	
	
	
	return 0;
}

