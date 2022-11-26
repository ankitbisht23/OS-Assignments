/* stdio.h
FILE *popen(const char *command,const char *type)
command- the process with which you want to communicate
type- w(for writing/send) or r(for reading/recive) 
example- 

write into a pipe

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h>
int main(){
FILE *rd;
char buffer[50];
sprintf(buffer,"name first");
rd=popen("wc -c","w");
fwrite(buffer,sizeof(char),strlen(buffer),rd);
pclose(rd);
} 
*/

// read/recive
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h>
int main(){
FILE *rd;
char buffer[50];
sprintf(buffer,"name first");
rd=popen("ls","r");
fread(buffer,sizeof(char),20,rd);
write(1,buffer,20);
printf("\n");
pclose(rd);
return 0;
} 
