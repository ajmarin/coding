import sys
for s in sys.stdin:
	x = int(s) - 1
	print(x << 1 if x else 1)
