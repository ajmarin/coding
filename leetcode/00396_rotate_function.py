class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        total = sum(nums)
        curr = sum(i * v for i, v in enumerate(nums))
        best = curr
        for v in nums[-1:0:-1]:
            curr += total - n * v
            best = best if best > curr else curr
        return best
