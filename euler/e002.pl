#!/usr/bin/perl

use strict;

my @fib = (0, 1);
my $sum = 0;

for(my $i = 2; ; ++$i){
	$fib[$i] = $fib[-1] + $fib[-2];
	if($fib[-1] > 4000000){ last; }
	if(not($fib[-1] & 1)){ $sum += $fib[-1]; }
}
print("$sum\n");
