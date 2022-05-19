#!/usr/bin/perl

use strict;
use warnings;
 
print "Hello World\n";



=hashbangline comments
We added #!/usr/bin/perl as the first line of our script:

When we run the script, we run it in our current shell environment. For most people on Linux/Unix 
that will be Bash. Bash will read the first line of the script. If it starts with a hash and a bang 
(hash-bang) #! then Bash will run execute the application that has its path on the hash-bang line 
(in our case /usr/bin/perl which is the standard location of the perl compiler-interpreter on most 
modern Unix-like system.

While we used #!/usr/bin/perl as our hash-bang line there can be other as well.
For example if we have installed another version of perl in a different location and we would like 
our scripts to use that, then we can put the path to that version of perl. For example 
`#!/opt/perl-5.18.2/bin/perl`

The advantage of setting a hash-bang (and turning on the executable bit) is that user does not have 
to know the script is written in Perl and if you have multiple instances of Perl on your system the 
hash-bang line can be used to pick which perl to be used. This will be the same for all the people 
on the specific machine. The drawback is that the perl listed in the hash-bang line is only used if 
the script is executed as ./hello.pl or as hello.pl. If it is executed as perl hello.pl it will use 
the version of perl that is found first in the directories listed in PATH. Which might be a different 
version of perl from the one in the hash-bang line.

Because of this, on modern Linux/Unix systems, people might prefer to use #!/usr/bin/env perl as the 
hash-bang line. When Bash sees this line it will first run the env command passing the name perl to 
it. env will find the first perl in the directories of PATH, and run that. So if we 
have #!/usr/bin/env perl in our script it will always use the first perl in our PATH. Both when 
it is executed as ./hello.pl and when it is executed as perl hello.pl. This too has a disadvantage, 
because this relies on the users setting their PATH environment correctly.

Here is a table that tries to explain the 4 cases:

  the hash-bang              Which perl is used to run the script when call it either of these ways:
                             ./hello.pl                    perl hello.pl

  /usr/bin/perl              /usr/bin/perl                 first perl in the PATH
  /usr/bin/env perl          first perl in the PATH        first perl in the PATH

* Flags on the hash-bang line

On the hash-bang line, after the path to perl we can add command-line flags to perl. You will 
probably see lots of scripts starting with #!/usr/bin/perl -w or maybe #!/usr/bin/env perl -w. 
The -w in this hash-bang turns on warnings. This is quite similar to what use warnings does, but 
this is the old style. You won't see this in most of the modern Perl scripts.

Another common flag that you might see on the hash-bang lines are -t and -T. They turn on the 
so-called taint-mode that will help you write more secure code.
=cut

















