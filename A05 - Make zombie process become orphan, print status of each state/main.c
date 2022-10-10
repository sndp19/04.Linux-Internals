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
	int pid,pid1;
	char buffer1[30],buffer2[30], buff[1];
	int fd1,fd2,gpid1,gpid2;
	int ret1,ret2,n=0;	
	//create a child process using fork
	pid = fork();
	//pid of child1 stored in gpid variable

	if(pid == 0)
	{
		sleep(2);
		/*            /child process/                 */		
		/* to print status */
		gpid1 = getpid();
		printf("A child created with pid %d\n",gpid1);
		
		/* storing path into buffer */		
		sprintf(buffer1," /proc/%d/status ",gpid1);
		fd1 = open(buffer1,O_RDONLY);
/*
		do{
			ret1 = read(fd1,buff,1);
			write(1,buff,ret1);
			if(buff[0] == '\n')
				n++;
		  }while(ret1 !=0 && n <3 );

*/		
		//exit child process
		exit(1);
 
	}
	else if (pid > 0)
	{
		sleep(7);
	
		/* storing path into buffer */		
		sprintf(buffer1," /proc/%d/status ",pid);
		fd1 = open(buffer1,O_RDONLY);

		do{
			ret1 = read(fd1,buff,1);
			write(1,buff,ret1);
			if(buff[0] == '\n')
				n++;
		  }while(ret1 !=0 && n <3 );

	
		//Praent process
		pid1 = fork();
		if(pid1 == 0)
		{
			sleep(5);
			//to print status
			gpid2 = getpid();
        		sprintf(buffer2,"  /proc/%d/status",gpid2);
                	fd2 = open(buffer1,O_RDWR);
  			if(fd2 == -1)
			{
				printf("Process %d cleared by init\n",gpid2);
	
			}       
			do{
                        	ret1 = read(fd1,buff,1);
                        	write(1,buff,1);
                        	if(buff[0] == '\n')
                                n++;
                  	}while(ret1 !=0 && n <3 );
 
                 	//exit child process
                	exit(1);

		}	
		else
			exit(0);

	}	
	return 0;


}


