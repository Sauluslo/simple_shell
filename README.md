|-------------------------------------------------------------------|
|--------------------- MY SIMPLE SHELL CONCEPTS --------------------|
|-------------------------------------------------------------------|
|What is a shell?|
|----------------|
|A shell is a user interface for access to an
|operating system's services. In general,
|operating system shells use either a command-line
|interface (CLI) or graphical user interface (GUI),
|depending on a computer's role and particular operation.
|It is named a shell because it is the outermost layer around
|the operating system.
|-------------------------------------------------------------------|
|Concept for me: A shell is a interpeter of commands, is basically
|a program that takes commands from the keyboard and gives them to 
|the operating system to perform.
|-------------------------------------------------------------------|
|Who designed and implemented the original Unix operating system?|
|----------------------------------------------------------------|
|Ken Thompson, Dennis Ritchie, Brian Kernighan, Douglas McIlroy, 
|and Joe Ossanna at Bell Labs.
|-------------------------------------------------------------------|
|Who wrote the first version of the UNIX shell?|
|----------------------------------------------|
|The first Unix shell was the Thompson shell, sh, written by 
|Ken Thompson at Bell Labs and distributed with Versions 1 through 6
|of Unix, from 1971 to 1975.
|-------------------------------------------------------------------|
|Who invented the B programming language (the direct predecessor to
|the C programming language)?|
|----------------------------|
|Ken Thompson and Dennis Ritchie.
|-------------------------------------------------------------------|
|Who is Ken Thompson?|
|--------------------|
|Is an American pioneer of computer science. Thompson worked at 
|Bell Labs for most of his career where he designed and implemented
|the original Unix operating system. He also invented the B 
|programming language,the direct predecessor to the C programming 
|language, and was one of the creators and early developers of the 
|Plan 9 operating system. Since 2006, Thompson has worked at Google,
|where he co-invented the Go programming language.
|-------------------------------------------------------------------|
|How does a shell work?|
|----------------------|
|reads its standard input from your terminal, and sends its standard
|output and standard error back to your terminal unless you tell it
|to send them elsewhere.
|-------------------------------------------------------------------|
|What is a pid and a ppid?|
|-------------------------|
|PPID = Each process is assigned a parent process ID (PPID) that 
|tells which process started it. The PPID is the PID of the processs
|parent.
|PID = When a process is started, it is given a unique number called
|process ID (PID) that identifies that process to the system.
|-------------------------------------------------------------------|
|How to manipulate the environment of the current process?
|
|
|
|
|
|
|
|
|-------------------------------------------------------------------|
|What is the difference between a function and a system call?
|
|
|
|
|
|
|
|-------------------------------------------------------------------|
|How to create processes?
|
|
|
|
|
|
|
|
|-------------------------------------------------------------------|
|What are the three prototypes of main?|
|--------------------------------------|
|So far we have seen that main could have different prototypes:
|int main(void);
|int main(int argc, char **argv);
|int main(int argc, char **argv, char **env);
|-------------------------------------------------------------------|
|How does the shell use the PATH to find the programs?
|
|
|
|
|
|
|
|
|-------------------------------------------------------------------|
|How to execute another program with the execve system call?
|
|
|
|
|
|
|
|
|-------------------------------------------------------------------|
|How to suspend the execution of a process until one of its children 
|terminate?|
|----------|
|A call to wait() blocks the calling process until one of its child
|processes exits or a signal is received. After child process 
|terminates, parent continues its execution after wait system call
|instruction.
|Example:
|C program to demonstrate working of wait() 
|#include<stdio.h> 
|#include<stdlib.h> 
|#include<sys/wait.h> 
|#include<unistd.h> 
|  
|int main() 
|{ 
|    pid_t cpid; 
|    if (fork()== 0) 
|        exit(0);           /* terminate child */
|    else
|        cpid = wait(NULL); /* reaping parent */
|    printf("Parent pid = %d\n", getpid()); 
|    printf("Child pid = %d\n", cpid); 
|  
|    return 0; 
|} 
|-------------------------------------------------------------------|
|What is EOF / end-of-file?|
|--------------------------|
|In computing, end-of-file (commonly abbreviated EOF) is a condition
|in a computer operating system where no more data can be read from 
|a data source. The data source is usually called a file or stream.
|-------------------------------------------------------------------|
