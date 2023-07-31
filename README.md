# Header Script

## How to use me ?

### One time use (no install required)

To use the header script without any install requirements, just clone the repository and run `make`.
This will create inside said repository an executable file called `header`.
You will then be able to use the header script in two different ways :

1. By running `./header SOURCES_DIR FILE_TO_CREATE [FILES_TO_INCLUDE]` 
	as in `./header sources includes/header.h include1.h include2.h`
	Beware that all the files specified from `include1.h` will have their full provided path included.
	So don't write `includes/include1.h` when you want to include `include1.h`
2. By running `./header SOURCES_DIR FILE_TO_CREATE`
	That way, you will have to include manually all the files you need for you project to compile properly

### Local install

If you like the header script enough to want it to stay permanently on your computer then you can run `make install`.
This will compile the script and move the binary into a folder called .local/bin/ which resides in your home folder.
If you already have the norminette, it is very likely that this folder already exists and that the path to
this folder is already in your path variable.
If not, or if you see that running the command `header` doesn't print the help message, add the following line to
your "run commands" file (probably located at `~/.zshrc` or `~/.bashrc`) : `export PATH="$PATH:$HOME/.local/bin"

## What I am meant to do ?

To see further informations on this topic, go and see `how-it-works.md`. The informations given here will only
allow you to ensure that you don't get any surprise when using this script with your project.

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

### How 
