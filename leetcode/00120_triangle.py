class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        prev = [0]
        for curr in triangle:
            curr[0] += prev[0]
            for i, (a, b) in enumerate(zip(prev, prev[1:])):
                curr[i + 1] += a if a < b else b
            curr[-1] += prev[-1]
            prev = curr
        return min(curr)
