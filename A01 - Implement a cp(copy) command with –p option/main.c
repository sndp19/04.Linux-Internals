//Question. Implement a cp(copy) command with –p option
/* ============================================================================================================================================
*Name		 :	Sandeep Varma Geddada
*Date		 :	18-09-2022
*Description	 :	Copy source file to destination file which passed through cmd-line arguments. After copying both files  must have equal size, 			      even it’s a zero sized file.  Eg:  ./my_copy source.txt dest.txt
 
==================================================================================================================================================*/

//START of Program

#include "my_copy.h"

int main(int argc, char **argv)
{
	//for storing File Descriptor
	int src_fd,dest_fd;
	//Buffer to store read value
	char choice;
	struct stat st;
	//Open file in read only mode
	
	if( argc > 3)
	{	
		//If -p argument is provided
		if(argv[1] == "-p")                 
		{	
			//Opening source file in file descriptor table
			if(src_fd = open(argv[2],O_RDONLY) ==-1)
			{
				perror("Error in opening Source file in File descriptor table\n");
				return 1;		

			}
			//Copying stat of source file to struct_stat members
			if(fstat(src_fd,&st) == -1)
			{
				perror("Failed to store stat of source file to respective stat values\n");
				return 2;
			}
			//opening destination File in file descriptor table
			if(dest_fd = open(argv[3],O_WRONLY)==-1)
			{
				printf("File %s  is already exists. Do you want to overwrite (Y/N)\n",argv[3]);
				scanf("%c",&choice);
				//Input of choice from user 
				if(choice == 'Y' || choice =='y')
				{	
					//Overwriting file over existing file
					if(dest_fd = open(argv[3],O_CREAT|O_WRONLY|O_TRUNC)==-1)
					{
						perror("Error \n");
						return 3;
					}
				}	 
				else if(choice =='N' || choice =='n')
				{
					return 0;
				}
		
			}
	
			//Changing destination file permision owner(rwx)group(rwx)others(rwx)
			if(fchmod(dest_fd,st.st_mode & 00777)==-1)
			{
				perror("Failed to change permissions of destination file\n");
				return 4;
			}
		}
	}
	else 
	{	
		//Opening Source file in file descriptor table
		if(src_fd = open(argv[1],O_RDONLY) == -1)
		{
			perror("Failed to open Source file\n");
			return 1;
		}	
		//Copying stat of source file to struct_stat members
		if(fstat(src_fd,&st) == -1)
		{
			perror("Failed to store stat of source file to respective stat values\n");
			return 2;
		}
		//opening destination File in file descriptor table
		if(dest_fd ==open(argv[2],O_WRONLY)==-1)
		{
			printf("File %s  is already exists. Do you want to overwrite (Y/N)\n",argv[2]);
			scanf("%c",&choice);
			//Input of choice from use
			if(choice == 'Y' || choice == 'y')
			{
				//Overwriting file over existing file
				if(dest_fd = open(argv[3],O_CREAT|O_WRONLY|O_TRUNC)==-1)
				{
					perror("Failed to Overwrite\n");
					return 3;
				}
			}
			else if(choice == 'N' || choice == 'n')
				return 0;

		}
		//Changing destination file permision owner(rwx)group(rwx)others(rwx)
		if(fchmod(dest_fd,st.st_mode &00777) == -1)
		{
			perror("Failed to change permissions of destination file\n");
			return 0;
		}
	}
	
	my_copy(src_fd,dest_fd);
	close(src_fd);
	close(dest_fd);

	return 0;
}


int my_copy(int source_fd, int dest_fd)
{
        int rd_ret,wr_ret;
        char buff[MAX];

        do{
                if(rd_ret = read(source_fd,buff,10) == -1)
                {
                        perror("Failed to read\n");
                        return 1;
                }
                if(wr_ret = write(dest_fd,buff,rd_ret) == -1)
                {
                        perror("Failed to write\n");
                        return 2;
                }
        }while(rd_ret != 0);

        return 0;

}
