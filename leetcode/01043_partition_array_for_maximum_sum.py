class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0]
        for i in range(1, n + 1):
            curr_max = res = 0
            for j in range(1, 1 + min(i, k)):
                curr_max = curr_max if curr_max >= arr[i - j] else arr[i - j]
                cand = dp[i - j] + curr_max * j
                res = cand if cand > res else res
            dp.append(res)
        return dp[-1]
