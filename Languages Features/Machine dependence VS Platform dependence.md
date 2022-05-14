#to-sort

> A program that run at any OS means, that is called platform independent and those programs run at any architecture of computer (hardware) are called machine independent and the phenomenon is platform and machine independency.

From [Wikipedia](http://en.wikipedia.org/wiki/Porting):

> Software is portable when the cost of porting it to a new platform is less than the cost of writing it from scratch. The lower the cost of porting software, relative to its implementation cost, the more portable it is said to be.

Machine-independent software, on the other hand, does not need any work to be ran on another machine (ex. from Windows to Mac OS). It is by this definition also highly portable.




----

C/C++ is machine independent. Because you can write a program code on any other configurations of hardware.

And, Platform independent is totally a different thing where you can write a program which supports on different environment of software .

As for example , Java is a platform independent .

----

Platform independence means that the same program works on any platform (operating system) without needing any modification where as platform dependent is exactly opposite of it, it is subjected to a specific platform which could be a hardware or an operating system.


A machine-dependent language works only on a specific computer system and its components. What it means is a code that you write on one particular system may not run in other system with different configurations.

A machine—independent language is a computer language that works on different computer systems regardless of their components. Thus a program written in one machine would run on any other machine.

For example: A program written on a machine with “xyz” configurations would work perfectly fine when run on a machine with “abc” configurations.

C language is a machine independent language because no matter which machine one writes in, it can be run on any other machine.

NOTE: Don't confuse “MACHINE INDEPENDENT” and “PLATFORM INDEPENDENT” as they are two completely different things.

---

JAVA

An important point to be noted is that while JAVA is platform-independent language, the JVM is platform-dependent. Different JVM is designed for different OS and byte code is able to run on different OS.

C

C Compiler is platform dependent since it is closely linked to the OS kernel which is different for different OS.

But over the years all OS's come with pre-installed compilers and libraries that make it quite platform independent for basic programming. For deeper low-level programming linked closely to the OS & HDLs (for eg when we are dealing with memory allocation tables) the behavior becomes more dependent on the platform and its relation with C Compiler.

C++

A C++ program may or may not be platform-dependent. If you call functions that are provided by the compiler on Windows and not in other operating systems, then your C++ program will compile only on Windows. That is a platform dependence. But if you avoid calling platform-dependent functions such as those, you can compile the C++ program anywhere.

C#

C# is designed to be a platform-independent language in the tradition of Java (although it is implemented primarily on Windows). It's syntax is similar to C and C++ syntax, and C# is designed to be an object-oriented language.

PHP

PHP is platform independent and can run on any platform — Linux, Unix, Mac OSX, Windows. This is because you can open source any platform. But when it comes to network programming, it is "handicapped", also, it can’t compete with Java in the area of platform-independence.

Python

Python and Java are interpreted languages, whereas C is a compiled language. Usually compiled languages are faster since they directly convert code to machine code, interpreted languages are platform-independent and code written in them are executed on the fly bypassing the compilation stage.

GO

Because go creates a machine code which is platform dependent and ... language If you have source code you can compile it in any platform.

----



----


Dependent :

> -   Requires the application to be run on specific hardware. 

-   Platform dependent typically refers to applications that run under only one operating system in one series of computers (one operating environment).
-   Example-Till now application developed in C#.NET was platform dependent.
-   Platform dependent means a software will work only in a particular platform it wont work in all platform means not in all os.

![](https://qphs.fs.quoracdn.net/main-qimg-8e71208ee37fc96b14a120829a4e9415)

Independent:

> -   will run on many kinds of hardware. 

-   Platform independence means executing a code irrespective of the Operating System on which it is being executed. Java is called a platform independence.
-   Platform independent means that the application can run in different operating system.
-   Example:Applications written in Java can run in any operating environment.
-   Ruby, Lisp, Scheme, Scala, Clojure, Python, Perl, PHP, C# (via Mono)... Honestly, the list could keep growing. It's much easier to narrow down your definition of platform independent or ask which languages ARE platform dependent. Java is platform independent because it runs on the Java Virtual Machine (Jvm).

----

Final thoughts:

Languages are always platform independent. No language needs you to write different code for different OS or device. It is the binary or the executables which are platform dependent or independent.