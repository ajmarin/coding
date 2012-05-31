R=lambda:map(int,raw_input().split())
n,k=R()
m=R()[0]
c=R()
z=sorted(c[:-1])
s=sum(z[-k:])
print n if s <= m else 1+min(i for i,j in enumerate(c) if s-z[-k]+j>m)
