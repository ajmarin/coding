class Solution:
    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        direction = include = 1
        ans = []
        for row in grid:
            for val in row[::direction]:
                if include:
                    ans.append(val)
                include = not include
            direction = -direction
        return ans
