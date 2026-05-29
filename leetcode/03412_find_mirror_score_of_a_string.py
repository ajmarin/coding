class Solution:
    def calculateScore(self, s: str) -> int:
        ORDA, ORDZ = ord("a"), ord("z")
        pos = [[] for _ in range(26)]
        score = 0
        for i, c in enumerate(s):
            ordc = ORDZ - ord(c)
            if pos[ordc]:
                score += i - pos[ordc].pop()
            else:
                pos[ord(c) - ORDA].append(i)
        return score
