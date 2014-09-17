#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int pid;
	pid =fork();
	switch (pid){
	case -1 : printf(" fork failed");
		exit(-1);
	case 0 : printf("I am the child, ID = %d\n", getpid());
		exit(0);
	default : printf("I am the parent, ID = %d\n", getpid());
	}
}
