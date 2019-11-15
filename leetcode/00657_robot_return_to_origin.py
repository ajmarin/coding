class Solution:
    def judgeCircle(self, moves: str) -> bool:
        c = collections.Counter(moves)
        return c['U'] == c['D'] and c['L'] == c['R']