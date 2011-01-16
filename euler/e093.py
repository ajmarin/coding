from itertools import *
import time
seen = [0 for i in range(360)]
def insert(x):
	if -1 < x < 360: seen[x] = 1

def rpn(x):
	s = []
	for c in x:
		if c.isdigit():	s.append(int(c))
		elif len(s) < 2: return 0
		else:
			op2, op1 = s.pop(), s.pop()
			if c == '+': s.append(op1 + op2)
			elif c == '-': s.append(op1 - op2)
			elif c == '*': s.append(op1 * op2)
			elif c == '/' and op2: s.append(op1 / float(op2))
			else: return 0
	return int(s[0]) if int(s[0]) == s[0] and len(s) == 1 else 0
def doAll(nums):
	for i in range(360): seen[i] = 0
	for op in product('+-*/', repeat=3):
		for x in permutations(nums):
			s = x[0] + x[1]
			insert(rpn(s + op[0] + x[2] + op[1] + x[3] + op[2]))
			insert(rpn(s + op[0] + x[2] + x[3] + op[2] + op[1]))
			s += x[2]
			insert(rpn(s + op[1] + op[0] + x[3] + op[2]))
			insert(rpn(s + op[1] + x[3] + op[2] + op[0]))
			insert(rpn(s + x[3] + op[0] + op[1] + op[2]))
			
	r = 1
	while r < 360 and seen[r]: r = r + 1
	return r - 1

ans, n = -1, 0
begin = time.time()
for i in range(1, 7):
	for j in range(i + 1, 8):
		for k in range(j + 1, 9):
			for l in range(k + 1, 10):
				numbers = ''.join(str(z) for z in [i, j, k, l])
				v = doAll(numbers)
				if v > n:
					n = v
					ans = numbers
print('Best: ({}, #{})'.format(ans, n))
print('Elapsed time: {0}ms'.format(int(1000 * (time.time() - begin))))