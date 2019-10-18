class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = float('-inf')
        current = 0
        for n in nums:
            current += n
            if current > best:
                best = current
            if current < 0:
                current = 0
        return best