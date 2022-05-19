#!/usr/bin/perl

=pod

=cut
use 5.010;
use strict;
use warnings;

print "Your name please: ";
my $myname = <STDIN>;
chomp $myname;

print "Your name is '$myname' \n";