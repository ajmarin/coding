class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        prev = defaultdict(float)
        prev[row, column] = 1.0
        for _ in range(k):
            curr = defaultdict(float)
            for (x, y), prob in prev.items():
                prob /= 8
                for dx in (2, -2, 1, -1):
                    nx = x + dx
                    if nx < 0 or nx >= n:
                        continue
                    for dy in (3 - abs(dx), abs(dx) - 3):
                        if 0 <= y + dy < n:
                            curr[nx, y + dy] += prob
            prev = curr
        return sum(prev.values())
