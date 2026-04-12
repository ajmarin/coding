class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        rows, cols = len(maze), len(maze[0])
        q = deque([entrance])
        costs = {tuple(entrance): 0}
        while q:
            r, c = q.popleft()
            cost = costs[r, c] + 1
            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue
                if maze[nr][nc] == "+" or (nr, nc) in costs:
                    continue
                if nr == 0 or nr == rows - 1 or nc == 0 or nc == cols - 1:
                    return cost
                costs[nr, nc] = cost
                q.append((nr, nc))
        return -1
