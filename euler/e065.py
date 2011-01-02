d, dsum, n = 1, 0, 0
for i in range(1, 101):
	if not(i % 3): x = int(2 * i / 3)
	else: x = 1 + (i == 1)
	d, n = x * d + n, d
dsum = 0
sn = str(d)
for x in str(d):
	dsum += int(x)
print(dsum)
