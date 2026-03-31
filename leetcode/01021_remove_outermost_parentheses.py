class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        balance = left = 0
        ans = ""
        for right, c in enumerate(s):
            if c == "(":
                balance += 1
            else:
                balance -= 1
                if balance == 0:
                    ans += s[left + 1 : right]
                    left = right + 1
        return ans
