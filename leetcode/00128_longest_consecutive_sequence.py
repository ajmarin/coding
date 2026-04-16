class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        starters = nums.copy()
        for n in nums:
            if n - 1 in nums:
                starters.remove(n)
        longest = 0
        for s in starters:
            e = s
            while (e := e + 1) in nums:
                pass
            longest = e - s if e - s > longest else longest
        return longest
