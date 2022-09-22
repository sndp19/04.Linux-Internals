
Pre-requisites:

    Knowledge about system calls, How to read and understand ‘man pages’.
    Command line arguments, File operation system calls (open, read, write, close ..etc)
    Working of dup system calls.

Objective:
To understand and implement using basic system calls.

Requirements:

    Using dup or dup2 redirect printf out to a given file instead of printing to stdout.
    Pass the file name using command-line arguments.
    Try using both system calls (dup and dup2).

Sample Execution:
./dup_dup2 f1.txt
Print this message into STDOUT

Note : printf() should be diverted on file and one on STDOUT
