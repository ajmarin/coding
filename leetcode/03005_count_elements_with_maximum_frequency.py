class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        c = Counter(nums)
        max_freq = max(c.values())
        return sum(v for v in c.values() if v == max_freq)
