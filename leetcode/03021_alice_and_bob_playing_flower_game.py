class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        odd_n = (n + 1) >> 1
        odd_m = (m + 1) >> 1
        return odd_n * (m - odd_m) + odd_m * (n - odd_n)

