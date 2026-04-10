class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        c = Counter(nums)
        return c[n - 1] == 2 and all(c[i] == 1 for i in range(1, n - 1))
