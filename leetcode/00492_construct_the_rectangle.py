class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        return next(
            [area // n, n] for n in range(floor(sqrt(area)), 0, -1) if area % n == 0
        )
