When you see this in .h file:

```cpp
#ifndef FILE_H
#define FILE_H

/_ ... Declarations etc here ... _/

#endif
```

-   This is a `preprocessor technique` of preventing a header file from being included multiple times,
    which can be problematic for various reasons.
-   During compilation of your project, each .cpp file (usually) is compiled. In simple terms, this means the compiler will take your .cpp file, open any files #included by it, concatenate them all into one massive text file, and then perform syntax analysis and finally it will convert it to some intermediate code, optimize/perform other tasks, and finally generate the assembly output for the target architecture.
-   Because of this, if a file is #included multiple times under one .cpp file, the compiler will append its file contents twice, so if there are definitions within that file, you will get a compiler error telling you that you redefined a variable.
-   When the file is processed by the preprocessor step in the compilation process, the first time its contents are reached the first two lines will check if FILE_H has been defined for the preprocessor. If not, it will define FILE_H and continue processing the code between it and the #endif directive. The next time that file's contents are seen by the preprocessor, the check against FILE_H will be false, so it will immediately scan down to the #endif and continue after it.
-   This prevents redefinition errors.

*   In C++ programming as a general practice we separate development into two file types. One is with an extension of .h and we call this a "header file." They usually provide a declaration of functions, classes, structs, global variables, typedefs, preprocessing macros and definitions, etc. Basically, they just provide you with information about your code.
*   Then we have the .cpp extension which we call a "code file." This will provide definitions for those functions, class members, any struct members that need definitions, global variables, etc. So the .h file declares code, and the .cpp file implements that declaration.
*   For this reason, we generally during compilation compile each .cpp file into an object and then link those objects (because you almost never see one .cpp file include another .cpp file).

How these externals are resolved is a job for the linker.
When your compiler processes main.cpp, it gets declarations for the code in class.cpp by including class.h. It only needs to know what these functions or variables look like (which is what a declaration gives you). So it compiles your main.cpp file into some object file (call it main.obj). Similarly, class.cpp is compiled into a class.obj file.
To produce the final executable, a linker is invoked to link those two object files together. For any unresolved external variables or functions, the compiler will place a stub where the access happens.
The linker will then take this stub and look for the code or variable in another listed object file,
and if it's found, it combines the code from the two object files into an output file and replaces
the stub with the final location of the function or variable. This way, your code in main.cpp can
call functions and use variables in class.cpp IF AND ONLY IF THEY ARE DECLARED IN class.h.

Include guard goals:

generate once, when creating a header
-never have to think about again
-chance of duplicating is less than your chance of winning the lottery
-Bad include guard names (for file "config.h"):

CONFIG_H

-   much too general
-   \_CONFIG_H, CONFIG**H, CONFIG_H**, **CONFIG_H**, etc.
-   all reserved, still much too general
    PROJECT_CONFIG_H
-   better, much less likely to duplicate in unrelated projects
-   but still no path information, easy to duplicate in large projects

---

Good include guard names (for file "config.h"):

`PATE*20091116_142045` that's <last name>\*<date>\_<time>
no project, path, filename information even needed easy to type if your editor has an insert-date feature, you can "type" it very fast easy to generate include a sequence number when generating, if you need to generate more than one per second strong guarantee of being universally unique

`INCLUDE_GUARD_726F6B522BAA40A0B7F73C380AD37E6B` generated from an actual UUID strong guarantee of being universally unique if it turns up unexpectedly, "INCLUDE_GUARD" is a good hint about what it is, while serving to put it in a separate namespace (though by convention rather than recognized by the language)
prepend a project name, if desired (which is often required by project guidelines for macros).
