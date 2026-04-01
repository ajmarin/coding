class Solution:
    def removeDuplicates(self, s: str) -> str:
        ans = []
        for c in s:
            if ans and c == ans[-1]:
                ans.pop()
            else:
                ans.append(c)
        return "".join(ans)
