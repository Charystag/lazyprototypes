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
- **Member types**
	- `DIR` : A structure representing a directory stream. Usually opaque to users
	- `struct dirent` : 

[^dirent]: <https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h>
