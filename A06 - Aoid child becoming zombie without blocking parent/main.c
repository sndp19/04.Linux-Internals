//Question) A06 - WAP to avoid child becoming zombie without blocking parent 
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Description	 :	To avoid child becoming zombie without blocking parent 

 Pre-requisites:

    Knowledge about system calls, How to read and understand ‘man pages’.
    Good knowledge about processes & zombie process.
    Working of fork & wait system call.

Objective:

To understand different states of a process.

Requirements: 

    Create a child process avoid it become a zombie.
    To avoid zombie we need to call wait(), but this block parent until child terminates.
    So we need to use waitpid() with proper arguments (Read man page). 
    When child is working parent has to continuously print some message.
    When ever child terminates parent has to print child terminated and print exit status of child process

Sample execution:
./nonblock_wait
A child created with pid 1234
parent is running
parent is running
parent is running . .
............................
Child 1234 terminated normally with exit status 0 parent terminating 
==================================================================================================================================================*/

//START of Program

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int ch_pid, status;

	//Creation of child process
	ch_pid = fork();
	if(ch_pid == -1)
	{
		printf("Error:Child creation with fork() failed\n");
		exit(1);
	}
	else if(ch_pid == 0)
	{
		//child process
		sleep(5);
		exit(1);
	}
	else if(ch_pid > 0)
	{
		//Parent process
		int w_pid;
		
		do
		{
			//check if child terminated
			w_pid = waitpid(ch_pid, &status,WNOHANG);
			
			if(w_pid == 0)
				printf("parent is running \n");

		}while( w_pid == 0 );
		//checking child exit status
		if(WIFEXITED(status))
			printf("Child %d terminated normally with exit status %d\n", ch_pid,WEXITSTATUS(status));
	}

	return 0;
}
