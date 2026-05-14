class Solution:
    def bestTower(
        self, towers: List[List[int]], center: List[int], radius: int
    ) -> List[int]:
        cx, cy = center
        best = -1
        ans = [-1, -1]
        for tx, ty, q in towers:
            dist = abs(tx - cx) + abs(ty - cy)
            if dist > radius:
                continue
            if q > best:
                best = q
                ans = [tx, ty]
            elif q == best:
                ans = min(ans, [tx, ty])
        return ans
