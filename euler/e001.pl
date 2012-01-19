#!/usr/bin/perl

$sum = 0;

for($i = 3; $i < 1000; $i++){
	if(not($i % 3) or not($i % 5)){
		$sum += $i;
	}
}

print "$sum\n"
