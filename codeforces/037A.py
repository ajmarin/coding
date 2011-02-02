n, x = input(), map(int,raw_input().split())
c, s = [0] * 1024, 0
for k in x: s += not c[k]; c[k] += 1
print max(c),s
