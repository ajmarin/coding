def pandigital(x):
	seen, s = [0 for i in range(10)], 0
	while(x):
		k = x % 10
		seen[k] = 1
		s += k
		x //= 10
	return s == 45 and sum(seen[1:]) == 9

p9, p15 = 10 ** 9, 10 ** 15
lim = 1000000
f, l, pf, pl = 1, 1, 0, 0
for i in range(2, lim):
	f, l, pf, pl = (f + pf), (l + pl) % p9, f, l
	while(f > p15): 
		f //= 10
		pf //= 10	
	x = f
	while x > p9: x //= 10
	if(pandigital(x) and pandigital(l)):
		print("Answer: {}\nF[{}] = {}...{}".format(i, i, x, l))
		break
