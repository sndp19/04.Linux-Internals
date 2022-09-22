//Question.WAP to understand usage of dup and dup2 system calls
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Description	 :	printf() should be diverted on file and one on STDOUT
*Sample Input	 :	2
*Sample output	 :	Enter the Choice
			 1) dup 
 			 2) dup2
			 =>2
			Print this message into STDOUT
 
==================================================================================================================================================*/

//START of Program


#include "dup_and_dup2.h"

int main(int argc,char *argv[])
{
	int choice,fd1,fd2,copy_fd;

	if(argc ==2)
	{
		printf("Enter the Choice\n 1) dup \n 2) dup2\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				fd1 = open(argv[1],O_WRONLY);
				//Copying stdout to other File descriptor
				copy_fd = dup(1);
				close(1);
				fd2 = dup(fd1);
				//Printing message to the input file instead of stdout
				printf("Print this message into the file1\n");
				//removind file from 1 of File descriptor
				close(1);
				dup(copy_fd);
				//Printing message to STDOUT
				printf("Print this message into STDOUT\n");
				return 0;
			}
			case 2:
			{
				fd1 = open(argv[1],O_WRONLY);
                                //Copying stdout to other File descriptor
				dup2(1,4);
                               	dup2(fd1,1);
				//Printing message to the input file instead of stdout
                                printf("Print this message into the file2\n");
				dup2(4,1);
				//Printing message to STDOUT
                                printf("Print this message into STDOUT\n");
	
                                break;
			}
			default:
				printf("Invalide choice\n");
				break;
		}
	}
	else
	{	//If  no file or more than one file was provided, 
		perror("Invalid Input\n Please Pass a file name\n");
		return 1;
	}

	return 0;
}
