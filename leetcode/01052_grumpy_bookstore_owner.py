class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        happy, max_bonus = 0, 0
        bonus, left = 0, 0
        for right, count in enumerate(customers):
            bonus += grumpy[right] * count
            happy += (not grumpy[right]) * count
            if right >= X:
                bonus -= grumpy[left] * customers[left]
                left += 1
            max_bonus = max(max_bonus, bonus)
        return happy + max_bonus