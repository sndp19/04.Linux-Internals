
Pre-requisites:

    Knowledge about system calls, How to read and understand ‘man pages’.
    Command line arguments, File operation system calls (open, read, write, close, fstat ..etc


Objective:

       To understand and implement using basic system calls


Requirements:

    Copy source file to destination file which passed through cmd-line arguments. After copying both files  must have equal size, even it’s a zero sized file.  Eg:  ./my_copy source.txt dest.txt
    If arguments are missing show the usage (help) info to use
    Implement a my_copy() function where you have to pass two file descriptors. Int my_copy(int source_fd, int dest_fd);
     If –p option passed copy permissions as well to destination (refer ‘fstat’ man page).  Eg: - ./my_copy –p source.txt dest.txt.
    If the destination file is not present then create a new one with given name. In case if it is present show a confirmation from user to overwrite. Eg: - ./my_copy source.txt destination.txt .File  “destination.txt” is already exists. Do you want to overwrite (Y/n)
    If user type ‘Y/n’ or enter key overwrite the destination with new file. In n/N don’t overwrite and exit from program.
    Program should able handle all possible error conditions.


Sample execution:

    When no arguments are passed ./my_copy Insufficient arguments
    Usage:- ./my_copy [option]  
    When destination file is not exists ./my_copy source.txt dest.txt . New dest.txt file is created and source.txt file will be copied to dest.txt file
     When destination file exists ./my_copy source.txt dest.txt File “dest.txt” is already exists. Do you want to overwrite (Y/n)
    When –p option passed ./my_copy –p source.txt dest.txt Permissions also copied from source file to destination file
