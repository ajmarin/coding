#!/usr/bin/perl

use strict;

my $n = 600851475143;

sub factor {
	while(!($_[0] & 1)){ $_[0] >>= 1; }
	while(!($_[0] % 3)){ $_[0] /= 3; }
	for(my $i = 5; ; ++$i){
		my $j = $i + 2;
		while(!($_[0] % $i)){ $_[0] /= $i; }
		while(!($_[0] % $j)){ $_[0] /= $j; }
		last unless($j ** 2 < $_[0]);
	}
}
factor $n;
print "$n\n"

