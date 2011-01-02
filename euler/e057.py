from math import *
ans, d, n = 0, 1, 1
for i in range(999):
	d, n = n + d, n + (d << 1)
	ans += floor(log10(n)) > floor(log10(d))
print(ans)
	
