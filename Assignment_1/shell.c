#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>


// ********************************** ECHO ************************************************************
void echo(char *args[], int l){
	//printf("%d\n",l);
	
	if(l==1) printf("\n");
	else if(!strcmp(args[1],"--help") && l==2) printf("--help\n");
	else if(!strcmp(args[1],"-n")){
		for(int i=2;i<l;i++){
			//printf("%s ",args[i]);
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
	}
	else if(!strcmp(args[1],"-E")){
		for(int i=2;i<l;i++){
			//printf("%s ",args[i]);
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
		printf("\n");
	
	}
	
	else{
		for(int i=1;i<l;i++){
			//printf("%s ",args[i]);
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
		printf("\n");
		
	}
	
	
}

// *************************************** PWD **********************************************************
void pwd(char *args[],int l){
	if(l>2) printf("pwd: too many arguments\n");
	else if(l==1){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	}
	else if(!strcmp(args[1],"-P")){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	
	}
	else if(!strcmp(args[1],"-L")){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	}
	else if(args[1][0]=='-') printf("%s: Invalid Option\n",args[1]);
	else printf("%s: Invalid Option\n",args[1]);
}

// ************************************** CD ***************************************************************
void cd(char *args[],int l){
	if(l==1){
		chdir("/home/ankit");
	}
	else if(l>3) printf("cd: too many arguments\n");
	else if(!strcmp(args[1],"-P")){
		int t;
		if(l==2) t=chdir("/home/ankit");
		else t=chdir(args[2]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
	
	}
	else if(!strcmp(args[1],"-L")){
		int t;
		if(l==2) t=chdir("/home/ankit");
		else t=chdir(args[2]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
	}
	else if(args[1][0]=='-') printf("%s: Invalid Option\n",args[1]);
	
	else{
	
		int t=chdir(args[1]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
		
	}
	char *temp[2]={"pwd","-L"};
	pwd(temp,1);
	
}
// ********************************** MAIN ***********************************************************
int main(){
	
	while(1){
		printf("ankit21014>> ");
		char cmd[200];
   		fgets(cmd, 200, stdin);
   
		if(strlen(cmd)==1)
			continue;
		//	printf("%s\n","enter something");
		//	printf("%ld\n",strlen(cmd));
		//	printf("%c",cmd[0]);	
		
		
			//printf("%s",cmd);
			//printf("%ld\n",strlen(cmd));
		cmd[strlen(cmd)-1]='\0';
		if(!strcmp("exit",cmd))
			break;
		int total_len=0;
		char *args[20];
		char *p=strtok(cmd," ");
		while(p!=NULL){
			args[total_len]=p;
			total_len++;
			p=strtok(NULL," ");
		}
			//printf("%s\n",p);
			//for(int i=0;i<total_len;i++){
			//	printf("%s\n",args[i]);
			//}
		if(!strcmp(args[0],"cd")){
			//printf("cd com\n");
			cd(args,total_len);
			
		}
		else if(!strcmp(args[0],"pwd")){
			//printf("pwd com\n");
			pwd(args,total_len);
		}
		else if(!strcmp(args[0],"echo")){
			//printf("echo com\n");
			echo(args,total_len);
			
		}
		else if(!strcmp(args[0],"ls")){
		
			
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				execvp("./ls",args);
			}
			else{
				pid_t w=wait(NULL);
				continue;
			}
			
		}
		else if(!strcmp(args[0],"date")){
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				execvp("./date",args);				
			}
			else{
				pid_t w=wait(NULL);
				
				continue;
				
			}
		}
		else if(!strcmp(args[0],"rm")){
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				execvp("./rm",args);
				
			}
			else{
				pid_t w=wait(NULL);
				continue;
			}
			
			//printf("rm com\n");
		}
		else if(!strcmp(args[0],"cat")){
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				execvp("./cat",args);
				
			}
			else{
				pid_t w=wait(NULL);
				continue;
			}
		}
		else if(!strcmp(args[0],"mkdir")){
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				execvp("./mkdir",args);
				
			}
			else{
				pid_t w=wait(NULL);
				continue;
			}
		}
		else printf("Command '%s' not found\n",args[0]);
		
	}
	return 0;
}
