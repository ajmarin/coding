#!/usr/bin/perl

use strict;

my $ans = 1;

sub gcd {
	my ($a, $b) = @_;
	return $b ? gcd($b, $a % $b) : $a;
}

for(my $i = 2; $i <= 20; ++$i){
	$ans = $ans * $i / gcd($ans, $i);
}

print("$ans\n");

