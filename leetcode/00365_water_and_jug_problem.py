class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        visited = set()

        def dfs(amt_x: int, amt_y: int) -> bool:
            if (amt_x, amt_y) in visited:
                return False
            if amt_x + amt_y == target or amt_x == target or amt_y == target:
                return True
            visited.add((amt_x, amt_y))
            pour_x = min(amt_x, y - amt_y)
            pour_y = min(amt_y, x - amt_x)
            return (
                dfs(amt_x - pour_x, amt_y + pour_x)
                or dfs(amt_x + pour_y, amt_y - pour_y)
                or dfs(x, amt_y)
                or dfs(amt_x, y)
                or dfs(0, amt_y)
                or dfs(amt_x, 0)
            )

        return dfs(0, 0)
