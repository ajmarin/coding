primes = [2, 3, 5]
candidates = primes[:]
inc = [0] * 3
ans = [1]
last = 1

for i in range(1690):
    ans.append(min(candidates))
    last = ans[-1]
    for i in range(3):
        if candidates[i] == last:
            inc[i] += 1
            candidates[i] = primes[i] * ans[inc[i]]


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        return ans[n - 1]
