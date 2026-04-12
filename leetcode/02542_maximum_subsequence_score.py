class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pairs = sorted(zip(nums2, nums1), reverse=True)
        h = [p[1] for p in pairs[:k]]
        heapify(h)
        heapsum = sum(h)
        ans = pairs[k - 1][0] * heapsum
        for n2, n1 in pairs[k:]:
            if n1 > h[0]:
                heapsum += n1 - h[0]
                heapreplace(h, n1)
                ans = max(ans, heapsum * n2)
        return ans
