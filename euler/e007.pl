#!/usr/bin/perl

use strict;

my @prime_list = (2, 3, 5, 7);

sub is_prime {
	my ($n, $is_prime) = ($_[0], 1);
	foreach my $prime (@prime_list){
		last if $prime ** 2 > $_[0];
		next if($_[0] % $prime);
		$is_prime = 0;
		last;
	}
	return $is_prime;
}

for(my $i = 9; ; $i += 2){
	if(is_prime($i)){
		push(@prime_list, $i);
	}
	last unless($#prime_list < 10000);
}

print "$prime_list[-1]\n";
