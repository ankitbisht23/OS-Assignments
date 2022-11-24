#include<stdio.h>
#include<sys/syscall.h>
#include<linux/kernel.h>
#include<unistd.h>
#include<errno.h>
int main(){
	int n=2,m=3;
	float arr[2][3]={{5,2,3},{3,4,4}};
	float arr_cpy[2][3];
	int st=syscall(451,arr_cpy,arr,2,3);
	if(!st){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%f ",arr_cpy[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
	
}

