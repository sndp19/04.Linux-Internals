//Question)A10 - Implement communication between three related processes using two pipe
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
Pre-requisites   : 	Knowledge about system calls, How to read and understand ‘man pages’.
    			Good knowledge about processes and IPC. 
    			Working of pipe & dup system calls.

Objective   	 : 	To understand working of pipe between two process. 

Requirement	 :	Create three child process and execute commands passed from command-line arguments 
    			Each command is separated by a '|' (pipe) character. 
    			First child execute first command (with or without options) and pass o/p to next. 
    			Second child executes second command (after '|') will reads I/p from first pipe. 
    			Third Child execute third command (after 2nd pipe '|') will read i/p from second pipe.
    			Parent will wait for  child process to finish .

Sample execution:

    			1)./three_pipes (No arguments)

 			Error: No arguments passed Usage: ./three_pipes  <command1 > '|'   <command2> '|'  <command3 >       

			2) ./pipe ls ­l '|' grep 

 			Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2> '|'  <command3 >

			3) ./pipe ls -­l '|' grep “pattern” '|' wc -­l 

			5 5 25



 
==================================================================================================================================================*/

//START of Program



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//Declare an array
	int pipe_fd[2],pipe_fd2[2],i,j;
	pid_t pid1,pid2;
	//Create a pipe
	pipe(pipe_fd);
	
	for(i=2;i < argc; i++)
	{
		if(strcmp(argv[i],"|") ==0)
			j = i;
	}
	switch (pid1 = fork())
	{
		case -1:
			perror("error:fork()");
			exit(1);
		case 0:
		{
			//child1 process
			//Close the write end from child
			close(pipe_fd[1]);
			//Duplicating to stdout
			dup2(pipe_fd[0],0);
			execvp(argv[j+1],(argv+j+1));
			break;
		}
		default:

		{
			pid2 = fork();
		        
			if(pid2 == 0)
			{
				//child2 process
				//Closing the read end for child 2
				close(pipe_fd[0]);
				//duplicating to stdin
				dup2(pipe_fd[1],1);
				execvp(argv[0],argv);
				break;
			}       
			else if(pid2 >0)
			{
				pid3 = fork();
		        
			if(pid3 == 0)
			{
				//child2 process
				//Closing the read end for child 2
				close(pipe_fd[0]);
				//duplicating to stdin
				dup2(pipe_fd[1],1);
				execvp(argv[0],argv);
				break;
			}       
			else if(pid2 >0)
			{
				exit(0);
			}         
			else if(pid2 == -1)
			{
				perror("Error: fork()");
				exit(2);
			}		
		
			break;}
			

			}         
			else if(pid2 == -1)
			{
				perror("Error: fork()");
				exit(2);
			}		
		
			break;}
			

	}										


	return 0;
}



