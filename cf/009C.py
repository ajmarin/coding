n, x, z = raw_input(), 0, '0'
for c in n: 
	x = (x << 1) + (c > '0' or z > '1')
	z = max(z, c)
print x
