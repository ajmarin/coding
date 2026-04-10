class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        return sum(
            n - a - b <= limit
            for a in range(1 + min(limit, n))
            for b in range(1 + min(limit, n - a))
        )
