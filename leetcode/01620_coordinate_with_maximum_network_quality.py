class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        maxx, maxy = max(t[0] for t in towers), max(t[1] for t in towers)
        radius_sq = radius**2

        best_score = -1
        winner = [-1, -1]
        for x, y in product(range(maxx + 1), range(maxy + 1)):
            score = 0
            for tx, ty, q in towers:
                dist_sq = (tx - x) ** 2 + (ty - y) ** 2
                if dist_sq > radius_sq:
                    continue
                score += floor(q / (1 + sqrt(dist_sq)))
            if score > best_score:
                winner = [x, y]
                best_score = score
        return winner
