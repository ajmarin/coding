class Solution:
    def maxArea(
        self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]
    ) -> int:
        horizontalCuts += [0, h]
        horizontalCuts.sort()
        verticalCuts += [0, w]
        verticalCuts.sort()
        max_span = lambda arr: max(b - a for a, b in pairwise(arr))
        return max_span(horizontalCuts) * max_span(verticalCuts) % (10**9 + 7)
