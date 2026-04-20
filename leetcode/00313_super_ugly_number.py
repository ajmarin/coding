class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        index = [0] * len(primes)
        candidates = primes[:]
        ugly = [1]
        last = 1
        while n := n - 1:
            ugly.append(min(candidates))
            last = ugly[-1]
            for i, c in enumerate(candidates):
                if c == last:
                    index[i] += 1
                    candidates[i] = primes[i] * ugly[index[i]]
        return last
