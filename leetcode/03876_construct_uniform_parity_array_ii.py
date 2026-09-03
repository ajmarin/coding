class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        return min(nums1) & 1 == 1 or all(not (n & 1) for n in nums1)
