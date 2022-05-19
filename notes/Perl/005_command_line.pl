=pod
Printing a number

Now type in perl -e "print 42". This will print the number 42 on the screen. On Windows the prompt will appear on the next line

c:>perl -e "print 42"
42
c:>

On Linux you will see something like this:

gabor@pm:~$ perl -e 'print 42'
42gabor@pm:~$

Please note, I used single-quote ' in Linux and double-quote " on Windows.
This is due to the different behaviour of the command line on these two operating systems. Nothing to do with Perl.

In general on Linux/Unix always use single-quotes around the code snippet, on Windows always use double-quotes.

In this example we use the -e flag that tells perl, "Don't expect a file. The next thing on the command-line is the actual Perl code."




# Replace Java by Perl

This command: `perl -i.bak -p -e "s/\bJava\b/Perl/" resume.txt` will replace all appearance of 
the word Java by the word Perl in your résumé while keeping a backup of the file.

On Linux you could even write this perl -i.bak -p -e 's/\bJava\b/Perl/' *.txt to replace Java by Perl in all your text files.

(Again, please note, on Linux/Unix you should probably always use single-quotes on the command line, while on Windows double-quotes.)
=cut