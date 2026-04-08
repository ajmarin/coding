class Solution:
    def similarPairs(self, words: List[str]) -> int:
        chars = [set(w) for w in words]
        n = len(chars)
        return sum(chars[i] == chars[j] for i in range(n) for j in range(i + 1, n))
