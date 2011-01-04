from math import *
cnt = 0
for b in range(1, 10):
	cnt += int(1 / (1 - log10(b)))
print('Answer is', cnt)
