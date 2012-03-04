input()
x = map(lambda x: int(x)&1, raw_input().split())
print x.index(x.count(0) > 1) + 1

