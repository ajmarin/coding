class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        return sum(
            words[j].startswith(words[i]) and words[j].endswith(words[i])
            for i in range(n)
            for j in range(i + 1, n)
        )
