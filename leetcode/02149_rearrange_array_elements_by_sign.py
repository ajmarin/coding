class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        pi, ni = 0, 1
        for n in nums:
            if n > 0:
                ans[pi] = n
                pi += 2
            else:
                ans[ni] = n
                ni += 2
        return ans

