class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        ans = inf
        for i in range(len(nums) // 2):
            ans = min(ans, nums[i] + nums[~i])
        return ans / 2
