class Solution:
    def minAbsoluteDifference(self, nums: list[int]) -> int:
        ans = inf
        last_one = last_two = -inf
        for i, n in enumerate(nums):
            if n == 1:
                last_one = i
                ans = i - last_two if i - last_two < ans else ans
            elif n == 2:
                last_two = i
                ans = i - last_one if i - last_one < ans else ans
        return ans if ans != inf else -1
