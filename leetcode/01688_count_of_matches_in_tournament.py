class Solution:
    def numberOfMatches(self, n: int) -> int:
        matches = 0
        while n > 1:
            matches += n >> 1
            n = (n + 1) >> 1
        return matches
