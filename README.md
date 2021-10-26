# Copy_ls_command
In this project I tried to made of copy ls command with option <b>-t -a</b> of Linux

## Description
The ls command is used to list files or directories in Linux and other Unix-based operating systems.

![img](https://www.freecodecamp.org/news/content/images/2020/08/Screenshot-2020-08-20-at-9.40.29-PM.png)


### How ls command works 
 ls -flags  directory
List files including hidden files

Type the ls -a command to list files or directories including hidden files or directories. In Linux, anything that begins with a . is considered a hidden file:

![img](https://www.freecodecamp.org/news/content/images/2020/08/Screenshot-2020-08-21-at-11.12.26-AM.png)

Type the ls -t command to list files or directories and sort by last modified date and time in descending order

![img](https://www.freecodecamp.org/news/content/images/2020/08/Screenshot-2020-08-21-at-12.20.09-PM.png)

And ls -at command to list files or directories including hidden files or directories and then will  sort by last modified date and time in descending order


## Ls function and helper other function 
```
void my_ls(char** dirname, int indx, optn* flags_ls)(https://github.com/nurbolatkz/Copy_ls_command/blob/main/mylsfunc.c)- /* main ls function */

[void read_Dir(char* dir, optn* flags) ; ](https://github.com/nurbolatkz/Copy_ls_command/blob/main/readdir.c) - /* read given a directory by flags */

[void display_list(char** filenames, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/display.c) - /*print all sorted files by flags */

[char** sort_lex(char** my_arr, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) -  /* sort file names list in lexicographical order */

[char** sort_time(char** my_arr, int size, char* dirname);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) - /* list files and dirs sort by last modified time */ 

[void my_swap(char** a, char** b);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/stringfun.c) -   / * swap filenames in array  */

[char** sort_timedirs(char** dirname, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) -  /* sort filenames in subdirectories. Find path to file then get last modified time. When user entered other directories from current. */


```
void my_ls(char** dirname, int indx, optn* flags_ls)(https://github.com/nurbolatkz/Copy_ls_command/blob/main/mylsfunc.c)- /* main ls function */

[void read_Dir(char* dir, optn* flags) ; ](https://github.com/nurbolatkz/Copy_ls_command/blob/main/readdir.c) - /* read given a directory by flags */

[void display_list(char** filenames, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/display.c) - /*print all sorted files by flags */

[char** sort_lex(char** my_arr, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) -  /* sort file names list in lexicographical order */

[char** sort_time(char** my_arr, int size, char* dirname);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) - /* list files and dirs sort by last modified time */ 

[void my_swap(char** a, char** b);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/stringfun.c) -   / * swap filenames in array  */

[char** sort_timedirs(char** dirname, int size);](https://github.com/nurbolatkz/Copy_ls_command/blob/main/sorts.c) -  /* sort filenames in subdirectories. Find path to file then get last modified time. When user entered other directories from current. */

