class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        add = nums[-1]
        ans = 0
        for i in range(1, len(nums)):
            n = nums[~i]
            ans += i * n > add
            add += n
        return ans
