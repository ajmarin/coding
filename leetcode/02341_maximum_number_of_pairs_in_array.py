class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        leftover = len([v for v in Counter(nums).values() if v & 1])
        return [(len(nums) - leftover) >> 1, leftover]
