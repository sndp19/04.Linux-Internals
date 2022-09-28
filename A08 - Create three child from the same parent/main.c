//Question.A08 - WAP to create three child from the same parent
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Description	 :	To create three child from the same parent
Pre-requisites: 

    Knowledge about system calls, How to read and understand ‘man pages’. 
    Good knowledge about processes.
    Working of fork & wait system calls. 

Objective: 

• To understand how to use fork system calls.

 Requirements: 

    Create three child process from same parent. 
    Parent has to wait for all three child process.
    Print exit status of each child when they terminates.

Sample execution: 

./three_child 

Child 1 with pid 2020 created 
Child 2 with pid 2021 created
Child 3 with pid 2022 created 
Child 2020 is terminated with code 0 
Child 2021 is terminated with code 0 
Child 2022 is terminated with code 0
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
	pid_t pid1,pid2,pid3;
	int status,w_pid;
	
	//Creating a child process using fork()
	pid1 = fork();

	if(pid1 ==  -1 )
	{
		perror("Error: Fork() failed\n");
		exit(1);
	}
	else if(pid1 == 0)
	{
		// child1 created
		printf("child 1 with pid %d created \n",getpid());
		exit(0);
	}
	else
	{	
		//Parent process
		pid2 = fork();
		if(pid2 == -1)
		{
			perror("Error: Fork() failed \n");
			exit(1);
		}
		else if(pid2 == 0)
		{
			//child2 created
			printf("child 2 with pid %d created \n",getpid());
			exit(0);
		}	
		else
		{
			//Parent process
			pid3 = fork();
			if(pid3 == -1)
			{
				perror("Error: Fork() failed \n");
				exit(1);

			}
			else if(pid3 == 0 )
			{
				//child3 created
				printf("child 3 with pid %d created \n",getpid());
				exit(0);
			}
			else
			{
				//Parent process
				for(int i=0;i<3;i++)
				{
					//Parent waits while child is terminated and returns pid which is  stored in w_pid
					w_pid =wait(&status);
					//If child is terminated
					if(WIFEXITED(status))
					{

						printf("Child %d is terminated with Code %d\n",w_pid,WEXITSTATUS(status));
					}
				}			

			}
		}
	}
	return 0;
}



