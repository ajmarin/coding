import itertools
ans, d, f, s = '', {}, {}, set()
for i in range(1, 10000):
	nums = ''.join(sorted(str(i ** 3)))
	l = len(s)
	s.add(nums)
	if len(s) == l:
		d[nums] += 1
	else: 
		d[nums] = 1
		f[nums] = i ** 3
	if d[nums] == 5:
		print('Answer is', f[nums])
		break

