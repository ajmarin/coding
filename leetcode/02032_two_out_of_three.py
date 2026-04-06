class Solution:
    def twoOutOfThree(
        self, nums1: List[int], nums2: List[int], nums3: List[int]
    ) -> List[int]:
        presence = defaultdict(set)
        for index, arr in zip(range(3), (nums1, nums2, nums3)):
            for n in arr:
                presence[n].add(index)
        return [n for n, present_in in presence.items() if len(present_in) > 1]
