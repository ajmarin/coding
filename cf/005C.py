b, big, cnt, s, z = -1, 0, 1, [], raw_input()
for i in range(len(z)):
	if z[i] == '(': s.append(i)
	elif s:
		s.pop()
		L = i - s[-1] if len(s) else i - b
		if L > big: big = L; cnt = 1;
		else: cnt += L == big
	else: b = i
print big, cnt

