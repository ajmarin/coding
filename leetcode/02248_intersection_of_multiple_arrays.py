class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        res = set(nums[0])
        for arr in nums[1:]:
            res &= set(arr)
        return sorted(res)
