class Solution:
    def fillCups(self, amount: List[int]) -> int:
        return max(*amount, (sum(amount) + 1) // 2)
