# SHELL SCRIPTING

#bash-shell

![[https://www.linuxjournal.com/sites/default/files/styles/360_250/public/nodeimage/story/bash-icon_0.png?itok=JZG6p4sq]]


> Linux shell scripting is used to help automate routine tasks

### 0. A bit of overview
Linux has a variety of different shells Like ==Bourne shell (sh), C shell (csh), Korn shell (ksh), TC shell (tcsh), Bourne Again shell (bash)==. Certainly the most popular shell is “bash”. 
Bash is an sh-compatible shell that incorporates useful features from the Korn shell (ksh) and C shell (csh). 
bash is not only an excellent command line shell, but a scripting language in itself. Shell scripting allows us to use the shell’s abilities and to automate a lot of tasks that would otherwise require a lot of commands.

Bash shell is the most common command line interpreter for Linux operating system. It is a result of decades of development of various command line interpreters,each building up on its predecessor good features, and adding its own improvements.

In today’s world, scripting is gaining ground everywhere-from network devices to supercomputers. Once you master Bash for common administrative task, you can go ahead and learn Python or Perl more easily, because you have a solid foundation on what Linux can and can not do.

Although Bash is not a full-blown programming languages, with it’s loops, conditions, variables, chaining multiple commands together, shell scripts have grown to be much more than just command line expressions put together.

Bash scripting will help you automate routine tasks and save valuable time, whether you’re a sys admin, Linux user or software developer. Shell script is much quicker than programming in any other languages.


> ORDER OF EXECUTION is top to bottom in a shell script!

Shell is a high level language. We don't have to worry about low-level programming objects like bytes, pointers and types!


> ### KIM
> Anything that you can do on the command line can be automated by writing a shell script.

# 1. Typographical Conventions Used in This Tutorial

Significant words will be written in _italics_ when mentioned for the first time.

Code segments and script output will be displayed as monospaced text.  
Command-line entries will be preceded by the Dollar sign ($). If your prompt is different, enter the command:

```
PS1="$ " ; export PS1
```

Then your interactions should match the examples given (such as `./my-script.sh` below).  
Script output (such as "Hello World" below) is displayed at the start of the line.
```
$ echo '#!/bin/sh' > my-script.sh
$ echo 'echo Hello World' >> my-script.sh
$ chmod 755 my-script.sh
$ ./my-script.sh Hello World 
$
```
Entire scripts will be shown with a gray background, and include a reference to the plain text of the script, where available:


```
#!/bin/sh
# This is a comment!
echo Hello World	# This is a comment, too!
```

Note that to make a file executable, you must set the eXecutable bit, and for a shell script, the Readable bit must also be set:

$ chmod a+rx my-script.sh
$ ./my-script.sh


# 2. Philosophy

Shell script programming has a bit of a bad press amongst some Unix systems administrators. This is normally because of one of two things:

-   The speed at which an interpreted program will run as compared to a C program, or even an interpreted Perl program.
-   Since it is easy to write a simple batch-job type shell script, there are a lot of poor quality shell scripts around.

It is partly due to this that there is a certain machismo associated with creating _good_ shell scripts. Scripts which can be used as CGI programs, for example, without losing out too much in speed to Perl (though both would lose to C, in many cases, were speed the only criterion).  
There are a number of factors which can go into good, clean, quick, shell scripts.

-   The most important criteria must be a clear, readable layout.
-   Second is avoiding unnecessary commands.

A clear layout makes the difference between a shell script appearing as "black magic" and one which is easily maintained and understood.  
You may be forgiven for thinking that with a simple script, this is not too significant a problem, but two things here are worth bearing in mind.

1.  First, a simple script will, more often than anticipated, grow into a large, complex one.
2.  Secondly, if nobody else can understand how it works, you will be lumbered with maintaining it yourself for the rest of your life!

Something about shell scripts seems to make them particularly likely to be badly indented, and since the main control structures are if/then/else and loops, indentation is critical for understanding what a script does.

One weakness in many shell scripts is lines such as:

```
cat /tmp/myfile | grep "mystring"
```

which would run much faster as:

```
grep "mystring" /tmp/myfile
```

Not much, you may consider; the OS has to load up the `/bin/grep` executable, which is a reasonably small 75600 bytes on my system, open a `pipe` in memory for the transfer, load and run the `/bin/cat` executable, which is an even smaller 9528 bytes on my system, attach it to the input of the pipe, and let it run.

Of course, this kind of thing is what the OS is there for, and it's normally pretty efficient at doing it. But if this command were in a loop being run many times over, the saving of not locating and loading the `cat` executable, setting up and releasing the pipe, can make some difference, especially in, say, a CGI environment where there are enough other factors to slow things down without the script itself being too much of a hurdle. Some Unices are more efficient than others at what they call "building up and tearing down processes" - i.e., loading them up, executing them, and clearing them away again. But however good your flavour of Unix is at doing this, it'd rather not have to do it at all.

As a result of this, you may hear mention of the Useless Use of Cat Award (UUoC), also known in some circles as **The Award For The Most Gratuitous Use Of The Word Cat In A Serious Shell Script** being bandied about on the `comp.unix.shell` newsgroup from time to time. This is purely a way of peers keeping each other in check, and making sure that things are done right.

Which leads me nicely on to something else: Don't _ever_ feel too close to your own shell scripts; by their nature, the source cannot be closed. If you supply a customer with a shell script, s/he can inspect it quite easily. So you might as well accept that it will be inspected by anyone you pass it to; use this to your advantage with the [GPL](http://www.gnu.org/copyleft/gpl.html) - encourage people to give you feedback and bugfixes for free!


# 3. A First Script

For our first shell script, we'll just write a script which says "Hello World". We will then try to get more out of a Hello World program than any other tutorial you've ever read :-)  
Create a file (first.sh) as follows:



[first.sh](https://www.shellscript.sh/eg/first.sh.txt)
```
#!/bin/sh # This is a comment! 
echo Hello World # This is a comment, too!
```



The first line tells Unix that the file is to be executed by /bin/sh. This is the standard location of the Bourne shell on just about every Unix system. If you're using GNU/Linux, /bin/sh is normally a symbolic link to bash (or, more recently, dash).

The second line begins with a special symbol: `#`. This marks the line as a comment, and it is ignored completely by the shell.  
The only exception is when the _very first_ line of the file starts with `#!` - as ours does. This is a special directive which Unix treats specially. It means that even if you are using csh, ksh, or anything else as your interactive shell, that what follows should be interpreted by the Bourne shell.  
Similarly, a Perl script may start with the line `#!/usr/bin/perl` to tell your interactive shell that the program which follows should be executed by perl. For Bourne shell programming, we shall stick to `#!/bin/sh.`

The third line runs a command: `echo`, with two parameters, or arguments - the first is `"Hello"`; the second is `"World"`.  
Note that `echo` will automatically put a single space between its parameters.  
The `#` symbol still marks a comment; the # and anything following it is ignored by the shell.

now run `chmod 755 first.sh` to make the text file executable, and run `./first.sh`.  
Your screen should then look like this:
```
$ chmod 755 first.sh  
$ ./first.sh  
Hello World  
$
```
You will probably have expected that! You could even just run:
```
$ echo Hello World  
Hello World  
$
```
Now let's make a few changes.  
First, note that `echo` puts ONE space between its parameters. Put a few spaces between "Hello" and "World". What do you expect the output to be? What about putting a TAB character between them?  
As always with shell programming, try it and see.  
The output is exactly the same! We are calling the `echo` program with two arguments; it doesn't care any more than `cp` does about the gaps in between them. Now modify the code again:
```
#!/bin/sh  
# This is a comment!  
echo "Hello      World" # This is a comment, too!
```
This time it works. You probably expected that, too, if you have experience of other programming languages. But the key to understanding what is going on with more complex command and shell script, is to understand and be able to explain: WHY?  
`echo` has now been called with just ONE argument - the string "Hello    World". It prints this out exactly.  
The point to understand here is that the shell parses the arguments BEFORE passing them on to the program being called. In this case, it strips the quotes but passes the string as one argument.  
As a final example, type in the following script. Try to predict the outcome before you run it:



[first2.sh](https://www.shellscript.sh/eg/first2.sh.txt)
```
#!/bin/sh  
# This is a comment!  
echo "Hello      World" # This is a comment, too!  
echo "Hello World"  
echo "Hello * World"  
echo Hello * Worldecho Hello Worldecho "Hello" Worldecho Hello "     " Worldecho "Hello "*" World"  
echo `hello` world
echo 'hello' world
```


Is everything as you expected? If not, don't worry! These are just some of the things we will be covering in this tutorial ... and yes, we will be using more powerful commands than `echo`!


# 4. Variables - Part I
Just about every programming language in existence has the concept of _variables_ - a symbolic name for a chunk of memory to which we can assign values, read and manipulate its contents. The Bourne shell is no exception, and this section introduces that idea. This is taken further in [Variables - Part II](https://www.shellscript.sh/variables2.html) which looks into variables which are set for us by the environment.  
Let's look back at our first Hello World example. This could be done using variables (though it's such a simple example that it doesn't really warrant it!)



