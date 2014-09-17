#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int i, n;
	pid_t pid;
	for (i = 0; i < n; i++)
		if (pid = fork() == 0)
	break;
		printf("My process ID = %d\n and my parent's ID = %d\n", getpid(), getppid());
}
