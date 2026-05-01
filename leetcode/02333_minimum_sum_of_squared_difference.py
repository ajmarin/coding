class Solution:
    def minSumSquareDiff(
        self, nums1: List[int], nums2: List[int], k1: int, k2: int
    ) -> int:
        diffs = [abs(n1 - n2) for n1, n2 in zip(nums1, nums2)]
        moves = k1 + k2
        if moves >= sum(diffs):
            return 0
        heapify_max(diffs)
        count, diff, gap = 1, heappop_max(diffs), 0
        while moves and diffs:
            gap = diff - diffs[0]
            if moves < (gap := diff - diffs[0]) * count:
                break
            diff = heappop_max(diffs)
            moves -= gap * count
            count += 1
        diff -= moves // count
        rem = moves % count
        x = min(count, rem)
        base = (diff - 1) ** 2 * x + diff**2 * (count - x)
        return base + sum(d * d for d in diffs)
