class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        values = []
        remainder = grid[0][0] % x
        for row in grid:
            for n in row:
                if n % x != remainder:
                    return -1
                values.append(n)
        values.sort()
        goal = values[len(values) >> 1]
        return sum(abs(goal - n) // x for n in values)
