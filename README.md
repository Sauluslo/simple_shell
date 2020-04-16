MY SIMPLE SHELL CONCEPTS
# What is a shell?
A shell is a user interface for access to an operating system's services.
In general, operating system shells use either a command-line interface (CLI) or graphica
user interface (GUI), depending on a computer's role and particular operation.
It is named a shell because it is the outermost layer around the operating system.

Concept for me: A shell is a interpeter of commands, is basically a program that takes commands
from the keyboard and gives them to the operating system to perform.

# Who designed and implemented the original Unix operating system?
Ken Thompson, Dennis Ritchie, Brian Kernighan, Douglas McIlroy, and Joe Ossanna at Bell Labs.

# ABOUT MY PROJECT
This project was written in C in order to emulate the linux sh shell and study how its background processes work.

# HOW INSTALL
If you want to test the functionality of this shell, follow the next steps:

|------------------------|
|(1)- Enter your terminal.
|(2)- Clone this repository.
|-->$ git clone https://github.com/Sauluslo/simple_shell.git
|(3)- Compiles all the * .c files that make up this program.
|-->$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh -g*|
|(4)- Run.
|-->$ ./hsh
|------------------------|

# USAGE

This shell behaves similarly to sh, once you have run the program, a commandprompt appears where you can type and execute the command you want.

Your shell should work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

# AUTHORS

Aldebaran Lopera <1617@holbertonschool.com>
