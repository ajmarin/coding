class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        maxcnt = max(Counter(nums).values())
        return n & 1 if maxcnt <= n // 2 else 2 * maxcnt - n
