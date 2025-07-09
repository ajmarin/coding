class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        L1, L2 = len(word1), len(word2)
        prev, curr = [[0] * (L2 + 1) for _ in range(2)]

        for a in word1:
            for j, (b, p, c) in enumerate(zip(word2, prev[1:], curr)):
                if a == b: curr[j + 1] = prev[j] + 1
                else: curr[j + 1] = p if p > c else c
            prev, curr = curr, prev
        return L1 + L2 - 2 * prev[L2]

