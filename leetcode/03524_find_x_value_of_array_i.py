class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        dp = [[0] * k for _ in range(n)]
        dp[0][nums[0] % k] = 1
        prev = dp[0]
        for i in range(1, n):
            x, curr = nums[i], dp[i]
            curr[x % k] += 1
            for j in range(k):
                curr[j * x % k] += prev[j]
            prev = curr
        return list(map(sum, zip(*dp)))
