class Solution:
    def maxScore(self, s: str) -> int:
        best = 0
        zeros, ones = 0, sum(c == "1" for c in s)
        for c in s[:-1]:
            if c == "0":
                zeros += 1
            else:
                ones -= 1
            score = zeros + ones
            best = score if score > best else best
        return best
