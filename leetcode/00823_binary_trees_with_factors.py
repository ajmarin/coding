class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD = 10**9 + 7

        arr.sort()
        dp = {n: 1 for n in arr}

        for i in range(len(arr)):
            root = arr[i]
            for child in arr[:i]:
                if root % child != 0 or (other := root // child) not in dp:
                    continue
                dp[root] = (dp[root] + dp[child] * dp[other]) % MOD
        return sum(dp.values()) % MOD
