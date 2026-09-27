class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        mapping = [*range(n)]
        stack = []
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                x = stack.pop()
                mapping[x] = i
                mapping[i] = x

        i, step = 0, 1
        while i < n:
            if i != mapping[i]:
                i = mapping[i]
                step = -step
            else:
                stack.append(s[i])
            i += step
        return "".join(stack)
