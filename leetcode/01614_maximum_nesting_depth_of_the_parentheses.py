class Solution:
    def maxDepth(self, s: str) -> int:
        ans = curr = 0
        for c in s:
            if c == "(":
                curr += 1
                ans = ans if ans > curr else curr
            elif c == ")":
                curr -= 1
        return ans
