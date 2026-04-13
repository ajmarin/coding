class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return sorted(nums2)[0] - sorted(nums1)[0]
