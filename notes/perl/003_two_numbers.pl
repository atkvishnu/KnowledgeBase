#!/usr/bin/perl

=question
Write a script that asks the user for two numbers, one after the other. 
Then prints out the sum of the two numbers.
=cut


use strict;
use warnings;
use 5.010;

say "Please enter 2 numbers to add! ";
my $num1 = <STDIN>;
my $num2 = <STDIN>;
my $sum = $num1 + $num2;

say "Sum is $sum";