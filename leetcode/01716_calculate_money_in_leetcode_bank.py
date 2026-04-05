class Solution:
    def totalMoney(self, n: int) -> int:
        full_weeks = n // 7
        remaining = n % 7
        return (56 + 7 * (full_weeks - 1)) * full_weeks // 2 + (
            1 + 2 * full_weeks + remaining
        ) * remaining // 2
