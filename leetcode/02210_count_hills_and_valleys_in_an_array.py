class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans = 0
        a = nums[0]
        for i in range(1, len(nums) - 1):
            b, c = nums[i], nums[i + 1]
            if (a < b > c) or (a > b < c):
                ans += 1
                a = b
        return ans

