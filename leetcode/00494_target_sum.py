class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)

        @cache
        def bt(remaining, i=0):
            if i == n:
                return not remaining
            return bt(remaining + nums[i], i + 1) + bt(remaining - nums[i], i + 1)

        return bt(target)
