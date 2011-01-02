a, z, dsum, y = 99, 1, 0, 1
while a > 0:
	if not(a % 3):
		x = int(a * 2 / 3)
	else:
		x = 1 + (a == 1)
	a = a - 1
	y, z = z, x * z + y

dsum = 0
sn = str(z)
for i in range(len(sn)):
	dsum += int(sn[i])
print(dsum)
