class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        pref, suff = [1], [1]
        for row in grid:
            for n in row:
                pref.append(pref[-1] * n % 12345)
        for row in reversed(grid):
            for n in reversed(row):
                suff.append(suff[-1] * n % 12345)
        suff = suff[::-1][1:]
        k, cols = 0, len(grid[0])
        for row in grid:
            for j in range(cols):
                row[j] = pref[k] * suff[k] % 12345
                k += 1
        return grid
