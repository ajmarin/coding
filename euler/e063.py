from math import *
cnt = 0
for b in range(1, 10):
	for p in range(1, 1 + int(1 / (1 - log10(b)))):
		cnt += len(str(b ** p)) == p
print('Answer is', cnt)
