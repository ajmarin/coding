import bisect

class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        summod = sum(abs(n1 - n2) for n1, n2 in zip(nums1, nums2))
        s1 = sorted(nums1)

        ans = summod
        for n1, n2 in zip(nums1, nums2):
            bidx = bisect.bisect(s1, n2)
            mod = abs(n1 - n2)
            cand1, cand2 = summod, summod
            if bidx < len(s1):
                cand1 = summod - mod + abs(s1[bidx] - n2)
            if bidx:
                cand2 = summod - mod + abs(s1[bidx - 1] - n2)
            ans = min(ans, cand1, cand2)
        return ans % (10**9 + 7)

