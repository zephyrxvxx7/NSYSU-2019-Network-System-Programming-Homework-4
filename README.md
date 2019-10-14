# 2019 Network System Programming Homework 4

This homework focuses on system programming and pipe.

## Part 1

1. Write, compile, and run a program named **hostinfo** that prints out system information in the following format.

2. Write, compile, and run a program named **mydate** that prints out the day and time in the following format.

3. Write a program called **printdir** that prints the current directory. Determine what size buffer to pass to **getcwd()** for dynamic allocation.( **Do not** use pwd().)

4. Write a program called **mycat** that is a simple version of the program cat. The program takes exactly one file name as argument; you should open it for reading and display its contents to the screen.

   Check that there is exactly one argument (argc == 2) and if not, display the usage message ”Usage: mycat filename”.

5. Write **pipe_ls** to practice using **pipe()** and **dup()**. Have your process start ls (using **fork()** and **exec()** ) but read the output from ls over a pipe. The ls program writes output on descriptor 1, so some work has to be done to get the pipe connected.

    Write what you read on the pipe to **stdout**.

## Part 2

1. Edit the **builtin.c** file to recognize **cd** , **pwd** , **id** , **hostname** and **builtin**. Write functions implementing these commands, and compile then into your shell. The **builtin** command lists the functions built into your shell.

    _Files provided:_
    _builtin.c, parse.c, shell.c, shell.h_

2. Modify the **redirect_in.c** file to recognize standard input and **redirect_out.c** file to recognize standard output. Add code to the **pipe_present.c** file to check for the pipe symbol. Add code to the **pipe_command.c** file to create a process to execute each of the pipe. Modify **is_background.c** to check the “&” symbol. Alter the **run_command.c** file to call these functions.

    _Files provided:_
    _redirect_in.c, redirect_out.c, run_command.c, pipe_present.c, pipe_command.c,_
    _is_background.c_

## Part 3

1. The first look up project lab familiarizes you with the format of the dictionary by completing the **convert.c** program that creates the dictionary of fixed-length records (fixrec) from a file of variable-length entries (dict). Add code to **convert.c** to change an editable file into a fixed-length record format.

    _File provided:_
    _convert.c, dict.h, dict_

2. Add code to the **lookup1.c** file to do a simple linear search through a file of fixed length records. Link with **main.c** , the user interface module.

    _File provided:_
    _lookup1.c, main.c_

**Rules:**

1. Please use C language in this homework and run your program on Ubuntu 18.04.
2. Please provide Makefile to compile your homework; otherwise, you will get ZERO.
3. Do not copy others homework.
4. If you have any question, please send email to sp_ta@net.nsysu.edu.tw or come to F5018, but TA does not help to debug.

**Upload:**

1. Please compress your homework into zip or tar archive.
2. Upload your homework to **NSYSU Cyber University**.
3. Naming rules:" **StudentID_SP_HW4.zip** ".

    For example: D083040001_SP_HW4.zip
4. Deadline: 2019/10/15 23:59
