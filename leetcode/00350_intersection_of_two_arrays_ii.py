class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c1, c2 = Counter(nums1), Counter(nums2)
        ans = []
        for n in c1:
            ans += [n] * min(c1[n], c2[n])
        return ans
