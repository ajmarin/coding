class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1counts = Counter(nums1)
        self.nums2 = nums2
        self.counts = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        curr = self.nums2[index]
        added = curr + val
        self.counts[curr] -= 1
        self.nums2[index] = added
        self.counts[added] += 1

    def count(self, tot: int) -> int:
        return sum(
            x * self.counts[tot - n]
            for n, x in self.nums1counts.items()
        )

