#!/usr/bin/perl

use 5.010;
use strict;
use warnings;

# 1st method (multi-line comments)
=for comment
say "What is your name? ";
my $name = <STDIN>;					# $name is called a scalar variable.
say "Hello $name, how are you?";

# Variables are declared using the `my` keyword.
# Scalar variables always start with a $ sign. The <STDIN> is the tool to read a line from the keyboard.
=cut


# 2nd method (multi-line comments)
=pod
comments
=cut

# 3rd method (multi-line comments)
=begin comment
123
=cut


#------------------------------------------------------------
# Getting rid of newlines

say "What is your name? ";
my $name = <STDIN>;
chomp $name;			# chomp to remove the trailing newlines from strings
say "Hello $name, how are you?";