class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = rolling_sum = 0
        prev = -1
        for n in nums:
            if n > prev:
                rolling_sum += n
            else:
                ans = rolling_sum if rolling_sum > ans else ans
                rolling_sum = n
            prev = n
        return max(ans, rolling_sum)
