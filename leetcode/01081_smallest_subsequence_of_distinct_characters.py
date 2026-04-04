class Solution:
    def smallestSubsequence(self, s: str) -> str:
        ans = []
        last = {c: i for i, c in enumerate(s)}
        for i, c in enumerate(s):
            if c in ans:
                continue
            while ans and ans[-1] > c and last[ans[-1]] > i:
                ans.pop()
            ans.append(c)
        return "".join(ans)
