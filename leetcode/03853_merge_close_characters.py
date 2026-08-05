class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        allow = [-1] * 128
        ans = ""
        for c in s:
            if len(ans) > allow[ord(c)]:
                allow[ord(c)] = len(ans) + k
                ans += c
        return ans
