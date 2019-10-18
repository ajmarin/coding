class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        insertion = m + n - 1
        p1 = m - 1
        p2 = n - 1
        while p2 > - 1:
            if p1 > - 1 and nums1[p1] >= nums2[p2]:
                nums1[insertion] = nums1[p1]
                p1 -= 1
            else:
                nums1[insertion] = nums2[p2]
                p2 -= 1
            insertion -= 1