class Solution:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        ways_12, ways_34 = Counter(), Counter()
        for a in nums1:
            for b in nums2:
                ways_12[a + b] += 1
        for a in nums3:
            for b in nums4:
                ways_34[a + b] += 1
        return sum(w12 * ways_34[-k] for k, w12 in ways_12.items())
