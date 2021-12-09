# 0x16. C - Simple Shell

## Description

In this project we are tasked with creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error.

---

## Instructions

* Compiling the program:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

* Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

* Non-interactie mode:
```
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
```
---

## Examples

/mnt/d/COHORTE 16 HOLBERTON/simple_shell$ /bin/ls -l                           
total 56
-rwxrwxrwx 1 root root   220 Dec  8 12:42 AUTHORS
-rwxrwxrwx 1 root root  3176 Dec  8 12:53 README.md
-rwxrwxrwx 1 root root  2449 Dec  7 18:39 folder_fun.c
-rwxrwxrwx 1 root root  3112 Dec  7 18:39 folder_fun_1.c
-rwxrwxrwx 1 root root  1191 Dec  7 18:39 folder_fun_2.c
-rwxrwxrwx 1 root root  1227 Dec  7 19:15 function.c
-rwxrwxrwx 1 root root 22528 Dec  8 18:58 hsh
-rwxrwxrwx 1 root root  1012 Dec  8 11:18 main.c
-rwxrwxrwx 1 root root  1349 Dec  8 11:18 main.h
-rwxrwxrwx 1 root root   981 Dec  7 19:40 man_1_simple_shell
/mnt/d/COHORTE 16 HOLBERTON/simple_shell$ 


---

## Files

File|Description
---|---
[README.md](./README.md)|File description
main.c |  Main function of the program
folder_fun.c | Delete global vr
folder_fun_1.c | Delete global vr
folder_fun_2.c | Delete global vr
function.c | Every functions for development of the project.
main.h | Prototype and functions
man_1_simple_shell | man simple shell

---

## Project Requirements
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags `-Wall -Werror -Wextra and -pedantic`
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style.
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

---

## Tasks

### 0. README, man, AUTHORS
* Write a README/
* Write a man for your shell.
* You should have an (AUTHORS)[./AUTHORS] file at the root of your repository, listing all individuals having contributed content to the repository.

### 1. Betty would be proud
* Write a beautiful code that passes the Betty checks

### 2. Simple shell 0.1
* Write a UNIX command line interpreter.
* Your Shell should:
	- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	- The prompt is displayed again each time a command has been executed.
	- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
	- The command lines are made only of one word. No arguments will be passed to programs.
	- If an executable cannot be found, print an error message and display the prompt again.
	- Handle errors.
	- You have to handle the "end of file" condition (Ctrl+D)

### 3. Simple shell 0.2
* Handle command lines with arguments

### 4. Simple shell 0.3
* Handle the PATH

### 5. Simple shell 0.4
* Implement the exit built-in, that exits the shell
* Usage: exit
* You dont have to handle any argument to the built-in exit

### 6. Simple shell 1.0
* Implement the env built-in, that prints the current environment

### 7. What happens when you type ls -l in the shell


## Authors
* **Reinaldo Castro** - [Rcastro89](https://github.com/Rcastro89)
* **Nelson Gallego** - [NELSONANDREY](https://github.com/NELSONANDREY)
