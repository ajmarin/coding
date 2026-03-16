DIRECTIONS = ((1, 1), (1, -1), (-1, -1), (-1, 1))


class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        def compute_sum(row, col, steps):
            total = 0
            for dr, dc in DIRECTIONS:
                for _ in range(steps):
                    row, col = row + dr, col + dc
                    total += grid[row][col]
            return total

        rows, cols = len(grid), len(grid[0])
        sums = set([x for row in grid for x in row])

        for steps in range(1, min(rows, cols)):
            for r in range(0, rows - 2 * steps):
                for c in range(steps, cols - steps):
                    sums.add(compute_sum(r, c, steps))

        return sorted(sums, reverse=True)[:3]
