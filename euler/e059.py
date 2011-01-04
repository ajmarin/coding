enc = eval('[' + open('cipher1.txt').read() + ']')
ans, maxs = 0, 0
ok = [[1, 1, 1] for i in range(128)]
def valid(x):
	return not(34 < x < 39 or x < 32 or x > 122 or x == '/' or x == '@' or 90 < x < 97)
def decrypt(x):
	if not(ok[x[0]][0] and ok[x[1]][1] and ok[x[2]][2]): return (0, 0)
	cnt, tot = 0, 0
	x = (500 * x)[:len(enc)]
	for i in range(len(x)):
		k = x[i] ^ enc[i]
		if not valid(k): 
			ok[x[i % 3]][i % 3] = 0
			return (tot, cnt)
		cnt += k == 32
		tot += k
	return (tot, cnt)
for i in range(97,123):
	for j in range(97,123):
		for k in range(97,123):
			test, sc = decrypt((i, j, k))
			if sc > maxs:
				maxs = sc
				ans = test
				key = chr(i) + chr(j) + chr(k)
print('Answer is {}, with \'{}\' as key'.format(ans, key))

