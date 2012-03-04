n, m = map(int,raw_input().split())
x, s = sorted(map(int,raw_input().split())), 0
for i in range(m):
	s += -x[i] if x[i] < 0 else 0
print s
