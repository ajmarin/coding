a, b, c, d = 2, 5, 3, 7
while b + d < 1000000:
	a, b = a + c, b + d
print('Answer is {}, from fraction {}/{}'.format(a,a,b))
