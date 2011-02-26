import sys
while True:
	b, e = map(int,input().split());
	if not(b or e): break
	print(b**e)

