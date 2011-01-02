from math import *
MAX = 1000000
primes = [2]
p = [1 for i in range(MAX)]
for i in range(4, MAX, 2): p[i] = 0
for i in range(3, 1001, 2):
	if(p[i]):
		primes.append(i)
		for j in range(i * i, MAX, i):
			p[j] = 0
for i in range(1001, MAX, 2):
	if(p[i]): primes.append(i)
def is_prime(x):
	lim = ceil(sqrt(x + .5))
	for k in primes:
		if k > lim: return 1
		if not(x % k): return 0
c, p, s, z = 5, 3, 3, 9
while p / (s << 1) > 0.1:
	for i in range(4):
		z += s + 1
		p += is_prime(z)
	s += 2
print(s)
