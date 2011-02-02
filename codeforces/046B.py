size = ['S', 'M', 'L', 'XL', 'XXL']
have = map(int, raw_input().split())
n = input()
for i in range(n):
	s = raw_input()
	x = size.index(s)
	for i in range(5):
		if x + i < 5 and have[x + i]:
			print size[x + i]
			have[x + i] -= 1
			break
		if x - i > -1 and have[x - i]:
			print size[x - i]
			have[x - i] -= 1
			break
