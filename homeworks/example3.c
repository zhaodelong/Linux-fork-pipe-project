#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	pid_t pid;
	int status;
	pid =fork();
	switch (pid){
	case -1 : printf(" fork failed");
		exit(-1);
	case 0 : printf("I am the child, ID = %d\n", getpid());
		execlp("bash","bash","-c","ls",NULL);
		break;
	default : printf("I am the parent, ID = %d\n", getpid());
	}
	wait(NULL);
	
}
