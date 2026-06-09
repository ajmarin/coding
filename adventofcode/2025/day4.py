import sys


def neighbors(r, c, rows, cols):
    for dr in range(-1, 2):
        nr = r + dr
        if nr < 0 or nr >= rows:
            continue
        for nc in range(c - 1, c + 2):
            if 0 <= nc < cols:
                yield nr, nc


def part_one(grid):
    rows, cols = len(grid), len(grid[0])
    ans = 0
    for r, row in enumerate(grid):
        for c in range(cols):
            if row[c] != "@":
                continue
            rolls = 0
            for nr, nc in neighbors(r, c, rows, cols):
                if grid[nr][nc] == "@" and (rolls := rolls + 1) > 4:
                    break
            else:
                ans += 1
    return ans


def part_two(grid):
    rows, cols = len(grid), len(grid[0])
    ans = 0
    to_remove = [(0, 0)]
    while to_remove:
        to_remove = []
        for r, row in enumerate(grid):
            for c in range(cols):
                if row[c] != "@":
                    continue
                rolls = 0
                for nr, nc in neighbors(r, c, rows, cols):
                    if grid[nr][nc] == "@" and (rolls := rolls + 1) > 4:
                        break
                else:
                    to_remove.append((r, c))
        ans += len(to_remove)
        for r, c in to_remove:
            grid[r][c] = "."
    return ans


if __name__ == "__main__":
    grid = [list(line.rstrip()) for line in sys.stdin.readlines()]
    print(f"Part one: {part_one(grid)}")
    print(f"Part two: {part_two(grid)}")
