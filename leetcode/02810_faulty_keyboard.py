class Solution:
    def finalString(self, s: str) -> str:
        ans = deque()
        fn = ans.append
        for c in s:
            if c == "i":
                fn = ans.appendleft if fn == ans.append else ans.append
            else:
                fn(c)
        return "".join(ans if fn == ans.append else reversed(ans))
