//Question. WAP to read the data from File and write to stdout
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Description	 :	To copy the data from File and write to stdout
 
==================================================================================================================================================*/

//START of Program

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 10

int main(int argc,char **argv)
{
	//For storing file descriptor
	int rd_ret,wr_ret,source_fd;
	//Buffer to store read value
	char buff[50];

	//Open file in read only mode
	source_fd = open("file.txt",O_RDONLY);
	
	//Check for error
	if(source_fd == -1)
	{
		perror("open");
		return(1);
	}
	do
	{
		// Reading MAX Bytes from file
		rd_ret = read(source_fd,buff,50);
		//Check for Errors
		if(rd_ret == -1)
		{
			perror("Read");
			return 2;
		}
		//Writing to stdout
		wr_ret = write(1,buff,rd_ret);
		//Checks for error
		if(wr_ret == -1)
		{
			perror("write");
			return 3;
		}
	       

	}while(rd_ret!=0);
	
	close(source_fd);
}
