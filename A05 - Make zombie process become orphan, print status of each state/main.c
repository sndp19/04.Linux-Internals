//Question)A05 - WAP to make zombie process become orphan, print status of each state
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada

*Description     :	Create a scenario to make zombie process become orphan, print status of each state.

*Pre-requisites  : 	Knowledge about system calls, How to read and understand ‘man pages’.
    			Good knowledge about processes, zombie and orphan.
    			Working of fork system call.

*Objective	 :	To understand different states of a process.

*Requirements    :      1)Create a child process and print status that process is running
    			2)After some time print status that process is zombie state
    			3)After some time print zombie process cleared by init.
    			4)To print status use help of /proc//status file.
			5)For eg: if child pid is 1234, open file /proc/1234/status and print first 3 lines
     			 If that file is not available means that process is cleared.

*Sample execution:

			1. ./zomb_orph
			A child created with pid 1234
			Name:  ./zomb_orph
			State: S (sleeping)
			Name:  /zomb_orph   (After some time)
			State: Z (zombie)
			Process 1234 cleared by init  (After some time)
 
==================================================================================================================================================*/

//START of Program

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t pid,pid1;
	char buffer1[50],buffer2[50], buff[2];
	int fd1,fd2,gpid1,gpid2;
	int ret;	
	//create a child process using fork
	pid = fork();
	//pid of child1 stored in gpid variable
	gpid1 = getpid();
	if(pid == 0)
	{
		/* child process */		
		/* to print status */
		printf("A child created with pid %d\n",gpid1);
		//chmod("  /proc/%d/status ", mode_t mode
		sprintf(buffer1,"  /proc/%d/status | head -3",gpid1);
	
		fd1 = open(buffer1,O_RDONLY);
		do{
			ret = read(fd1,buff,1);
			write(1,buff,1);
		}while(ret !=0 );
		system(buffer1);
		sleep(2);
		//exit child process
		exit(1);

	}
	else if (pid > 0)
	{
		//Praent process
		sleep(5);

                //to print status
                sprintf(buffer2,"  /proc/%d/status | head -3",gpid1);
                fd2 =  open(buffer2,O_RDONLY);
                system(buffer2);

                //exit child process
                exit(1);

	}
	
	return 0;


}


