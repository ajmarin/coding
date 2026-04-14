class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        pref = list(accumulate(nums, initial=0))
        return sum(pref[i + 1] - pref[max(0, i - nums[i])] for i in range(len(nums)))
