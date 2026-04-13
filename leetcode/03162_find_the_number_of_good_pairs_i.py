class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(n1 % (n2 * k) == 0 for n1 in nums1 for n2 in nums2)
