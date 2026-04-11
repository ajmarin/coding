class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        if all(n == 1 for n in nums):
            return len(nums) - 1
        ones = []
        prev = start = 0
        for i, n in enumerate(nums):
            if n == 1 and prev == 0:
                start = i
            elif n == 0 and prev == 1:
                ones.append((start, i))
            prev = n
        if (len(ones) == 0 and start) or (ones and start > ones[-1][-1]):
            ones.append((start, len(nums)))
        ans = max((b - a for a, b in ones), default=0)
        for (a, b), (c, d) in pairwise(ones):
            if c == b + 1:
                ans = d - a - 1 if d - a - 1 > ans else ans
        return ans
