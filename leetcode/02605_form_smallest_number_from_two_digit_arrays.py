class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        min1, min2 = min(nums1), min(nums2)
        return min(
            set(nums1) & set(nums2),
            default=10 * min1 + min2 if min1 < min2 else 10 * min2 + min1,
        )
