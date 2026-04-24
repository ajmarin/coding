class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        if k:
            return sum(c[n + k] > 0 for n in c)
        return sum(c[n] > 1 for n in c)
