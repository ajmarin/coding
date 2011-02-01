import sys
a, c = 0, 0
for s in sys.stdin:
	if s[0] == '+' or s[0] == '-': c += ((s[0] == '+') << 1) - 1
	else: a += c * (len(s) - s.index(':') - 2)
print a
