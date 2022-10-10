//Question) A07 - WAP to create child process to execute command passed through command line
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Description	 :	
*Pre-requisites :      Knowledge about system calls, How to read and understand ‘man pages’.
    			Good knowledge about processes.
    			Working of fork, wait and exec system calls.
*Objective       :	To understand how to use exec system calls.
*Requirements	 :      Create child and execute a command passed from command-line arguments.  
    			If no arguments passed print a usage message.
    			In case any wrong command passed, print an error message.
    			After child terminates print the exit status of child process.

*Sample execution: -   1)No args passed (Print usage info)
			 ./exe_child Usage: ./exe_child args...
			2)Valid arg. passed
			 /exe_child date
			3)This is the CHILD process, with id 11612
			 Wed Apr  4 13:27:19 IST 2012
			 Child exited with status 0
 
==================================================================================================================================================*/

//START of Program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char *argv[])
{
	//Declare an array
	int i,ret,status;
	pid_t pid1,cpid;
	//Create a pipe
	
	
	if(argc == 1)
	{
		printf("%s:%s args...\n",argv[0],argv[0]);
		exit(1);
	}
	
	switch (pid1 = fork())
	{
		case -1:
			perror("error:fork()");
			exit(1);
		case 0:
		{
			/*              child1 process              */
			//Close the write end from child
			printf("This is the CHILD process, with id %d\n",getpid());		
			for(i=1;i< argc;i++)
			{
				ret = execlp(argv[i],argv[i],(char*)0);
				if(ret == -1)
				{
					printf("Invalid Argument passed\n");
					printf("%s:%s args...\n",argv[0],argv[0]);
					exit (1);
				}
				printf("\n");
			}
			
			
			break;
		}
		default:
		{
			/*     		Parent process		   */
			cpid = wait(&status);
			if(WIFEXITED(status))
			{
				printf("Child exited with status %d\n",WEXITSTATUS(status));
			}				
			else
				printf("Child terminated abnormally\n");
		}
	}
	
	return 0;
}
