class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()

        full = sum(nums)
        ans, total = [], 0
        while 2 * total <= full:
            ans.append(nums.pop())
            total += ans[-1]
        return ans
