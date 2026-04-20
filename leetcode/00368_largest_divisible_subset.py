class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        dp = [1] * n
        prev = [-1] * n
        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if 1 + dp[j] > dp[i]:
                        dp[i] = 1 + dp[j]
                        prev[i] = j
        index = max(range(n), key=dp.__getitem__)
        ans = []
        while index != -1:
            ans.append(nums[index])
            index = prev[index]
        return ans
