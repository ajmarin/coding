class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        s = "#" * (n - 1) + "."
        return ["." * n, *(s for _ in range(m - 1))]
