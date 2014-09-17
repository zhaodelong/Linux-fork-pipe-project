#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#define bufsize 20
int fildes[2];
char buffer[bufsize];
void error(void)
{
	printf("unable to create a new process - job terminated \n");
		fflush(stdout);
} 

void child(void)
{
	int pm, i;
	printf("child starts working.\n");
	close(fildes[1]);
	for (i = 0; i<5; i++)
	{
		printf("in child i = %d \n", i);
		pm = read(fildes[0],&buffer,20);
		printf ("child received %d chars from parent\n",pm);
		printf ("message received is: %s ",buffer);
		fflush(stdout);
		sleep(1);
	}
	exit(0);
}

void parent(void)
{
	int i, pm;
	printf("parent starts working.\n");
	close(fildes[0]);
	for (i = 0; i < 5 ; i++)
	{
		switch(i){
		case 0:
		pm = write(fildes[1], "first message \n", 20);
		printf("characters written by parent = %d \n", pm);
		fflush(stdout);
		break;
		case 1:
		pm = write(fildes[1], "second message \n", 20);
		printf("characters written by parent = %d \n", pm);
		fflush(stdout);
		break;
		case 2:
		pm = write(fildes[1], "third message \n", 20);
		printf("characters written by parent = %d \n", pm);
		fflush(stdout);
		break;
		case 3:
		pm = write(fildes[1], "fourth message \n", 20);
		printf("characters written by parent = %d \n", pm);
		fflush(stdout);
		break;
		case 4:
		pm = write(fildes[1], "fifth message \n", 20);
		printf("characters written by parent = %d \n", pm);
		fflush(stdout);
		}
	}
	wait(NULL);
	printf("parent terminating\n");
	exit(0);
}

int main(void)
{
	int pp, pid;
 
	pp = pipe (fildes);
	printf("pipe opened with pp = %d \n", pp);
	fflush(stdout);
	pid = fork();
	if (pid == 0)
		child();
	else if (pid == -1)
		error();
	else parent();
}
