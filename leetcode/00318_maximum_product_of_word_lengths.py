class Solution:
    def maxProduct(self, words: List[str]) -> int:
        N = len(words)
        chars = list(map(set, words))
        lens = list(map(len, words))
        m = 0
        for i in range(N):
            for j in range(i + 1, N):
                prod = lens[i] * lens[j]
                if prod > m and not len(chars[i] & chars[j]):
                    m = prod
        return m