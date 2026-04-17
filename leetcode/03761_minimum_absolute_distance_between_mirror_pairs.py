class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        ans, last = 100_000, {}
        for i, n in enumerate(nums):
            if n in last:
                ans = ans if ans < i - last[n] else i - last[n]
            last[int(str(n)[::-1])] = i
        return -(ans == 100_000) | ans
