class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        ans = j = 0
        for i in range(n1):
            t = nums1[i]
            j = max(i, j)
            while j < n2 and t <= nums2[j]:
                j += 1
            ans = ans if ans > j - i else j - i
        return ans - (ans > 0)
