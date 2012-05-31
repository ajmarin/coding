($n,$k)=split(/ /,<>);
$m=int <>;
@c=map{int $_} split(/ /,<>);
@z=sort {$a<=>$b}@c[0..$n-2];
$s += $z[$n-$_-1] for(1 .. $k);
$x=0;
print "$n\n" if $s <= $m;
for(0 .. $n-1){
	$x = $_ + 1 if $s - $z[$n-$k-1] + $c[$_] > $m;
	last if $x;
}
print "$x\n" if $s > $m;
