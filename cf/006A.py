a = sorted(map(int, raw_input().split()))
m = max(a[0]+a[1]-a[2],a[1]+a[2]-a[3])
print ["IMPOSSIBLE", "SEGMENT", "TRIANGLE"][(m>=0)+(m>0)]
