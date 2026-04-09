class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        n = len(words)
        return sum(
            words[i] == words[j][::-1] for i in range(n) for j in range(i + 1, n)
        )
