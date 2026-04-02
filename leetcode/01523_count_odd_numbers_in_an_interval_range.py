class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high & 1 or low & 1) + ((high - low) >> 1)
