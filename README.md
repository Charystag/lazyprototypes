# Lazy Header Script

## How to use it ?

### One time use (no install required)

To use the header script without any install requirements, just clone the repository and run `make`.
This will create inside said repository an executable file called `lazyprototypes`.
You will then be able to use the header script in two different ways :

1. By running `./lazyprototypes SOURCES_DIR FILE_TO_CREATE [FILES_TO_INCLUDE]`<br/>
	as in `./lazyprototypes sources includes/header_name.h include1.h include2.h`
	Beware that all the files specified from `include1.h` will have their full provided path included.
	So don't write `includes/include1.h` when you want to include `include1.h`
2. By running `./lazyprototypes SOURCES_DIR FILE_TO_CREATE`<br/>
	That way, you will have to include manually all the files you need for you project to compile properly

### Local install

If you like the header script enough to want it to stay permanently on your computer then you can run `make install`.
This will compile the script and move the binary into a folder called .local/bin/ which resides in your home folder.
If you already have the norminette, it is very likely that this folder already exists and that the path to
this folder is already in your path variable.
If not, or if you see that running the command `lazyprototypes` doesn't print the help message, add the following line to
your "run commands" file (probably located at `~/.zshrc` or `~/.bashrc`) : `export PATH="$PATH:$HOME/.local/bin"`

## What is it meant to do ?

To see further informations on this topic, go and see [how-it-works](docs/how-it-works.md). The informations 
given here will only allow you to ensure that you don't get any surprise when using this script with your project.

### What is the expected result ?

What you're going to get is an output that is very similar to which inside the `test.h` file under the folder `tests`.
The header script will parse all the sources in the folder (and all subfolders) you provided in order to write a
norm compliant 42 header.

### Another header script ? Why do I need your crap ?

I get it, you're already using a header script (or your time is so low value that you write all you prototypes by hand
and that's okay too). This is what I noted in other header scripts (some of these flaws also target mine), that 
convinced me to do better :

1. Line returns weren't taken into account.
	This forced me to write my function prototypes on one line (even for very long function names) and to norm this
	part of the code at the very end of my project
2. Commented part of the code were, inversely, taken into account.
	This forced me to remove commented functions altogether even if I wanted to comment a function that I knew I needed
	but that wasn't working in order to test another part of my code
3. Header was not norm compliant.
	As I am going to use this header script for school projects, I want it to create a header that I can forget about
	and push without having to modify. This is what that script does.

### On the length of a tab character

Usually, a tab character is of length 8 (that is, tabstops are at a distance of 8 spaces). However if you do so, it becomes
a pain in the ass to align variables to comply with 42 norm. In the script, the variable `TABLEN` which is defined in
`header_int.h` allows you to control the length of a tab character, and to use it align the variables properly.
You can basically set it to any value, but I recommend using 4 spaces wide tabs (and thus letting it set to 4).
To modify it, just run make with the value of `TABLEN` you want to set. <br/> For example : `make TABLEN=8` or
`make re TABLEN=8`. <br/>
However, know that if you modify it (and modify the rendering accordingly in your text editor, for me it is vim) you wil
get an aligned result with your desired tab length.

### How to write your C files ?

Even if the Script fixes a lot of problems I encountered, they are still a few rules that can (and will) be improved later.

For now, the only (and last) rule you have to follow are :

1. Always put a `\` if you want to split your function prototype on multiple lines
	That is, do :
	```c
	struct s_return_type	my_func(struct s_type identifier, \
	struct s_another_type another_identifier)
	{
		/*code here*/
	}
	```
	Rather than :
	```c
	struct s_return_type	my_func(struct s_type identifier, 
	struct s_another_type another_identifier)
	{
		/*code here*/
	}
	```

2. Write your functions return types on the same line as your function name
	That is do :
	```c
	struct s_return type	my_func(struct s_type identifier){
		/*code here*/
	}
	```
	Rather than :
	```c
	struct s_return type
	my_func(struct s_type identifier){
		/*code here*/
	}
	```

Aside from those two rules (and some bugs that you users might discover and that I'll be more than happy to fix), you can
write your C files as you wish. Go check the `test.c` file in the `tests` folder and the resulting `test.h` file.

### What about the other files ?

Right now, there is defined variable in the file called `header_int.h` (whose name is the legacy of a time when the header
script wasn't as good as it is now). This variable called `EXT` controls the source file that are looked for by the script.
If you want, you can modify it and use the script to parse other types of files, I didn't test it with other files extensions
but as soon as you respect the two rules I stated earlier it should be working the same.
To modify this variable, run `make` with the value of `EXT` you want to set. <br/> For example : `make EXT=.cpp` or
`make re EXT=.cpp`. <br/>
Another update of the header script will come to fix it and allow the user to specify the files to look for when running
the script.

### What now ? You done talking ?

Now, go on and use the script as you like. It is yours as soon as it arrives on your computer. Don't hesitate to report bugs
for me to fix them as soon as I can (or if you want to go through the code by yourself feel more than free to fork, fix and
make a pull request for the change).

### Wait ! What if I don't want it anymore ?

If you want the header script to go, just run `make uninstall` in the script folder and you will be all set. Thanks for
installing it in the first place.

### Acknowledgements

Thanks to rmechety for having provided his version of a Headermaker script written in cpp. This encouraged me to provide my
own version that wanted to offer another way to automate header creation. Feel free to check out his version which is
available at [Headermaker](https://github.com/rmechety/Headermaker)
