class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        MOD = 10**9 + 7
        dp = [1] * (len(pressedKeys) + 1)
        for i, c in enumerate(pressedKeys):
            res = dp[i]
            for j in range(1, 1 + min(2 + (c in {"7", "9"}), i)):
                if pressedKeys[i - j] != c:
                    break
                res += dp[i - j]
            dp[i + 1] = res % MOD
        return res % MOD
