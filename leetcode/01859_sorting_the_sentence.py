class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split(" ")
        ans = [None] * len(words)
        for w in words:
            ans[int(w[-1]) - 1] = w[:-1]
        return " ".join(ans)
