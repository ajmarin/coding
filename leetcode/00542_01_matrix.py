class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        rows, cols = len(matrix), len(matrix[0])
        visited = [[False] * cols for _ in matrix]
        q = collections.deque()
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if v == 0:
                    visited[i][j] = True
                    q.append((i, j, 0))
        while q:
            i, j, d = q.popleft()
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows or nj < 0 or nj >= cols:
                    continue
                if not visited[ni][nj]:
                    visited[ni][nj] = True
                    matrix[ni][nj] = d + 1
                    q.append((ni, nj, d + 1))
        return matrix