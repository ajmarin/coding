class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        stack = []
        dp = [0] * n

        ans = 0
        for i in range(n):
            if s[i] == "(":
                stack.append(i)
            elif stack:
                left = stack.pop()
                dp[i] = i - left + 1 + (dp[left - 1] if left else 0)
                ans = ans if ans > dp[i] else dp[i]
        return ans
