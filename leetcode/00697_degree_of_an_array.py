class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        c = Counter(nums)
        deg = max(c.values())
        if deg == 1:
            return 1
        first, last = {}, {}
        for i, n in enumerate(nums):
            if n not in first:
                first[n] = i
            else:
                last[n] = i
        return 1 + min(last[n] - first[n] for n, cnt in c.items() if cnt == deg)
