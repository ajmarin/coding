class Solution:
    delta = {
        "N": (0, 1),
        "S": (0, -1),
        "E": (1, 0),
        "W": (-1, 0),
    }

    def maxDistance(self, s: str, k: int) -> int:
        x, y = 0, 0
        ans = 0

        for i, c in enumerate(s):
            d = self.delta[c]
            x, y = x + d[0], y + d[1]
            ans = max(ans, min(i + 1, abs(x) + abs(y) + 2 * k))
        return ans

