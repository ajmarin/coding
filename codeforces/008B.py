s = raw_input().strip()
depth, OK, x, y = 1, 1, 150, 150
v = [[0] * 300 for i in range(300)]
d = [[-1, 0],[1, 0],[0, 1],[0, -1]]

def check(x, y):
	z = depth
	for i in range(4):
		t = v[x+d[i][0]][y+d[i][1]]
		if t and t != z - 1: return False
	return True

for c in s:
	OK &= v[x][y] == 0
	v[x][y] = depth
	depth += 1
	x, y = x + (c == 'R') - (c == 'L'), y + (c == 'U') - (c == 'D')
	OK &= check(x, y)
	if not OK: break

print ["BUG", "OK"][OK]
