
* create child process to execute command passed through command line *

Pre-requisites:-

    Knowledge about system calls, How to read and understand ‘man pages’.
    Good knowledge about processes.
    Working of fork, wait and exec system calls.

Objective:

• To understand how to use exec system calls.

Requirements:

    Create child and execute a command passed from command-line arguments.  
    If no arguments passed print a usage message.
    In case any wrong command passed, print an error message.
    After child terminates print the exit status of child process.

Sample execution: -
1. No args passed (Print usage info)
./exe_child Usage: ./exe_child args...
2. Valid arg. passed
./exe_child date
This is the CHILD process, with id 11612
Wed Apr  4 13:27:19 IST 2012
Child exited with status 0
