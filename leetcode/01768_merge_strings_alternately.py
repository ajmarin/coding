class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = []
        for c1, c2 in zip(word1, word2):
            ans.append(c1)
            ans.append(c2)
        return "".join(ans) + word1[len(word2) :] + word2[len(word1) :]
