class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])
        ways = [[0] * cols for i in range(rows)]
        ways[0][0] = 1 - obstacleGrid[0][0]
        for i in range(rows):
            for j in range(cols):
                if obstacleGrid[i][j]:
                    continue
                if i:
                    ways[i][j] += ways[i - 1][j]
                if j:
                    ways[i][j] += ways[i][j - 1]
        return ways[rows - 1][cols - 1]