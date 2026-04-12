class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n = len(piles)
        low, high = 1, max(piles)
        piles = [p - 1 for p in piles]
        while low < high:
            mid = (low + high) >> 1
            time_taken = n + sum(pile // mid for pile in piles)
            if time_taken > h:
                low = mid + 1
            else:
                high = mid
        return low
