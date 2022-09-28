

 Pre-requisites:

    Knowledge about system calls, How to read and understand ‘man pages’.
    Good knowledge about processes & zombie process.
    Working of fork & wait system call.

Objective:

To understand different states of a process.

Requirements: 

    Create a child process avoid it become a zombie.
    To avoid zombie we need to call wait(), but this block parent until child terminates.
    So we need to use waitpid() with proper arguments (Read man page). 
    When child is working parent has to continuously print some message.
    When ever child terminates parent has to print child terminated and print exit status of child process

Sample execution:
./nonblock_wait
A child created with pid 1234
parent is running
parent is running
parent is running . .
............................
Child 1234 terminated normally with exit status 0 parent terminating
