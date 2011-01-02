from math import *
def sqr(x):
	return x * x
			
def calc_sqrt(x, prec = 10):
	g = int(floor(sqrt(x)))
	ans = str(g) + '.'
	n = 100 * (x - g * g)
	for i in range(prec - 1):
		k = 9
		for j in range(1, 10):
			if j * (g * 20 + j) > n:
				k = j - 1
				break
		n = 100 * (n - k * (g * 20 + k))
		g = 10 * g + k
		ans = ans + str(k)
	return ans

def digit_sum(x):
	r = 0
	for z in x: 
		if z > '0' and z <= '9': r += int(z)
	return r

ans = 0
for x in range(2, 100):
	if sqr(floor(sqrt(x + .5))) == x: continue
	sqrt_str = calc_sqrt(x, 100)
	ans += digit_sum(sqrt_str)
print(ans)

