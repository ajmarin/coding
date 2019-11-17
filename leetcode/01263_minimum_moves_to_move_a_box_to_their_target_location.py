class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        valid_coord = lambda i, j: 0 <= i < rows and 0 <= j < cols
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '#':
                    continue
                if grid[i][j] == 'S':
                    start = i, j
                elif grid[i][j] == 'B':
                    box = i, j
                elif grid[i][j] == 'T':
                    target = i, j
                grid[i][j] = '.'
        q = collections.deque([(start, box)])
        pushes = {(start, box): 0}
        def adjacent(i: int, j: int):
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = i + di, j + dj
                if not valid_coord(ni, nj) or grid[ni][nj] == '#':
                    continue
                yield ni, nj
        while q:
            pos, box = q.popleft()
            p = pushes[pos, box]
            for next_pos in adjacent(*pos):
                ni, nj = next_pos
                if next_pos != box:
                    if (next_pos, box) not in pushes:
                        pushes[next_pos, box] = p
                        q.appendleft((next_pos, box))
                else:
                    i, j = pos
                    boxi, boxj = 2 * ni - i, 2 * nj - j
                    next_box = boxi, boxj
                    if not valid_coord(*next_box) or grid[boxi][boxj] == '#':
                        continue
                    elif (next_pos, next_box) not in pushes:
                        if next_box == target:
                            return p + 1
                        pushes[next_pos, next_box] = p + 1
                        q.append((next_pos, next_box))
        return -1