class Solution:
    def isMiddleElementUnique(self, nums: list[int]) -> bool:
        mid = len(nums) >> 1
        mid_el = nums[mid]
        return all(n != mid_el for n in nums[:mid] + nums[mid + 1 :])
