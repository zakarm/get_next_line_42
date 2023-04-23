# get_next_line_42 🚧

## Requirements :
The function is written in C language and thus needs the gcc || cc compiler and some standard C libraries to run.

## Introduction 🚪 :

```
  You will understand how files are opened, read and closed in an OS,
  and how they are interpreted by a programming language for further analysis.
  This task is crucial to understand for a future programmer since much of the time is based
  on manipulating files for data management and persistence.
  This project consists of coding a function that returns one line at a time from a text file.
```

## Description 📙 :

The project is a program that reads a line from a file descriptor and returns that line. The function is called get_next_line and it takes an integer file descriptor as its parameter. It returns a string (char*) containing the line that was read from the file descriptor. If there is nothing else to read or if an error occurred, it returns NULL.

The program uses the read function to read from the file descriptor, and the malloc and free functions to allocate and free memory dynamically. The program also includes a header file called get_next_line.h, which contains the prototype of the get_next_line function.

To make the program more efficient, a buffer size is defined using the -D BUFFER_SIZE=n compiler flag, which defines the buffer size for the read function. The buffer size can be modified by peer evaluators and the Moulinette to test the code.

The program is designed to read files one line at a time, rather than reading the whole file and then processing each line. To achieve this, the get_next_line function reads as little as possible each time it is called, and returns the current line when it encounters a new line character. The program can handle binary files, but this behavior is not well-defined.

The program should be able to compile with or without the -D BUFFER_SIZE flag, and the default buffer size can be set by the programmer. The get_next_line function has undefined behavior if the file pointed to by the file descriptor changed since the last call, but the read function did not reach the end of the file.
