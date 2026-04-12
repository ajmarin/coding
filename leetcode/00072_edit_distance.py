class Solution:
    @cache
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        if word1[0] == word2[0]:
            return self.minDistance(word1[1:], word2[1:])
        return 1 + min(
            self.minDistance(word1[1:], word2),  # delete from word1
            self.minDistance(word1, word2[1:]),  # delete from word2
            self.minDistance(word1[1:], word2[1:]),  # replace
        )
