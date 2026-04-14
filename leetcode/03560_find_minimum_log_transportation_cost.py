class Solution:
    def minCuttingCost(self, n: int, m: int, k: int) -> int:
        if m <= k and n <= k:
            return 0
        return k * ((m if m > k else n) - k)
