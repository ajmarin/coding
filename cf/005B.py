import sys
s = [z.strip() for z in sys.stdin]
L = max(map(len,s))
print '*' * (L + 2)
l = 0;
for z in s:
	sp = L - len(z)
	spl = (sp + l) >> 1; spr = sp - spl
	print '*' + ' ' * spl + z + ' ' * spr + '*'
	if sp & 1: l = 1 - l
print '*' * (L + 2)
