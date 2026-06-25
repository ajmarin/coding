class Solution:
    def minIncrease(self, nums: List[int]) -> int:
        dp = [(0, 0)] * 2
        curr, succ = nums[:2]
        for i in range(1, len(nums) - 1):
            prev, curr, succ = curr, succ, nums[i + 1]
            target = 1 + (prev if prev >= succ else succ)
            special, ops = dp[-2]
            ops -= target - curr if curr < target else 0
            dp.append(max(dp[-1], (special + 1, ops)))
        return -dp[-1][-1]
