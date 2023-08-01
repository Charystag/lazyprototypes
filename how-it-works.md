# How it Works

The objective of this document is to explain how the header script works so
you can take inspiration from it and modify it to make it more suitable to
your needs.

# Table Of Contents

1. [Gather Files](#Gather-all-the-required-files-from-a-directory)
2. [Extract Prototypes](#Extract-the-prototypes-in-a-temporary-file)
3. [Write header](#Writting-the-norm-compliant-header)
4. [Format header](#Formatting-the-header)

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
the following character is also a space or a tab. A tab accounts for `TABLEN` (which is 4 by default) in the
distance.

> More on the notion of distance [here](#Compute-the-actual-length-of-a-function-prototype) where I explain
> how I compute the length of a prototype

## What actually is a line of code ?

### Formatting

In C programming, it is possible to write such things as :
```c
struct s_return_type
my_function(struct s_argument_type identifier){
	/*code here*/
}
```

This will be counted as 4 different lines by the script and thus it will not detect that this is actually a function
declaration (actually I didn't test but I don't think it is going to end well if you do so).

However, to split a line of code you have another option :
```c
struct s_return_type my_function(struct s_argtype id1, \
struct s_argtype id2){
	/*code here*/
}
```
Even though there are 4 lines here, this will be seen by the script as 3 lines of code. The function `get_codeline`
(whose prototype is written below) reads the file and detects if the line that is just read ends with the 
sequence `"\\\n"`. If so, it reads the next line and concatenates it to the first one until the line doesn't 
end with `"\\\n"` anymore.<br/>
Here is the function prototype :
```c
int get_codeline(struct s_str **buff, FILE *fstream)
```
As it uses the function getline to retrieve the contents of the file, we need to give it a `FILE` pointer instead
of a regular file descriptor.

### Where is the line stored

To make the collection of the code lines easier, a special construct will be used. This struct's objective is to
transform the C strings referenced to by a `char *` into a complete type[^types] (page 36 of the referenced document).
That is, a type that olds its own size.<br/>
Here is the definition of the struct :
```c
struct s_str
{
	char	*str;
	size_t	len;
	size_t	size;
}
```
## What to do with one line of code ?

Once we retrieved our line of code we check if it is a function prototype. If so, we write it to our line of code to the
temporary header file, which is created in `/tmp` folder and holds the prototypes of our sources file, each prototype on
a separate line.

After that, once we have gathered all the prototypes from the source files, we can start cutting it to fit our needs,
that is, use the maximum we computed while checking for function prototypes to help us align our functions with the one
that is has the longest type declarations of all

# Writting the norm compliant header

## Give the proper format to our function prototypes

A function prototypes can be seen as splitted into 3 distincts parts. Let's take a random function prototype, with `|`
to visually separate the 3 parts :
```c
struct s_return_type|   |func_name(struct s_argument_type identifier);
```
We will now give a name to these 3 parts to make it easier to reference them later:

1. The first part will be called the **return part**. This is the part where lies the return type of the function
	and the function qualifiers. In this part, the only whitespaces the norm allows are *spaces*. They account for
	one in the total length of the prototype.
2. The second part will be called the **gap**. This is the part where we have to put right number of tab characters 
	to align the functions properly. In this part, the only whitespaces norm allows are *tabs*. They account for
	`TABLEN` in the total length of the prototype. I recall that this length is 4 by default.
3. The last part will be called the **input part**. This is the part where lies the function name and the major part
	of its signature[^signature]. In this part also, the only whitespaces the norm allows are *spaces*

Now that we have a better idea of what a function prototype is made of, we see that we will need to modify the return part
and the input part so that they only contain spaces (and no more that one space at a time) and that we will need to put
the right number of tabs in the gap so that the function is properly aligned.

## Compute the actual length of a function prototype

Now that we have our rules to properly format a function prototype, we can compute its length. Lets first recall
the new definition of the [length](#On-the-notion-of-distance) we gave earlier.
Each char accounts for 1 in the length, except the tab characters that account for `TABLEN`. We will call this new length
the ***tablen*** of our prototype.

### The actual number of tabs.

To know the number of tab characters that we will have to fill our gap with we remark that, for the function with
the largest return part, we still need one tab character.
So for this function, the number of tabs is : `max_distance / TABLEN - distance / TABLEN + 1`. <br/>
As `distance == max_distance` we have that there is indeed 1 tab character in the gap for that function <br/>
This allows us to remark that the distance we need to fill in other function is 
also : `max_distance / TABLEN - distance / TABLEN + 1`.

> :warning: Beware to not simplify this expression due to integer division

---

Once we have the number of tabs and the length of the return part and the input part. We can create a new string to write
those in and compute the tablen of the prototype. This tablen is the number we will use to know if we need to cut our
prototype for it to comply with the 42 norm.

## Slicing the prototype

In `header_int.h` is defined a preprocessor constant named `MAX_LINE_LEN`. This constant is by default at 79 (for a reason
we'll understand later on) and controls the maximum length that a line of code can have in the header file.
In the function `write_prototype` whose task is to write the prototypes in the header file and whose code is below :
```c
static int write_prototype(const char *line, int ofd, size_t length, const unsigned int max_distance)
```
We compute the tablen of a prototype and we use it to define the variable `lines_count = tabslen(prototype) / MAX_LINE_LEN + 1`.
If this variable is defined, we `realloc` the prototype to give it room for the `"\\\n"` strings we'll need to add in order
to make it norm compliant.

### The next separator

To make our prototype norm compliant, we need to cut it. To ensure that it is indeed following the norm guidelines, we will
try to cut it at the latest `','` where the tablen is smaller than the `MAX_LINE_LEN`. If no `','` is encountered we find
the last `'\t'` before `MAX_LINE_LEN`. When we get the index of the cut, we move all the bytes 2 positions forward in order to
make room for the two characters we need to add and we do so while the remanining tablen of the prototype is greater than
`MAX_LINE_LEN`

> Note that if no `','` and no `'\t'` is encountered before `MAX_LINE_LEN`, the script will make the header but it won't be
> norm compliant. One could argue that if we use the spaces to split the prototype it would lay the right result. I may
> fix it later (as using spaces throws unexpected results at the moment) but for now I will argue that if you need more
> than 80 characters for your function return type. ***YOU*** are the problem.

### Chotto matte ! Why is the max line length equal to 79 ?

When looking for the next separator, if a `','` is encountered, we move one position forward (to keep the `' '` on the same
line) before moving the characters. If the `','` is at position 79, our `' '` will then be at position 80 which is the
guideline provided by the norm.

# Formatting the header

This part, which is the last part of this version of the header script carries the objective of writting all the important
infos in the header script which are :

1. The 42 header (which is not dynamic now but will be fixed in another version)
2. The header protection (we're not allowed to use a pragma[^pragma] directive to do so in 42 headers)
3. Include the optional headers given as arguments
4. Write the `#endif` once we've written all the prototypes with the rules we discussed earlier.

## Header inclusion

To write all the directive wee need in our header file, we will use the `include_headers` function, whose prototype is
written below :
```c
static int include_headers(int header_fd, const char *header, char **includes)
```
In this function, `header` holds the path to the header file we have to create. We use the name of this file to create
the right header protection.

> Note to 42 students : This actually provided me with a use case of libft's function `ft_strmapi`

After that we iterate over the array of files to include in order to put in their place the include files specified
by the user.

## The 42 header

At the data at which this version is written (August 1^s^t^ 2023) the 42 header you will get is a 42 header with the
wrong name, author and dates. However the file you will get is sill norm compliant. From now on you have 3 options

1. Let the 42 header as it is (recommended if you don't want to modify your header at all)
2. Delete the header in the final folder and use a 42 header plugin to replace it with your own header
3. Wait for the next version of the script that will bring a fix to that an a lot more options.

# Final Words

Here it is, thanks for reading the explanations. Don't hesitate to send an email at <nsainton@student.42.fr> to report
any bug (be sure to use "HEADER\_SCRIPT -- subject" as your email subject).
Hope that this script will be of any use to you and that you learn something while reading it, see you soon for the
next update.

[^dirent]: <https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h>
[^types]: <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf>
[^signature]: <https://en.wikipedia.org/wiki/Function_prototype>
[^pragma]: <https://gcc.gnu.org/onlinedocs/cpp/Pragmas.html#index-_0023pragma-once>
