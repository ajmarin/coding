class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dxdy = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        direction = 0
        x, y, dx, dy = 0, 0, 0, 1
        seen = set()
        seen.add((0, 0, 0, len(instructions)))
        for i in range(4):
            for index, c in enumerate(instructions):
                if c == 'G':
                    x += dx
                    y += dy
                elif c == 'R':
                    direction = (direction + 1) & 3
                    dx, dy = dxdy[direction]
                else:
                    direction = (direction + 3) & 3
                    dx, dy = dxdy[direction]
                if (x, y, direction, index + 1) in seen:
                    return True
                seen.add((x, y, direction, index + 1))
        return False