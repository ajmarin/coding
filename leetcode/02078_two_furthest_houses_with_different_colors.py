class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        return max(
            j - i for i in range(n) for j in range(i + 1, n) if colors[i] != colors[j]
        )
