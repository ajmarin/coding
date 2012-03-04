x=[0 for i in range(2**17)]
n=input()
t=map(int,raw_input().split())
for i in range(n):
	d=t[i]-min(i,n-i-1)
	if d>0:x[d]+=1;
print n-max(x)
