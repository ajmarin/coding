class Solution:
    def minimumPushes(self, word: str) -> int:
        n, total = len(word), 0
        cost = 1
        while n:
            count = min(n, 8)
            total += cost * count
            n -= count
            cost += 1
        return total
