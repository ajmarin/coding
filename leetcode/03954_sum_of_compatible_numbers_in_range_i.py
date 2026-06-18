class Solution:
    def sumOfGoodIntegers(self, n: int, k: int) -> int:
        return sum(i for i in range(max(n - k, 0), n + k + 1) if not n & i)
