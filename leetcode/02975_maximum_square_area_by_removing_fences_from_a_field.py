class Solution:
    def maximizeSquareArea(
        self, m: int, n: int, hFences: List[int], vFences: List[int]
    ) -> int:
        hFences.extend([1, m])
        vFences.extend([1, n])
        hFences.sort()
        vFences.sort()

        gaps = set(b - a for a, b in combinations(hFences, 2))
        size = max(
            (b - a for a, b in combinations(vFences, 2) if b - a in gaps), default=0
        )
        return -1 if not size else size * size % (10**9 + 7)
