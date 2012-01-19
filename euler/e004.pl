#!/usr/bin/perl

use strict;

my $ans = 0;

sub palindrome {
	my $num = $_[0] . '';
	return reverse($num) eq $num;
}

for(my $i = 100; $i < 1000; ++$i){
	for(my $j = $i; $j < 1000; ++$j){
		my $p = $i * $j;
		if(palindrome($p) and $p > $ans){
			$ans = $p;
		}
	}
}

print "$ans\n";
