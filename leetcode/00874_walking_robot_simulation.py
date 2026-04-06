MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        direction = max_dist = x = y = 0
        obstacles = set(map(tuple, obstacles))
        for c in commands:
            if c == -2:
                direction = (direction + 3) % 4
            elif c == -1:
                direction = (direction + 1) % 4
            else:
                dx, dy = MOVES[direction]
                for i in range(c):
                    nx, ny = x + dx, y + dy
                    if (nx, ny) in obstacles:
                        break
                    x, y = nx, ny
                    dist = x * x + y * y
                    if dist > max_dist:
                        max_dist = dist
        return max_dist
