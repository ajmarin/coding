class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        rows, cols = len(classroom), len(classroom[0])
        index = sx = sy = 0
        litter_index = {}
        for x, row in enumerate(classroom):
            for y, val in enumerate(row):
                if val == "S":
                    sx, sy = x, y
                elif val == "L":
                    litter_index[x, y] = index
                    index += 1
        visited = {(sx, sy, 0): energy}
        q = deque([(sx, sy, 0, energy, 0)])
        goal = (1 << index) - 1
        if index == 0:
            return 0
        while q:
            x, y, mask, e, moves = q.popleft()
            if not e or e < visited[x, y, mask]:
                continue
            for dx, dy in pairwise((1, 0, -1, 0, 1)):
                nx, ny = x + dx, y + dy
                if nx < 0 or nx >= rows:
                    continue
                if ny < 0 or ny >= cols:
                    continue
                cell = classroom[nx][ny]
                if cell == "X":
                    continue
                next_energy, next_mask = e - 1, mask
                if cell == "R":
                    next_energy = energy
                elif cell == "L":
                    next_mask |= 1 << (litter_index[nx, ny])
                    if next_mask == goal:
                        return moves + 1
                if next_energy > visited.get((nx, ny, next_mask), -1):
                    visited[nx, ny, next_mask] = next_energy
                    q.append((nx, ny, next_mask, next_energy, moves + 1))
        return -1
