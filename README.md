CS3113			 Homework No. 1			    September 8, 2014
				Due: September 18, 2014
				(50 points)


This program is to give you practice in the use of UNIX functions fork() and pipe() and to implement message communication between processes.   

Write a program with two processes – one of them acts as a client and the other as a server.  On receipt of an appropriate request from the client, the server can perform the following services:
(a) print time and date, local or universal,
(b) print calendar for the any month, with Sunday or Monday as the first day of the week
(c) list the contents of the working or any other directory, 
(d) quit -- when the client makes request to quit, the server terminates.

In this program you will use the UNIX fork() function to create a child process.  The child process will act as a server and the parent process will act as a client.  The communication between the two will be through the use of the pipe() function.  You can choose your “tokens” to identify the type of request.  Upon receiving a request from the client, the server will use fork() to create a child that will perform the desired task and then quit.  The server tasks can be performed by loading the appropriate UNIX function using the execlp() or execvp() function calls to replace the child process created by the server.  You may use the man command on your terminal to get more information on the needed commands to perform the desired tasks.

The following UNIX commands perform the required tasks:

	ls 	lists directory
	date 	gives date and time of the day
	cal     prints the calendar

Look up the various options in the UNIX online manual using the man command


1. Your program should be well-documented for full credit. 
2. Partial credit can only be given for programs that compile and run but do not perform the entire task stipulated in the assignment.


