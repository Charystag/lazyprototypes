# How it Works

The objective of this document is to explain how the header script works so
you can take inspiration from it and modify it to make it more suitable to
your needs.

# Table Of Contents

1. [Gather Files](#Gather-all-the-required-files-from-a-directory)
2. [Extract Prototypes](#Extract-the-prototypes-in-a-temporary-file)

# Gather all the required files from a directory

## The dirent library

This library [^dirent], although not included in the C standard is usually portable between
platforms. It is used by including the header `dirent.h` and provides constructs
and functions that facilitate directory traversing. <br/>
Here is a list of the constructs and functions we'll need to retrive the
directory entries we're looking for :

- **Functions**
	- `DIR *opendir(const char *dirname)` : Opens a directory stream corresponding to the directory
		named by dirname
	- `int closedir(DIR *dirp)` : Closes the directory stream referred to by dirp.
	- `struct dirent *readdir(DIR *dirp)` : Returns a pointer to a structure representing the entry
		at the current position in the stream and positions the stream at the next entry
- **Member constants** (defined in `stdio.h`)
	- `NAME_MAX` / `FILENAME_MAX` : The maximum length of `d_name`
- **Member types**
	- `DIR` : A structure representing a directory stream. Usually opaque to users
	- `struct dirent` : A struct that contains at least the member `char d_name[]`
		a char array containing the entry name that will not exceed a size of NAME_MAX.

> In addition to the member `d_name`, the struct dirent can contain a number `unsigned int d_type` that
> holds the type of file pointed to by the entry. One could replace the use of this member by a call
> to the function `stat` defined in `unistd.h`. More infos at `man 2 stat` or 
> at [man 2 stat](https://www.man7.org/linux/man-pages/man2/stat.2.html)

## How to retrieve directory entries ?

The function called `get_dir_entries` will allow us to retrieve all the needed entries from a given directory
and all subdirectories. Here is its prototype :
```c
int get_dir_entries(const char *path, struct s_lit **lst, const char *ext)
```
This function will put all the entries in a linked list and return the status of the operation. Here is how
it will proceed :

1. First it opens the directory
2. While there is something to read in the directory stream, do the following operations
	1. Create the path to the file by concatenating with sprintf the input path and the name of the entry
	2. If the type of the entry is not that of a directory, check its extension, if it is a wrong extension
		go to the next entry. If it is right, add it to the list of files.
	3. If it is a directory that is not `.` or `..` then recursively apply the function `get_dir_entries` to it
		with the new path to that directory as an argument
3. If everything went well, you now have a linked list containing all the paths to the file you want to parse
	as a result

# Extract the prototypes in a temporary file

To create a norm compliant header file, we will need to :

- Establish criterions to define which line of code is a prototype, and which isn't.
- Define how lines of code will be retrieved, in order to ensure that the data we get is the data we see
- Know the maximum distance of a function name from the left of the screen (which will allow us to align
	all the functions properly

To achive such a result, we will create a temporary header file first. As we need to know the maximum
distance among all source files, we can't create the norm compliant header in one go.

## What is a function prototype ?

### Rules to define a prototype

These are the rules I defined to know if a line of code is a function prototype :

1. It has to begin with an alphabetic character or a `_`
2. It has to contain an open parenthesis
3. If it contains the `static` keyword, this keyword has to be after the first parenthesis
4. If the first 'm' before the first parenthesis is the string `main` then it shouldn't be included in the header

### On the notion of distance

The function that checks if a line of code is a function prototype also has the role of computing the distance
from this prototype to the beginning of the line (to compute the proper number of tab characters to put in order
to align all the functions). This distance is computed until the first `' '` or `'\t'` between the end of types
declaration and the function name. It is computed as such : <br/>
Each character increases the distance of 1 except if : the character we're looking at is a space or a tab and
the following character is also a space or a tab.

## What actually is a line of code ?

### Formatting

In C programming, it is possible to write such things as :
```c
```
[^dirent]: <https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h>
