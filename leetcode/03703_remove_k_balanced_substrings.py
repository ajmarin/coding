class Solution:
    def removeSubstring(self, s: str, k: int) -> str:
        ans = ""
        stack = []
        for c in s:
            if not stack or stack[-1][0] != c:
                stack.append([c, 1])
            else:
                stack[-1][1] += 1
            if c == ")" and len(stack) > 1 and stack[-1][1] == k and stack[-2][1] >= k:
                stack.pop()
                stack[-1][1] -= k
                if not stack[-1][1]:
                    stack.pop()
        return "".join(c * n for c, n in stack)
