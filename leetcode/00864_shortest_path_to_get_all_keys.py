class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        rows, cols = len(grid), len(grid[0])
        final_state = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '@':
                    sx, sy = i, j
                elif 'a' <= grid[i][j] <= 'f':
                    final_state |= 1 << (ord(grid[i][j]) - ord('a'))
        moves = ((1,0), (0,1), (-1, 0), (0, -1))
        q = collections.deque([(sx, sy, 0, 0)])
        visited = set([(sx, sy, 0)])
        while q:
            x, y, keys, steps = q.popleft()
            for dx, dy in moves:
                nx, ny = x + dx, y + dy
                if nx < 0 or nx >= rows or ny < 0 or ny >= cols or grid[nx][ny] == '#':
                    continue
                if 'A' <= grid[nx][ny] <= 'F':
                    need = ord(grid[nx][ny]) - ord('A')
                    if not keys & (1 << need):
                        continue
                k = keys
                if 'a' <= grid[nx][ny] <= 'f':
                    k |= 1 << (ord(grid[nx][ny]) - ord('a'))
                    if k == final_state:
                        return steps + 1
                new_state = (nx, ny, k, steps + 1)
                if new_state[:3] not in visited:
                    visited.add(new_state[:3])
                    q.append(new_state)
        return -1