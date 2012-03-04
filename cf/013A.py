import fractions
n, s = input(), 0
for i in range(2, n):
	x = n
	while x: s += x % i; x /= i
g = fractions.gcd(s, n-2)
print str(s/g)+'/'+str((n-2)/g)
