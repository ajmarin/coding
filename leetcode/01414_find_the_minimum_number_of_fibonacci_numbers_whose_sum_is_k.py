N = 10**9
F = [1, 1]
while F[-1] <= N:
    F.append(F[-1] + F[-2])


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        ans = 0
        while k:
            ans += 1
            k -= F[bisect_right(F, k) - 1]
        return ans
