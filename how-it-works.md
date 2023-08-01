# How it Works

The objective of this document is to explain how the header script works so
you can take inspiration from it and modify it to make it more suitable to
your needs.

# Gather all the required files from a directory {#get-dir-entries}

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
> to the function `stat` defined in `unistd.h`. More infos at `man 2 stat` or at [man 2 stat](https://www.man7.org/linux/man-pages/man2/stat.2.html)

## How to retrieve directory entries ?



[^dirent]: <https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h>
