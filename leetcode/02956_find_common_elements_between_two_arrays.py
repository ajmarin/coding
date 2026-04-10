class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersection = set(nums1) & set(nums2)
        return [sum(n in intersection for n in arr) for arr in [nums1, nums2]]
