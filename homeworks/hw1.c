/* CS3113 Homework 1 */
//	To practice in the use of UNIX functions fork() and pipe() and
//	to implement message communication between processes.
//  Name: Delong Zhao
//  09.17.2014

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#define bufsize 20
int fildes[2];
char buffer[bufsize]; //buffer used by pipe to passing information between parent and child process.
char command[bufsize]; //user input strings

void error(void)
{
	printf("unable to create a new process - job terminated \n");
		fflush(stdout);
} 

// child process to read command from pipe buffer and excecute it.
void child(void)
{
	int pm, i;
	close(fildes[1]);
	pm = read(fildes[0],&buffer,20); // get command string from pipe
	execlp("bash","bash","-c",buffer,NULL); // excecute command
	sleep(1);
	exit(0);
}

// parent process to write pipe buffer
void parent(void)
{
	int i, pm;				
	close(fildes[0]);
	pm = write(fildes[1], command, 20); // write pipe to passing command string
	wait(NULL);
}

int main(void)
{
	int pp, pid;
	
	printf("Enter command to perform task: \n");
        printf("ls: lists directory \n");
        printf("date: gives date and time of the day \n");
        printf("cal:  prints the calendar\n");
        printf("quit: quit program\n");
	// while loop to get user input
	while (strcmp(command,"quit") !=0) {
		printf("Enter command: ");
		scanf("%s", command); // ask user to input command
		if (strcmp(command,"quit") ==0){
			break; //quit if command is quit
		}	 
	
	pp = pipe (fildes); // pipe file buffer for information passing
	pid = fork(); //creat child process
	if (pid == 0)
		child();
	else if (pid == -1)
		error();
	else parent();
	}
	
}
