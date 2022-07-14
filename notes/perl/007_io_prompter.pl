use 5.010;
use strict;
use warnings;
use IO::Prompter;

=pod
my $user = prompt 'Username: ';
my $passwd = prompt 'Password: ', -echo=>'*';

say $user;
say $passwd;
=cut


my $selection = prompt 'Choose ...', -menu => [qw(wealth health wisdom)], '>';
say $selection;