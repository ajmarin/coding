class Solution:
    def countOppositeParity(self, nums: list[int]) -> list[int]:
        ans = [0] * len(nums)
        counts = [0, 0]
        for i in range(len(nums) - 1, -1, -1):
            p = nums[i] & 1
            counts[p] += 1
            ans[i] = counts[1 - p]
        return ans
