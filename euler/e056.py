maxs = 0
for i in range(1, 100):
	for j in range(1, 100):
		maxs = max(maxs, sum(int(x) for x in str(i ** j)))
print(maxs)
