class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        a = b = c = total = 0
        for x in reversed(stoneValue):
            total += x
            a, b, c = total - min(a, b, c), a, b

        if 2 * a > total:
            return "Alice"
        return "Tie" if 2 * a == total else "Bob"
