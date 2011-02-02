n, h = input(), map(int, raw_input().split())
idx, mind = -1, 1024
for i in range(n):
	t = abs(h[i] - h[i - 1])
	if t < mind: mind = t; idx = i
print idx+1, 1 + (idx + n - 1) % n
